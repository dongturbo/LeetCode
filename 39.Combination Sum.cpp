/* 利用深度优先遍历，首先排序，然后按照排的顺序开始深度优先遍历，并对遍历的节点进行累加，大于或等于target时返回。
 * result 存放结果
 * temp 存放临时储存的结果
 * beginIndex 开始遍历的索引位置
 */
void dfsSearch(vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp, int beginIndex,int tempSum,int target){
	if (candidates[beginIndex] == 0){
		beginIndex++;
	}
	for (int i = beginIndex; i < candidates.size(); i++){
		int sum = tempSum + candidates[i];
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
		dfsSearch(candidates, result, temp, i, sum, target);
		temp.pop_back();
	}	
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(),candidates.end());
	vector<vector<int>> result;
	vector<int> temp;
	dfsSearch(candidates,result,temp,0,0,target);
	return result;
}