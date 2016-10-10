int numberOfArithmeticSlices(vector<int>& A) {
      if(A.size()==0)
          return 0;
    int res = 0,count=0,diff=0;
    vector<int> counts(A.size(),0);
    for (int i = 0; i < A.size() - 1; i++){
      if (i == 0){
        diff = A[i + 1] - A[i];
        count = 1;
      }
      else{
        //差值相同的话count累加
        if (A[i + 1] - A[i] == diff){
          count++;
          if (count >= 2 && counts[count]==0){
            if (count == 2){
              counts[count] = 1;
            }
            else{
               //递推公式，当三个为Arithmetic slices时，若后面的依然是的话，则有下列递推式，即counts[i+1]=counts[i]+i; counts[i]表示当连续i个差值相等的话，slice的个数
              counts[count] = counts[count - 1] + count - 1;
            }
          }
        }
        else{
          diff = A[i + 1] - A[i];
          res += counts[count];
          count = 1;
        }
      }
    }
    res += counts[count];
    return res;
  }
