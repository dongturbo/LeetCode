//利用hash表存储出现的频率
int majorityElement(vector<int>& nums) {
    unordered_map<int,int> map;
    int limit=nums.size()/2,find;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
        if(i>=limit && map[nums[i]]>limit)
        {
            find= nums[i];
            break;
        }
    }
    return find;
}
