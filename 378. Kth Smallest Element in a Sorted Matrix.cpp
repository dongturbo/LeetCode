//暴力的方法，从头到尾查找，找到第k个为止，若k大于元素个数的一半的话，倒着往前查，若小于的话从前往后查
int kthSmallest(vector<vector<int>>& matrix, int k) {
   int length = matrix.size(), target=0;
  vector<int> indexs;
  if (k>length*length / 2){
    indexs = vector<int>(matrix.size(), length - 1);
    for (int i = 0; i<=length*length - k ; i++){
      int maxIndex = 0;
      while (maxIndex<length&&indexs[maxIndex]<0){
        maxIndex++;
      }
      for (int j = 1; j<length; j++){
        if (indexs[j] >= 0 && matrix[maxIndex][indexs[maxIndex]]<matrix[j][indexs[j]]){
          maxIndex = j;
        }
      }
      if (i != length*length - k){
        indexs[maxIndex]--;
      }
      target = maxIndex;
    }
  }
  else{
    indexs = vector<int>(matrix.size(), 0);
    for (int i = 0; i<k; i++){
      int minIndex = 0;
      while (minIndex<length&&indexs[minIndex] >= length){
        minIndex++;
      }
      for (int j = 1; j<length; j++){
        if (indexs[j] < length && matrix[minIndex][indexs[minIndex]]>matrix[j][indexs[j]]){
          minIndex = j;
        }
      }
      if (i != k - 1){
        indexs[minIndex]++;
      }
      target = minIndex;
    }
  }
  return matrix[target][indexs[target]];
}


  int kthSmallest(vector<vector<int>>& matrix, int k) {
     int size = matrix.size(), l = matrix[0][0], r = matrix[size-1][size-1];
      while(l < r)
      {
          int smaller = 0, m =(r+l)/2;
          for(int i = 0; i < size; ++i) 
              smaller += upper_bound(matrix[i].begin(), matrix[i].end(), m)-matrix[i].begin();
          smaller<k? l=m+1 : r=m;
      }
      return r;
  }
