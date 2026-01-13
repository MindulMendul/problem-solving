// 위상정렬 + 백트래킹으로 푸는 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int __start, __end;
int node[10'001];
vector<pair<int, int>> edge[100'001];
vector<pair<int, int>> back[100'001];
int visited[10'001];
int indegree[10'001];

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  for(int i=1; i<=N; i++){
    node[i]=0;
    visited[i]=0;
    indegree[i]=0;
  }

  for(int i=0; i<M; i++){
    int s, e, c;
    cin>>s>>e>>c;
    edge[s].push_back({e, c});
    indegree[e]++;
    back[e].push_back({s, c});
  }
  cin>>__start>>__end;

  queue<int> q;
  q.push(__start);
  while(!q.empty()){
    int s=q.front(); q.pop();
    for(int i=0; i<edge[s].size(); i++){
      int e=edge[s][i].first, c=edge[s][i].second;
      if(node[e]<node[s]+c) node[e]=node[s]+c;
      indegree[e]--;
      if(indegree[e]==0) q.push(e);
    }
  }
  cout<<node[__end]<<"\n";
  int answer=0;

  queue<int> btq;
  btq.push(__end);
  visited[__end]=1;
  while(!btq.empty()){
    int s=btq.front(); btq.pop();
    for(int i=0; i<back[s].size(); i++){
      int e=back[s][i].first, c=back[s][i].second;
      if(node[e]+c<node[s]) continue;
      answer++;
      if(!visited[e]) {
        btq.push(e);
        visited[e]=1;
      }
    }
  }

  cout<<answer;
  return 0;
}
