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
