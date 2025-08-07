#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K; cin>>N>>K;
  long long int coin[N];
  long long int dp[K+1];
  for(int i=0; i<N; i++) cin>>coin[i];
  for(int k=0; k<=K; k++) dp[k]=21'0000'0000;
  for(int i=0; i<N; i++) if(coin[i]<=K) dp[coin[i]]=1;

  //dp[K]=min(dp[K], dp[K-coin[i]]+dp[coin[i]])
  for(int k=1; k<=K; k++){
    for(int i=0; i<N; i++){
      if(k-coin[i]<0) continue;
      dp[k]=min(dp[k], dp[k-coin[i]]+dp[coin[i]]);
    }
  }

  if(dp[K]==21'0000'0000) cout<<-1;
  else cout<<dp[K];
  
  return 0;
}
