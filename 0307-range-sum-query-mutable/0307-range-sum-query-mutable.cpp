class NumArray {
public:
    vector<int> seg;
    int N;
    NumArray(vector<int>& nums) {
        N = nums.size();
        int newN = 1;
        while(newN < N) newN = newN << 1;
        seg.resize(2 * newN, 0);
        for(int i=newN;i<N+newN;i++){
            seg[i] = nums[i-newN];
        }
        N = newN;
        for(int i=N-1;i>=1;i--) {
            seg[i] = seg[i+i] + seg[i+i+1];
        }
        for(int i : seg) cout<<i<<" ";
    }

    void upd(int node, int nl , int nr, int index, int u){
        if(index > nr || index < nl) return;

        if(nl == nr) {
            seg[node] = u;
            return;
        }

        int mid = (nr + nl) / 2;
        if(index <= mid) {
            upd(node*2, nl, mid, index, u);
        }
        else upd(node*2 + 1, mid+1, nr, index,u);
        seg[node] = seg[node*2] + seg[node*2 + 1];
    }
    
    void update(int index, int val) {
        upd(1, 1, N, index+1, val);
    }

    int find(int node, int nl, int nr, int ql ,int qr){
        if(ql > nr || nl > qr) return 0;

        if(nr <= qr && ql <= nl) return seg[node];

        int mid = (nr + nl) / 2;
        int lft = find(node*2, nl, mid, ql, qr);
        int rft = find(node*2 + 1, mid+1, nr, ql ,qr);
        return lft + rft; 
    }
    
    int sumRange(int lt, int rt) {
        return find(1, 1, N, lt+1, rt+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */