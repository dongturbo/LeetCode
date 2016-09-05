class NumArray {
public:
    
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        for(int i=0;i<nums.size();i++){
            sums.push_back(nums[i]+sums.back());
        }
    }

    int sumRange(int i, int j) {
        if(j>sums.size())
            return sums.back();
        return sums[j+1]-sums[i];

    }
private:
    vector<int> sums;
};
