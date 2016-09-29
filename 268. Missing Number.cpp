//对数组中按最小值到最大值为等差数列求和，然后再求数组数的和，两者相减即为缺少的数，若相等的话，判断最小值是否为0，是的话，则返回最大值+1，否则返回0
int missingNumber(vector<int>& nums) {
    int min=INT_MAX,max=INT_MIN;
    long sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<min)
            min=nums[i];
        if(nums[i]>max)
            max=nums[i];
        sum+=nums[i];
    }
    int res=(min+max)*(max-min+1)/2-sum;
    res=res==0?max+1:res;
    res=min==0?res:0;
    return res;
}
