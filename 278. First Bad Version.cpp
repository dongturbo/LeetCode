//利用二分查找
int firstBadVersion(int n) {
    long long begin = 1, end = n, mid = 1;
  	while (begin <= end){
  		mid = (begin + end) / 2;
  		if (!isBadVersion(mid)){
  			begin = mid + 1;
  		}
  		else
  			end = mid - 1;
  	}
  	return begin;
  }
