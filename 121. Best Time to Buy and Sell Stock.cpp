//利用动态规划
int maxProfit(vector<int>& prices) {
  if(prices.empty())
      return 0;
  int maxProfit=0,minVal=prices[0];
  for(int i=0;i<prices.size();i++){
      maxProfit=max(prices[i]-minVal,maxProfit);
      minVal=min(prices[i],minVal);
  }
  return maxProfit;
}
