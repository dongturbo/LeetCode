//类似与之前的Combination Sum的DFS，有一点需要注意，如何避免重复。如果两个数相同，我们先用前一个数，只有当前一个数用了，这个数才能使用。
void dfsSearch(vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp, int beginIndex,int tempSum,int target,int last){
	if (beginIndex >= candidates.size()){
		return;
	}
	for (int i = beginIndex; i < candidates.size(); i++){
		int sum = tempSum + candidates[i];
		if (i > 0 && candidates[i] == candidates[i - 1] && last != i - 1){
			continue;
		}
		if (sum == target){
			temp.push_back(candidates[i]);
			result.push_back(temp);
			temp.pop_back();
			return;
		}
		else if (sum > target){
			return;
		}
		temp.push_back(candidates[i]);
		dfsSearch(candidates, result, temp, i+1, sum, target,i);
		temp.pop_back();
	}	
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(),candidates.end());
	vector<vector<int>> result;
	vector<int> temp;
	int last = -1;
	for (int i = 0; i < candidates.size(); i++){
		int sum = candidates[i];
		if (i > 0 && candidates[i] == candidates[i - 1] && last != i - 1){
			continue;
		}
		if (sum == target){
			temp.push_back(candidates[i]);
			result.push_back(temp);
			temp.pop_back();
			break;
		}
		else if (sum > target){
			break;
		}
		temp.push_back(candidates[i]);
		dfsSearch(candidates, result, temp, i+1, sum, target,i);
		temp.pop_back();
	}
	return result;
}