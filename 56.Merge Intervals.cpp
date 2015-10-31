/*解题思路：
	1.按照interval的start升序排序。
	2.比较第i个interval的end和第i+1个interval的start。
	3.如果end>start则合并两个interval，然后重新执行第二步，否则停止合并，把interval添加到result中。
	4.直到合并到最后一个interval为止。
*/
static bool compare(const Interval& item1, const Interval& item2)
{
	return item1.start < item2.start;
}
vector<Interval> merge(vector<Interval>& intervals) {
	int length = intervals.size();
	vector<Interval> result;
	if (length == 0)
		return result;
	sort(intervals.begin(), intervals.end(), compare);
	Interval curIn = intervals[0];
	for (int i = 0; i < length; i++){
		if (curIn.end < intervals[i].start){
			result.push_back(curIn);
			curIn = intervals[i];
		}
		else{
			curIn.end = max(curIn.end, intervals[i].end);
		}

	}
	result.push_back(curIn);
	return result;
}