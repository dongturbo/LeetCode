bool canPartition(vector<int>& nums) {
  int sum = 0;
  for (int i = 0; i < nums.size(); i++){
    sum += nums[i];
  }
  //如果所有数据的和为奇数的话，直接返回否
  if (sum % 2 != 0)
    return false;
  sum /= 2;
  //保存累计的和的结果
  vector<int> maps(sum+1,0);
  for (int i = 0; i < nums.size(); i++){

    for (int j = 0; j < sum; j++){
      if (maps[j] > 0 && j + nums[i] <= sum){
        maps[j + nums[i]] += 1;
      }
      else if(nums[i]<=sum){
        maps[nums[i]] = 1;
      }
      //只要最后一个结果大于0，表示已经累计出这个结果
      if (maps.back() > 0)
        return true;
    }
  }
  return false;
}
