int maxProfit(vector<int>& prices) {
    if(prices.empty())
        return 0;
    int maxProfit=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]-prices[i-1]>0){
           maxProfit+= prices[i]-prices[i-1];
        }
    }
    return maxProfit;
}
