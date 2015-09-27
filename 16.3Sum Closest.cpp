int range = 2147483647,temp=0,result=0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++){
		int k = i + 1, j = nums.size() - 1;
		while (k<j){			
			temp = nums[i] + nums[k] + nums[j];
			if (temp - target < 0){
				if (target - temp < range){
					range = target - temp;
					result = temp;
				}
				k++;
			}
			else if (temp - target > 0){
				if (temp - target < range){
					range = temp - target;
					result = temp;
				}
				j--;
			}
			else{
				return target;
			}
		}
	}

	return result;