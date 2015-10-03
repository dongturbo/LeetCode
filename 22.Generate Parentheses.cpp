#include "stdafx.h"
#include<string>
#include <cstdlib>
#include<iostream>
#include<vector>
#include<math.h>
#include<hash_map>
#include<stack>
#include<map>
#include <algorithm>
using namespace::std;

void dfs(string s,int p1,int p2,vector<string> &result){
	if (p1 > 0){
		if (p1 == p2){
			string temp = s + '(';
			dfs(temp, p1 - 1, p2,  result);
		}
		else if (p1 < p2){
			string temp = s + '(';
			dfs(temp, p1 - 1, p2,  result);
			string temp1 = s + ')';
			dfs(temp1, p1, p2 - 1,  result);
		}
	}
	else{
		for (int i = 0; i < p2; i++){
			s += ')';
		}
		result.push_back(s);
		return;
	}
	
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	dfs("(", n - 1, n, result);
	return result;
}




int main(int argc, char *argv[]){

	vector<string> result = generateParenthesis(5);
	for (int i = 0; i < result.size();i++){
		cout << result[i]<< endl;
	}
	
	return 0;
}
