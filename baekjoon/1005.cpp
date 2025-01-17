#include <iostream>
#include <vector>

using namespace std;

int edge[1001][1001];
int delay[1001];
int dp[1001];
int visited[1001];

int dfs(int ind){
  visited[ind]=1;
  for(int i=1; i<=edge[ind][0]; i++){
    if(visited[edge[ind][i]]==0) dfs(edge[ind][i]);
    dp[ind]=max(dp[ind], dp[edge[ind][i]]);
  }
  return dp[ind]+=delay[ind];
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, tc;
  cin>>T;
  
  for(tc=1; tc<=T; tc++){
    int N, K, W;
    cin>>N>>K;
    
    for(int i=1; i<=N; i++) {
      cin>>delay[i];
      dp[i]=-1;
      edge[i][0]=0;
      visited[i]=0;
    }

    for(int i=0; i<K; i++){
      int x, y; cin>>x>>y;
      edge[y][++edge[y][0]]=x;
    }
    cin>>W;
    cout<<dfs(W)+1<<'\n';
  }

  return 0;
}
