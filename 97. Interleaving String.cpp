/*第一种方法利用递归暴力破解，不过时间超时了*/
bool isInterleave(string s1, string s2, string s3) {
	int len1=s1.length(),len2=s2.length(),len3=s3.length();
    if(len1+len2!=len3)
        return false;
    if(s1!="" && s1[0]==s3[0]){
        if(len3==1)
            return true;
        else
            if(isInterleave(s1.substr(1),s2,s3.substr(1)))
                return true;
    }
    if(s2!="" && s2[0]==s3[0]){
        if(len3==1)
            return true;
        else
            if( isInterleave(s1,s2.substr(1),s3.substr(1)))
                return true;
    }
    return false;

}

/*
设状态match[i][j] 为s1[0,i] ঻ s2[0,j]匹配s3[0, i+j]结果，如果s1 的最后一个字符等于
s3最后一个字符，则݈ f[i][j]=f[i-1][j];如果s2的最后一个字符等于s3的最后一个字符,则
f[i][j]=f[i][j-1]。因此状态转移方程为：
f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j])
|| (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);

*/

//利用二维动态规划+滚动数组
bool isInterleave(string s1, string s2, string s3) {
	int len1=s1.length(),len2=s2.length(),len3=s3.length();
    if(len1+len2!=len3)
        return false;
    vector<bool> match(len1+1,true);
    for(int i=1;i<=len1;i++) 
        match[i]=s1[i-1]==s3[i-1]&&match[i-1];
    for(int i=1;i<=len2;i++){
        match[0]=match[0]&&s2[i-1]==s3[i-1];
        for(int j=1;j<=len1;j++){
            match[j]=s2[i-1]==s3[i-1+j]&&match[j]||s1[j-1]==s3[i-1+j]&&match[j-1];
        }
    }
    return match[len1];

}

