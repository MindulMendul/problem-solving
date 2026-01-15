#include <iostream>

using namespace std;

int N, M;
int parent[200];
int edge[200][200];
int __par[1000];

int get_parent(int x){
  return (parent[x]==x)?x:parent[x]=get_parent(parent[x]);
}

void union_find(int a, int b){
  int pa=get_parent(a);
  int pb=get_parent(b);
  if(pa<pb) parent[b]=pa;
  else parent[a]=pb;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  for(int i=0; i<N;i++){
    parent[i]=i;
    for(int j=0; j<N; j++){
      cin>>edge[i][j];
    }
  }

  for(int i=N-1; i>=0; i--){
    for(int j=0; j<i; j++){
      if(edge[i][j]) union_find(i, j);
    }
  }
  
  for(int i=0; i<M; i++){
    cin>>__par[i]; __par[i]--;
    if(get_parent(__par[i])!=get_parent(__par[0])) {
      cout<<"NO";
      return 0;
    }
  }

  cout<<"YES";
  return 0;
}
