//利用两遍循环，第一遍把bull求出来，并记录下cow需要匹配的频率，第二遍求出cows
string getHint(string secret, string guess) {
    int num[10]={0};
    int bulls=0,cows=0;
    for(int i=0;i<secret.length();i++){
        if(secret[i]==guess[i]){
            bulls++;
            continue;
        }
        num[secret[i]-'0']++;
    }
    for(int i=0;i<secret.length();i++){
        if(secret[i]!=guess[i]){
            if(num[guess[i]-'0']>0){
                cows++;
                num[guess[i]-'0']--;
            }
        }
    }
    return to_string(bulls)+'A'+to_string(cows)+'B'; 
}
