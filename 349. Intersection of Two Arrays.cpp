//利用hash_map存储第一个数组，然后再用第二个去查找，同时利用map的value++来去重。
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> map;
    vector<int> result;
    for(int i=0;i<nums1.size();i++){
        map[nums1[i]]=1;
    }
    for(int i=0;i<nums2.size();i++){
        if(map.find(nums2[i])!=map.end()){
            if(map[nums2[i]]==1)
                result.push_back(nums2[i]);
            map[nums2[i]]++;
        }
    }
    return result;
}
