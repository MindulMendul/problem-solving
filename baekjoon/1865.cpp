#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

typedef long long int lli;
typedef pair<pair<int, int>, lli> ppi;

lli dis[501];
ppi edge[5200];
int T, N, M, W;

void get_input(){
  cin>>N>>M>>W;
  for(int i=1; i<=N; i++) dis[i]=INF;
  dis[1]=0;

  for(int m=0; m<2*M; m+=2) {
    int s,e; lli t;
    cin>>s>>e>>t;
    edge[m]={{s,e},t};
    edge[m+1]={{e,s},t};
  }

  for(int m=2*M; m<2*M+W; m++) {
    int s,e; lli t;
    cin>>s>>e>>t;
    edge[m]={{s,e},-t};
  }
}

bool bellman_ford(){
  for(int n=1; n<N; n++){
    for(int m=0; m<2*M+W; m++){
      int s=edge[m].first.first;
      int e=edge[m].first.second;
      lli t=edge[m].second;
      if(dis[e]>dis[s]+t){
        dis[e]=dis[s]+t;
      }
    }
  }

  // check the cycle
  for(int m=0; m<2*M+W; m++){
    int s=edge[m].first.first;
    int e=edge[m].first.second;
    lli t=edge[m].second;
    if(dis[e]>dis[s]+t) return true;
  }

  return false;
}


int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin>>T;
    for(int tc=0; tc<T; tc++){
        get_input();
        bool flag=bellman_ford();
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}