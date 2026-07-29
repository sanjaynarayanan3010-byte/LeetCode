class MyCircularDeque {
public:
    vector<int> nums;

    int size;

    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if(nums.size() >= size) return 0;
        nums.insert(nums.begin(), value);
        return 1;
    }
    
    bool insertLast(int value) {
        if(nums.size() >= size) return 0;
        nums.push_back(value);
        return 1;
    }
    
    bool deleteFront() {
        if(nums.size() == 0) return 0;
        nums.erase(nums.begin());
        return 1;
    }
    
    bool deleteLast() {
        if(nums.size() == 0) return 0;
        nums.pop_back();
        return 1;
    }
    
    int getFront() {
        if(nums.size() == 0) return -1;
        return nums[0];
    }
    
    int getRear() {
        if(nums.size() == 0) return -1;
        return nums[nums.size() - 1];
    }
    
    bool isEmpty() {
        return nums.size() == 0;
    }
    
    bool isFull() {
        return nums.size() >= size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */