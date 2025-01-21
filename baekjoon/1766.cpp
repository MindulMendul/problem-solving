#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin>>N>>M;

  vector<int> edge[N+1];
  vector<int> deg(N+1, 0);

  for(int i=0; i<M; i++){
    int s, e; cin>>s>>e;
    edge[s].push_back(e);
    deg[e]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  for(int i=1; i<=N; i++){
    if(deg[i]==0) q.push(i);
  }

  while(!q.empty()){
    int t=q.top(); q.pop();
    cout<<t<<" ";
    for(int e:edge[t]){
      deg[e]--;
      if(deg[e]==0) q.push(e);
    }
  }

  return 0;
}