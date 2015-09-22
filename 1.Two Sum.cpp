vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();  
        assert(len >= 2);             
        vector<int> ret(2, 0);  
        map<int, int> mapping;              // default all are 0  
        vector<long long> mul(len, 0);  
        for(int i = 0; i < len; i++){  
            mul[i] = (target - nums[i]) * nums[i];  
            if(mapping[mul[i]] > 0){        // not default 0  
                if(nums[i] + nums[mapping[mul[i]] - 1] == target){  
                    ret[0] = mapping[mul[i]];  
                    ret[1] = i + 1;  
                    break;  
                }  
            } else {  
                mapping[mul[i]] = i + 1;    // larger than 0  
            }  
        }  
        return ret;  
    }  