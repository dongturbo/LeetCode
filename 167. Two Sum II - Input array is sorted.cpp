vector<int> twoSum(vector<int>& numbers, int target) {
     int t=target-numbers[0];
     int left=0,right=numbers.size()-1;
     vector<int> result;
     //利用二分查找出小于target的最大元素，节省遍历的时间
     while(left<=right){
         int mid=(left+right)/2;
         if(numbers[mid]>t){
             right=mid-1;
         }else{
             left=mid+1;
         }
     }
     left=0;
     //查找出等于target的元素
     while(left<right){
         if(numbers[left]+numbers[right]==target){
             result.push_back(left+1);
             result.push_back(right+1);
             break;
         }else if(numbers[left]+numbers[right]>target){
             right--;
         }else{
             left++;
         }
     }
     return result;
}
