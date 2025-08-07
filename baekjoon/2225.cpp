#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K; cin>>N>>K;
  long long int dp[201][201];

  // dp[n][k] = dp[n-1][k-1] + dp[n-2][k-1]
  for(int i=0; i<201; i++) for(int j=1; j<201; j++) dp[i][j]=0;
  for(int i=0; i<201; i++) dp[i][1]=1;

  for(int k=1; k<=K; k++){
    for(int i=0; i<=N; i++){
      for(int j=0; j<=i; j++){
        dp[i][k]+=dp[i-j][k-1];
        dp[i][k]%=1'000'000'000;
      }
    }
  }
  cout<<dp[N][K];
  
  return 0;
}
