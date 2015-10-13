/*问题描述：count-and-say序列是如上所示的序列，比如，1，可以读作1个1， 所以下一个数就是11，
	11可以读作2个1，所以，下一个就是21。给定一个整数n，生成序列的第n个整数序列，该整数序列表示为字符串。
	
	该题可以采用计数的方式，依次遍历，比如1211，1个1，就将整数1转换为字符，然后将11添加到结果字符串中，
	1个2，就将1转换为字符，然后将12添加到结果字符串中，2个1，将2转换为字符，然后将21添加到结果字符串中。
*/

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
		for (int i = 1; i < n; i++){
			string  temp = result;
			int count = 1, length = result.length();
			char tempCh = result[0];
			result = "";
			for (int j = 1; j < length; j++){
				if (tempCh == temp[j]){
					count++;
				}
				else{
					result += count + '0';
					result += tempCh;
					tempCh = temp[j];
					count = 1;
				}			
			}
			result += count + '0';
			result += tempCh;
		}
		return result;
    }
};