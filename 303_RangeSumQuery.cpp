class NumArray {
  public:
    NumArray(vector<int> &nums) {
        accumulate.push_back(0);
        for(auto n : nums)
            accumulate.push_back(accumulate.back() + n);
    }

    int sumRange(int i, int j) {
        return accumulate[j+1] - accumulate[i];    
    }
    
  private:
    vector<int> accumulate;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
