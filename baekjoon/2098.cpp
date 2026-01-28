#include <iostream>

using namespace std;

#define INF 1000000000

int N;
int w[16][16];
int dp[65536][16];

int dfs(int mask, int curr){
  if(mask==(1<<N)-1){
    if(w[curr][0]==0) return INF;
    else return w[curr][0];
  }

  if(dp[mask][curr]!=-1) return dp[mask][curr];
  dp[mask][curr]=INF;

  for(int next=0; next<N; next++){
    if(w[curr][next]==0) continue; // 갈 수 없으면 스킵
    if((mask & (1<<next)) > 0) continue; // 이미 방문했다면 스킵

    int next_dfs=dfs(mask|(1<<next), next)+w[curr][next];
    dp[mask][curr]=min(dp[mask][curr], next_dfs);
  }
  return dp[mask][curr];
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  for(int i=0; i<(1<<N); i++) for(int j=0; j<N; j++) dp[i][j]=-1;
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>w[i][j];

  cout<<dfs(1,0);

  return 0;
}
