#include <iostream>

using namespace std;

int C, N;
int city[20][2];
int dp[1101];

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  cin>>C>>N;
  for(int i=0; i<N; i++){
    cin>>city[i][0]>>city[i][1];
  }

  for(int i=0; i<=1100; i++){
    dp[i]=2100000000;
  }

  dp[0]=0;
  for(int i=1; i<=1100; i++){
    for(int j=0; j<N; j++){
      if(i>=city[j][1]) dp[i]=min(dp[i], dp[i-city[j][1]]+city[j][0]);
    }
  }

  int ans=2100000000;
  for(int i=C; i<=1100; i++){
    if(ans>dp[i]) ans=dp[i];
  }
  cout<<ans;
  
  return 0;
}