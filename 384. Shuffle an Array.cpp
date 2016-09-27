class Solution {
public:
    vector<int> nums;
    Solution(vector<int> nums) {
        this->nums=vector<int>(nums.begin(),nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffleNums(nums.begin(),nums.end());
        for(int i=0,j;i<nums.size();i++){
            j = rand() % (i + 1);
            swap(shuffleNums[i], shuffleNums[j]);
        }
        
        return shuffleNums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
