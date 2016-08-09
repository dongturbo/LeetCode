vector<int> getRow(int rowIndex) {
    int numRows=rowIndex+1;
    vector<vector<int>> result;
    for(int i=0;i<numRows;i++){
        vector<int> temp(i+1);
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)
                temp[j]=1;
            else if(j<=(i+1)/2){
                temp[j]=result[i-1][j]+result[i-1][j-1];
            }else{
                temp[j]=temp[i-j];
            }
        }
        result.push_back(temp);
    }
    return result[rowIndex];
}
