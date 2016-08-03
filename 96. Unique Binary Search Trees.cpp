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
/*由于以上思路中递归时很多计算都是重复的，只要我们保存计算的结果，可以节省大量的时间。
只要end-begin的结果相等，那么他们的子树个数也是相等的，因此构建一个数组保存end-begin的临时结果，供以后计算使用*/
int recurNumTrees(int begin,int end,int* count){
	int result=0;	
	if(begin>=end){
		return 1;
	}else if(end-begin==1){
		return 2;
	}
	if(count[end-begin]!=0)
		return count[end-begin];
	for(int i=begin;i<=end;i++){
		result+=recurNumTrees(begin,i-1,count)*recurNumTrees(i+1,end,count);	
	}
	count[end-begin]=result;
	return result;
}

int numTrees(int n) {
	int *count=new int[n];
	memset(count,0,n*sizeof(int));
    if(n==0)
		return 0;
	else
		return recurNumTrees(0,n-1,count);
}
