class ProductOfNumbers {
public:
    vector<long long> nums;
    ProductOfNumbers() {
        int N;
    }
    
    void add(int num) {
        if(num == 0) {
            nums.clear();
        }
        else nums.push_back(num);
        if(nums.size() > 1) {
            if(num != 0) nums[nums.size() - 1] *= nums[nums.size() - 2];
        }
    }
    
    int getProduct(int k) {
        int div = (int)nums.size() - k - 1;
        if(div < 0) {
            if(div == -1) return nums.back();
            return 0;
        }
        return nums.back() / nums[div];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */