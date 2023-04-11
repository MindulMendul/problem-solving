#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

static int dp[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    string a, b;

    cin>>a>>b;

    int answer = 0;

    //init
    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            dp[i][j]=0;
        }
    }

    //calculate
    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            if(a.at(i-1)==b.at(j-1)){dp[i][j]=dp[i-1][j-1]+1;}
            else {dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
            if(dp[i][j]>answer){answer=dp[i][j];}
        }
    }
  
    //print result
    cout << answer;
    return 0;
}
