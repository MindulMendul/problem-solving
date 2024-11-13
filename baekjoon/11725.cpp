#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int parent[100001];

void dfs(int num){
  visited[num]=1;
  for(int i=0; i<graph[num].size(); i++){
    if(visited[graph[num][i]]) continue;
    parent[graph[num][i]]=num;
    dfs(graph[num][i]);
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  visited[0]=visited[1]=0;
  for(int i=2; i<=N; i++){
    int a, b; cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    visited[i]=0;
  }

  dfs(1);

  for(int i=2; i<=N; i++){
    cout<<parent[i]<<"\n";
  }

  return 0;
}
