#include "stdafx.h"
#include<string>
#include <cstdlib>
#include<iostream>
#include<vector>
#include<math.h>
#include<hash_map>
#include<map>
#include <algorithm>
using namespace::std;


vector<vector<int> > threeSum(vector<int> num, int target);

/*
* 1) Sort the array,
* 2) traverse the array, and solve the problem by using "3Sum" soultion.
*/

vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector< vector<int> > result;
	if (num.size()<4) return result;
	sort(num.begin(), num.end());

	for (int i = 0; i<num.size() - 3; i++) {
		//skip the duplication
		if (i>0 && num[i - 1] == num[i]) continue;
		vector<int> n(num.begin() + i + 1, num.end());
		vector<vector<int> > ret = threeSum(n, target - num[i]);
		for (int j = 0; j<ret.size(); j++){
			ret[j].insert(ret[j].begin(), num[i]);
			result.push_back(ret[j]);
		}
	}

	return result;
}

vector<vector<int> > threeSum(vector<int> num, int target) {

	vector< vector<int> > result;
	//sort the array (if the qrray is sorted already, it won't waste any time)
	sort(num.begin(), num.end());

	int n = num.size();

	for (int i = 0; i<n - 2; i++) {
		//skip the duplication
		if (i>0 && num[i - 1] == num[i]) continue;
		int a = num[i];
		int low = i + 1;
		int high = n - 1;
		while (low < high) {
			int b = num[low];
			int c = num[high];
			if (a + b + c == target) {
				//got the soultion
				vector<int> v;
				v.push_back(a);
				v.push_back(b);
				v.push_back(c);
				result.push_back(v);
				// Continue search for all triplet combinations summing to zero.
				//skip the duplication
				while (low<n && num[low] == num[low + 1]) low++;
				while (high>0 && num[high] == num[high - 1]) high--;
				low++;
				high--;
			}
			else if (a + b + c > target) {
				//skip the duplication
				while (high>0 && num[high] == num[high - 1]) high--;
				high--;
			}
			else{
				//skip the duplication
				while (low<n && num[low] == num[low + 1]) low++;
				low++;
			}
		}
	}
	return result;
}

int main(int argc, char *argv[]){

	vector<int> nums = { 1 ,0, - 1, 0, - 2, 2 ,5,-2,-3};
	vector<vector<int>> result = fourSum(nums,0);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < 4; j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}
