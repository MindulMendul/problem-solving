#include <iostream>

#define MAX 1001

using namespace std;

static int dp[MAX];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0]=dp[1]=1;

    int N; cin>>N;
    for (int i = 2; i <= N; i++) {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=10007;
    }

    cout<<dp[N]%10007;
    return 0;
}
