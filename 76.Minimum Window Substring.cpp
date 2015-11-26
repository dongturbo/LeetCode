/*算法核心思想如下：
	在保证[begin,end]窗口包含T中所有字符的条件下，延伸end，收缩begin。
	进行一次扫描后，记录符合条件的最小窗口(end-begin+1)表示的字符串。
	有个问题：怎样才知道[begin,end]窗口包含了T中所有字符？
	我使用count记录剩余“有效”字符数，当count达到0时，即可说明[begin,end]包含了T。
	注意：“有效”的意思是指，当前延伸得到的S[end]字符，使得[begin,end]更进一步包含T，而不是重复劳动。
	比如说，T="a", [begin,end]已经包含"a",再延伸得到"aa"，只是无效操作，并没有使得[begin,end]更接近T,有效字符数仍为1.
*/
string minWindow(string S, string T) {
	int begin = 0;
	int end = 0;
	int minbegin = 0;
	int minend = 0;
	int minSize = INT_MAX;
	vector<int> needFind(128, 0);
	vector<int> Found(128, 0);
	for (int i = 0; i < T.size(); i++)
		needFind[T[i]] ++;
	Found[S[0]] ++;
	int count = T.size();
	if (needFind[S[0]] >= Found[S[0]])
		count--;
	while (true)
	{
		if (count == 0)
		{//shrink begin
			while (Found[S[begin]] > needFind[S[begin]])
			{
				Found[S[begin]] --;
				begin++;
			}
			int size = end - begin + 1;
			if (size < minSize)
			{
				minbegin = begin;
				minend = end;
				minSize = size;
			}
		}
		if (end < S.size())
		{
			end++;
			Found[S[end]] ++;
			if (needFind[S[end]] >= Found[S[end]])
				count--;
		}
		else
			break;
	}
	if (minSize != INT_MAX)
		return S.substr(minbegin, minSize);
	else
		return "";
}