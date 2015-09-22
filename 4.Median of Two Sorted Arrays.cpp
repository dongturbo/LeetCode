class Solution {
public:
double findKth(vector<int>& nums1, vector<int>& nums2, int start1, int start2,int len1,int len2, int k){
	if (len1 > len2){
		return findKth(nums2, nums1, start2, start1, len2, len1, k);
	}
	if (len1 == 0){
		return nums2[start2+k-1];
	}
	if (k == 1){
		return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
	}
	int p = k / 2 < len1 ? k / 2 : len1;
	int q = k - p;
	if (nums1[start1 + p - 1] < nums2[start2 + q - 1]){
		return findKth(nums1,nums2,start1+p,start2,len1-p,len2,k-p);
	}
	else if (nums1[start1 + p - 1] > nums2[start2 + q - 1]){
		return findKth(nums1,nums2,start1,start2+q,len1,len2-q,k-q);
	}
	else{
		return nums1[start1 + p - 1];
	}
}
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size()) / 2;
	if ((nums1.size() + nums2.size()) % 2 == 0){
		return (findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), k) + findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), k+1)) / 2;
	}
	else{
		return findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), k+1);
	}
    }
};