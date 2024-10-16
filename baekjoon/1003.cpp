#include <iostream>

using namespace std;

#define MAX 50

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dp0[MAX]; dp0[0]=1; dp0[1]=0;
    int dp1[MAX]; dp1[0]=0; dp1[1]=1;

    for(int i=2; i<MAX; i++) {
        dp0[i]=dp0[i-1]+dp0[i-2];
        dp1[i]=dp1[i-1]+dp1[i-2];
    }

    int T, N; cin>>T;
    for (int i = 1; i <= T; i++) {
        cin>>N;
        cout<<dp0[N]<<" "<<dp1[N]<<endl;
    }

    return 0;
}
