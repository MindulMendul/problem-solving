#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[32001];
vector<int> deg(32001,0);

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin>>N>>M;
  
  for(int i=0; i<M; i++){
    int s,e; cin>>s>>e;
    edge[s].push_back(e);
    deg[e]++;
  }

  queue<int> q;
  for(int i=1; i<=N; i++){
    if(deg[i]) continue;
    q.push(i);
  }

  while(!q.empty()){
    int t=q.front(); q.pop();
    cout<<t<<" ";
    for(int dest:edge[t]){
      if(--deg[dest]==0) q.push(dest);
    }
  }

  return 0;
}