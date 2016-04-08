//最简单的方法是复制到nums1里面后，调用sort方法，不过应该考察的不是这个
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	for (int i = 0; i<n; i++){
		nums1[m + i] = nums2[i];
	}
	sort(nums1.begin(), nums1.end());
}
/*既然nums1的空间足够大，那么可以倒着往nums1里面放，i,j,k三个标志位分为指向nums1中的第m,nums2的第n个，nums1中的第m+n个。
    nums1[i]和nums2[j]作比较，大的放到nums1[k]位上，直到两个数组都遍历完
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1,k=m+n-1;
	while (i >= 0 && j >= 0){
		if (nums1[i] > nums2[j]){
			nums1[k--] = nums1[i--];
		}
		else{
			nums1[k--] = nums2[j--];
		}
	}
	if (j >= 0){
		for (int i = 0; i <= j; i++)
			nums1[i] = nums2[i];
	}
}