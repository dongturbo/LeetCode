//记录两个下标，一个表示当前要改变的值，另一个表示当前非零的值
void moveZeroes(vector<int>& nums) {
    int cur=0,next=0;
    while(next<nums.size()){
        if(nums[next]!=0){
            nums[cur]=nums[next];
            cur++;
            next++;
        }
        else{
            next++;
        }
    }
    while(cur<nums.size())
        nums[cur++]=0;
}
