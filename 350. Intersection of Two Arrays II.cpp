//根上一道题类似，只不过这次得记录出现的频次，并在迭代nums2的时候，进行减1，当频次大于0时，记录到结果中
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> map;
    vector<int> result;
    for(int i=0;i<nums1.size();i++){
        map[nums1[i]]++;
    }
    for(int i=0;i<nums2.size();i++){
        if(map.find(nums2[i])!=map.end()){
            if(map[nums2[i]]>=1)
                result.push_back(nums2[i]);
            map[nums2[i]]--;
        }
    }
    return result;
}
