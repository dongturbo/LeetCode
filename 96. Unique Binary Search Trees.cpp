/*和上一题思路一致，使用递归，不过超时了*/
int recurNumTrees(int begin,int end){
	int result=0;
	if(begin>=end){
		return 1;
	}else if(end-begin==1){
		return 2;
	}
	for(int i=begin;i<=end;i++){
		result+=recurNumTrees(begin,i-1)*recurNumTrees(i+1,end);	
	}
	return result;
}

int numTrees(int n) {
    if(n==0)
		return 0;
	else
		return recurNumTrees(0,n-1);
}
