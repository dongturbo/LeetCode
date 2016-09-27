//利用hash表和桶排序
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int num : nums)
        ++m[num];

    vector<vector<int>> buckets(nums.size() + 1); 
    //把出现的频率作为索引，元素作为数组中的元素
    for (auto p : m)
        buckets[p.second].push_back(p.first);

    vector<int> ans;
    //从高向低迭代，迭代够k个停止
    for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
        for (int num : buckets[i]) {
            ans.push_back(num);
            if (ans.size() == k)
                break;
        }
    }
    return ans;
}
