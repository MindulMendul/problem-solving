#include <iostream>
#include <vector>

using namespace std;

long long int arr[1025][1025];
long long int dp[1025][1025];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            long long int a; cin>>a;
            arr[i][j]=a;
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
        }
    }

    for(int tc=1; tc<=M; tc++){
        int x1,y1, x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]<<'\n';
    }

    return 0;
}
