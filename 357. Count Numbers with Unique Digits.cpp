/*通过数学中的全排列来计算,设f(n)表示所求结果，
  可知
  f(0)=1;
  f(1)=9+f(0),
  f(2)=9*9+f(1);
  f(3)=9*9*8+f(2);
  依次类推：
  f(n)=9*9*8*……*(10-n+1)+f(n-1); 同时（10-n+1）需大于0
*/
int countNumbersWithUniqueDigits(int n) {
    int res=1,mul;
    vector<int> temp(1,1);
    for(int i=0;i<n;i++){
        res=1;
        for(int j=0;j<=i;j++){
            if(j==0)
                mul=9;
            else
                mul=10-j;
            res*=mul;
        }
        res+=temp.back();
        temp.push_back(res);
    }
    return res;
}
