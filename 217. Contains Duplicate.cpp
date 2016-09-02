bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for(int i=0;i<nums.size();i++){
        if(set.find(nums[i])==set.end()){
            set.insert(nums[i]);
        }else{
            return true;
        }
    }
    return false;
}
