#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

typedef long long int lli;
typedef pair<pair<int, int>, lli> ppi;

lli dis[501];
ppi edge[6000];
int N, M;

ppi make_ppi(int s, int e, lli t){
  return make_pair(make_pair(s,e),t);
}

void get_input(){
  cin>>N>>M;
  for(int i=1; i<=N; i++) dis[i]=INF;
  dis[1]=0;

  for(int m=0; m<M; m++) {
    int s,e; lli t;
    cin>>s>>e>>t;
    edge[m]=make_ppi(s,e,t);
  }
}

bool bellman_ford(){
  get_input();

  for(int n=1; n<N; n++){
    for(int m=0; m<M; m++){
      int s=edge[m].first.first;
      int e=edge[m].first.second;
      lli t=edge[m].second;
      if(dis[s]!=INF && dis[e]>dis[s]+t){
        dis[e]=dis[s]+t;
      }
    }
  }

  // check the cycle
  for(int m=0; m<M; m++){
    int s=edge[m].first.first;
    int e=edge[m].first.second;
    lli t=edge[m].second;
    if(dis[s]!=INF && dis[e]>dis[s]+t) return true;
  }

  return false;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  bool flag=bellman_ford();
  if(flag) {
    cout<<-1; return 0;
  }

  for(int i=2; i<=N; i++){
    if(dis[i]==INF) cout<<-1;
    else cout<<dis[i];
    cout<<'\n';
  }

  return 0;
}
