/*若元素中有两个零时，则全部元素为0
  若只有一个为零时，则记录零的下标，并把除它外的元素做乘法
*/
vector<int> productExceptSelf(vector<int>& nums) {
    //保存所有非零元素的乘积
    long long product=1;
    int countZero=0,zeroIndex;
    vector<int> products(nums.size(),0);
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            countZero++;
            zeroIndex=i;
            if(countZero==2)
                break;
        }else
            product*=nums[i];
    }
    if(countZero==0){
        //如果没有为0的元素，那每次让乘积除以该元素就行
        for(int i=0;i<nums.size();i++){
            products[i]=product/nums[i];
        }
    }else if(countZero==1){
        //若有一个0的元素，则除它外的元素都为0，只把它置为乘积就行
        products[zeroIndex]=product;
    }
    return products;
}
