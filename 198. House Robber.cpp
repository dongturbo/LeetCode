/*利用动态规划，money和lastmoney保存前两步的结果，那么第i步=max{money，lastmoney+nums[i]}
*/
int rob(vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    int money=0,lastMoney=0;
    for(int i=0;i<nums.size();i++){
        int t=money;
        if(nums[i]+lastMoney>money){
            money=nums[i]+lastMoney;
            lastMoney=t;
        }else{
            lastMoney=money;
        }
    }
    return money;
}
