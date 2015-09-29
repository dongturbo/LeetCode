
void fourSumHelper(vector<int> &num, int index, vector<int> &path, int cursum, int target, vector<vector<int>> &res)
    {
    	if(path.size() >=4)
		{
			if(path.size() == 4 && cursum == target)
			{
				res.push_back(path);
				return;
			}else
				return;
		}
		for(int i = index; i < num.size(); i++)
    	{
			path.push_back(num[i]);
			cursum += num[i];
			fourSumHelper(num,i+1,path,cursum,target,res);
			path.pop_back();
			cursum -= num[i];
			while(i < num.size()-1 && num[i] == num[i+1])i++;
		}
	}
	vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res;
		if(num.size()<4)return res;
		sort(num.begin(), num.end());
		vector<int> path;
		fourSumHelper(num,0,path,0,target,res);
		return res;
    }