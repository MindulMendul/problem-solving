#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[1001];
vector<int> degree(1001, 0);

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin>>N>>M;

  for(int i=0; i<M; i++){
    int t, s, e;
    cin>>t>>s;
    for(int j=1; j<t; j++){
      cin>>e;
      edge[s].push_back(e);
      degree[e]++;
      s=e;
    }
  }

  queue<int> q;
  vector<int> ans;
  for(int i=1; i<=N; i++){
    if(degree[i]==0) q.push(i);
  }

  while(!q.empty()){
    int qq=q.front(); q.pop();
    ans.push_back(qq);
    for(int e: edge[qq]){
      if(--degree[e]==0) q.push(e);
    }
  }

  if(ans.size()!=N){
    cout<<0;
    return 0;
  }
  
  for(int a:ans){
    cout<<a<<'\n';
  }

  return 0;
}
