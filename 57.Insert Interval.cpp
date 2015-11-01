/*解题思路：
	1.循环intervals中的元素。
	2.遇到与newInterval用重叠的元素时进行合并，
	3.合并完后以后元素依次添加到result中
*/
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	int length = intervals.size();
	vector<Interval> result;
	bool isMerge = false;
	for (int i = 0; i < length; i++){
		if (!isMerge){
			if (newInterval.start<= intervals[i].start && newInterval.end>= intervals[i].start){
				newInterval.end = max(newInterval.end, intervals[i].end);
				if (i + 1 == length){
					result.push_back(newInterval);
					break;
				}
				continue;
			}
			else if (newInterval.start>= intervals[i].start &&newInterval.start <= intervals[i].end){
				newInterval.start = intervals[i].start;
				newInterval.end = max(newInterval.end, intervals[i].end);
				if (i + 1 == length){
					result.push_back(newInterval);
					break;
				}
				continue;
			}
			else if (intervals[i].start>newInterval.end){
				result.push_back(newInterval);
				isMerge = true;
			}
		}
		
		result.push_back(intervals[i]);
	}
	return result;
}
//这种方法是把newInterval添加到intervals中，然后按照上一道题的合并方法合并
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	int length = intervals.size();
	vector<Interval> result;
	if (length == 0)
	{
		result.push_back(newInterval);
		return result;
	}	
	vector<Interval>::iterator it;
	for (it = intervals.begin(); it != intervals.end();it++){
		if ((*it).start>newInterval.start){
			intervals.insert(it,newInterval);
			break;
		}
	}
	if (intervals.size() == length){
		intervals.push_back(newInterval);
	}
	length++;
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