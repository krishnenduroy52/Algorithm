#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }
    
    int start = 0;
    int maxLen = 1;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            start = i;
            maxLen = 2;
        }
    }
    
    for(int k =3; k <= n; k++){
        for(int i = 0; i < n - k + 1; i++){
            int j = i + k -1; 
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = 1;
                if(k > maxLen){
                    start = i;
                    maxLen = k;
                }
            }
        }
    }
    string news = "";
    for(int c = start; c < start + maxLen; c++){
        news += s[c];
    }
    return news;
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
}