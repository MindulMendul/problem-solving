#include <iostream>

#define MAX 1000001

using namespace std;

static int dp[MAX];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<MAX; i++) dp[i]=0;

    int N; cin>>N;
    for (int i = 1; i <= N; i++) {
        dp[i]=dp[i-1]+1;
        if(i%2==0 && dp[i]>dp[i/2]+1) dp[i]=dp[i/2]+1;
        if(i%3==0 && dp[i]>dp[i/3]+1) dp[i]=dp[i/3]+1;
    }

    cout<<dp[N]-1;
    return 0;
}
