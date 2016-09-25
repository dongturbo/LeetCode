//利用前面计算的结果
vector<int> countBits(int num) {
     vector<int> count(num+1);
     count[1]=1;
     int n=1;
     for(int i=2;i<=num;i++){
         while(i>=n){
             n*=2;
         }
         n/=2;
         count[i]=1+count[i-n];
     }
     return count;
}
