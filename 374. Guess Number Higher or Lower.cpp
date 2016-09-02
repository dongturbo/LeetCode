//利用二分查找，根据guess的返回值判断是在上半部分还是下半部分
int guessNumber(int n) {
    long begin=1,end=n,mid=(begin+end)/2;
    int check=guess(mid);
    while(check!=0 && begin<=end){
        if(check>0){
            begin=mid+1;
        }else{
            
            end=mid-1;
        }
        mid=(begin+end)/2;
        check=guess(mid);
    }
    return mid;
}
