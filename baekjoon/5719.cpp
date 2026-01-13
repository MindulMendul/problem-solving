#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1'000'000'000

int N, M, S, E;
vector<pair<int, int>> edge[500];
vector<pair<int, int>> back[500];
int visited[500];
int dist[500];

void dijsktra(int ss){
  priority_queue<pair<int, int>> q;
  q.push({0, ss});
  while(!q.empty()){
    int c=-q.top().first, s=q.top().second;
    q.pop();
    if(dist[s]<c) continue;
    for(int i=0; i<edge[s].size(); i++){
      int e=edge[s][i].first, next_dist=c+edge[s][i].second;
      if(dist[e]>next_dist) {
        dist[e]=next_dist;
        q.push({-next_dist, e});
      }
    }
  }
  return;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(true){
    cin>>N>>M;
    if(N==0 && M==0) return 0;
    cin>>S>>E;

    for(int i=0; i<N; i++){
      visited[i]=0;
      dist[i]=MAX;
      edge[i].clear();
      back[i].clear();
    }
    dist[S]=0;

    for(int i=0; i<M; i++){
      int s, e, c;
      cin>>s>>e>>c;
      edge[s].push_back({e, c});
      back[e].push_back({s, c});
    }
    
    dijsktra(S);

    queue<int> btq;
    btq.push(E);
    visited[E]=1;
    while(!btq.empty()){
      int s=btq.front(); btq.pop();
      for(int i=0; i<back[s].size(); i++){
        int e=back[s][i].first, c=back[s][i].second;
        if(dist[e]+c==dist[s]){
          for(int i=0; i<edge[e].size(); i++){
            if(edge[e][i].first==s){
              edge[e][i].second=MAX;
              break;
            }
          }

          if(visited[e]) continue;
          visited[e]=1;
          btq.push(e);
        }
      }
    }

    for(int i=0; i<N; i++){
      dist[i]=MAX;
    }
    dist[S]=0;

    dijsktra(S);
    if(dist[E]>=MAX)cout<<-1;
    else cout<<dist[E];
    cout<<'\n';
  }
}
