
//先按pair.first元素进行排序
static bool compare(pair<int, int> a, pair<int, int> b){
  if (a.first > b.first)
    return true;
  else if (a.first < b.first)
    return false;
  else
    return a.second < b.second;
}


vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
  vector<pair<int, int>> res(people.begin(), people.end());
  sort(res.begin(),res.end(),compare);
  //排完序后，当前的下标即为前面比它大的元素个数
  for (int i = 0; i < res.size(); i++){
    //若下标数大于second的时候，说明前面比它大的元素比实际多，因此前移这个元素，直到相等
    for (int j = i; j > 0 && res[j].second < j; j--){
      swap(res[j],res[j-1]);
    }
  }
  return res;
}
