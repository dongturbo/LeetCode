vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    for(int i=0;i<numRows;i++){
        vector<int> temp(i+1);
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)
                temp[j]=1;
            else{
                temp[j]=result[i-1][j]+result[i-1][j-1];
            }
        }
        result.push_back(temp);
    }
    return result;
}
