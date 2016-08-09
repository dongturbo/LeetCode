/*
  1.先查找t中第一个字符即第i个，在s中的子序列的个数，并记录t[0]在s中的位置信息，并把位置以及匹配个数存到map
  2.再查找第i+1个字符，根据前面map的信息中匹配的位置往后查，查询前i+1个字符组成序列的个数
  3.直到匹配完，把最后匹配的map中的个数累加，即为最终子序列的个数

*/
int numDistinct(string s, string t) {
  int slen=s.length(),tlen=t.length();
  vector< map<int,int> > index(tlen,map<int,int>());
  for(int i=0;i<slen;i++){
      if(t[0]==s[i])
          index[0][i]=1;
  }
  for(int i=1;i<tlen;i++){
      map<int,int>::iterator it;
      for(it=index[i-1].begin();it!=index[i-1].end();it++){
          for(int k=it->first+1;k<slen;k++){
              if(s[k]==t[i]){
                  index[i][k]+=it->second;
              }
          }
      }
  }    
  int result=0;
  for(map<int,int>::iterator it=index[tlen-1].begin();it!=index[tlen-1].end();it++){
      result+=it->second;
  }
  return result;

}
