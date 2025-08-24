#include <iostream>

using namespace std;

int M, N;
int map[700][700];
int add[1400];

void grow(int x, int y){
  int tmp=map[y][x-1];
  if(map[y-1][x-1]>tmp) tmp=map[y-1][x-1];
  if(map[y-1][x]>tmp) tmp=map[y-1][x];
  map[y][x]=tmp;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  //init map
  cin>>M>>N;
  
  // main code
  for(int i=0; i<2*M; i++) add[i]=1;

  for(int tc=1; tc<=N; tc++){
    int a, b, c; cin>>a>>b>>c;
    for(int i=a; i<a+b; i++) add[i]+=1;
    for(int i=a+b; i<a+b+c; i++) add[i]+=2;
  }

  for(int i=M-1; i>=0; i--) map[i][0]=add[M-1-i];
  for(int i=1; i<=M-1; i++) map[0][i]=add[M+i-1];

  for(int i=1; i<M; i++){
    grow(i,i);
    for(int j=i+1; j<M; j++) grow(i,j);
    for(int j=i+1; j<M; j++) grow(j,i);
  }

  // print
  for(int i=0; i<M; i++) {
    for(int j=0; j<M; j++){
      cout<<map[i][j]<<" ";
    }
    cout<<'\n';
  }

  return 0;
}
#include <iostream>

using namespace std;

int M, N;
int map[700][700];
int add[1400];

void grow(int x, int y){
  int tmp=map[y][x-1];
  if(map[y-1][x-1]>tmp) tmp=map[y-1][x-1];
  if(map[y-1][x]>tmp) tmp=map[y-1][x];
  map[y][x]=tmp;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  //init map
  cin>>M>>N;
  
  // main code
  for(int i=0; i<2*M; i++) add[i]=1;

  for(int tc=1; tc<=N; tc++){
    int a, b, c; cin>>a>>b>>c;
    for(int i=a; i<a+b; i++) add[i]+=1;
    for(int i=a+b; i<a+b+c; i++) add[i]+=2;
  }

  for(int i=M-1; i>=0; i--) map[i][0]=add[M-1-i];
  for(int i=1; i<=M-1; i++) map[0][i]=add[M+i-1];

  for(int i=1; i<M; i++){
    grow(i,i);
    for(int j=i+1; j<M; j++) grow(i,j);
    for(int j=i+1; j<M; j++) grow(j,i);
  }

  // print
  for(int i=0; i<M; i++) {
    for(int j=0; j<M; j++){
      cout<<map[i][j]<<" ";
    }
    cout<<'\n';
  }

  return 0;
}
