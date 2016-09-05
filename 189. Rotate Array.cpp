/*[1,2,3,4,5,6,7] 被旋转成[5,6,7,1,2,3,4]，我将1放到4的位置，4放到7的位置，7放到3的位置，3放到6的位置，6放到2的位置，
2放到5的位置，最后5放到1的位置，每次我只要计算出这个被替换掉的元素下一次应该到的位置就行了！看似很完美，额外空间复杂度O(1)。 
　　实现了一下发现一个问题，只有k%n和n互质的时候，这个方法才有效！ 
　　比如数组为[1,2,3,4]，k=2。第一次1换到3，然后3换到1，到了初始位置了，结束，但是数组为[3,2,1,4]。当n和k%n有公因子的时候，
　　就会出现这种问题。这个问题可以这样解决，找到n和k%n的最大公因子c，然后对数组的前c个数进行上述的迭代替换操作。
　　这种方法的时间复杂度是O(n)。 
*/
void rotate(vector<int>& nums, int k) 
{
    if(nums.size() == 0) return;
    k = k%nums.size();
    if(k < 1) return;
    int gcd = divisor(nums.size(),k);
    for(int i = 0; i < gcd; i++)
    {
        int temp = nums[i];
        int tempIndex = i;
        while((tempIndex + k)%nums.size() != i)
        {
            int theTemp = nums[(tempIndex + k)%nums.size()];
            nums[(tempIndex + k)%nums.size()] = temp;
            temp = theTemp;
            tempIndex = (tempIndex + k)%nums.size();
        }
        nums[i] = temp;
    }
}


int divisor(int m,int n)
{
     int temp;
     while(m%n!=0){
         temp=n;
         n=m%n;
         m=temp;
     }
     return n;
 }
