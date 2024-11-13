#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  int s;
  int e;
  int cost;
} Edge;

bool cmp(Edge e1, Edge e2) {
  return e1.cost<e2.cost;
}

int parent[10001];

int getParent(int p){
  if(p==parent[p]) return p;
  return parent[p]=getParent(parent[p]);
}

void unionFind(int a, int b){
  int pa=getParent(a), pb=getParent(b);
  if(pa>pb) parent[pa]=pb;
  else parent[pb]=pa;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int V, E; cin>>V>>E;
  vector<Edge> ve;

  for(int i=0; i<E; i++) {
    Edge e; cin>>e.s>>e.e>>e.cost;
    ve.push_back(e);
  }
  sort(ve.begin(), ve.end(), cmp);

  for(int i=0; i<=V; i++) {
    parent[i]=i;
  }

  int ans=0;
  for(int i=0; i<E; i++){
    Edge e=ve[i];
    if(getParent(e.s)==getParent(e.e)) continue;
    unionFind(e.s, e.e);
    ans+=e.cost;
  }

  cout<<ans;

  return 0;
}
