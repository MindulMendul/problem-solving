#include <iostream>

using namespace std;

#define INF 2e18

typedef long long int lli;
typedef pair<lli, lli> pll;
int N;

pll matrix[501];
lli dp[501][501];

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;

  if(N==1){
    cout<<0;
    return 0;
  }
  
  for(int i=0; i<N; i++) {
    cin>>matrix[i].first>>matrix[i].second;
    dp[i][i]=0;
  }
  
  for(int dis=1; dis<N; dis++){
    for(int s=0; s+dis<N; s++){
      dp[s][s+dis]=INF;
      for(int k=s; k<s+dis; k++){
        lli union_const=matrix[s].first*matrix[k].second*matrix[s+dis].second;
        dp[s][s+dis]=min(dp[s][k]+dp[k+1][s+dis]+union_const, dp[s][s+dis]);
      }
      cout<<dp[s][s+dis]<<" ";
    }cout<<'\n';
  }

  cout<<dp[0][N-1];

  return 0;
}
 