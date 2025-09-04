#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int N, K, L;
int map[100][100];
char time[10001];

queue<pair<int, int>> baam;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N;
  for(int i=0; i<10000; i++) time[i]='A';
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) map[i][j]=0;

  cin>>K;
  for(int i=0; i<K; i++) {
    int x, y; cin>>y>>x;
    map[y-1][x-1]=2;
  }

  cin>>L;
  for(int i=0; i<L; i++) {
    int t; char d; cin>>t>>d;
    time[t]=d;
  }

  int t=0;
  map[0][0]=1;
  baam.push(make_pair(0, 0));

  int d=0, x=0, y=0;
  while(true){
    t++;
    // cout<<t<<endl;
    // for(int i=0; i<N; i++){
    //   for(int j=0; j<N; j++){
    //     cout<<map[i][j]<<" ";
    //   }cout<<endl;
    // }cout<<endl;

    x+=dx[d]; y+=dy[d];
    if(x<0 || x>=N || y<0 || y>=N){break;}
    if(map[y][x]==1){break;}

    
    if(time[t]=='L') d=(d+3)%4;
    else if(time[t]=='D') d=(d+1)%4;

    if(map[y][x]==2){
      map[y][x]=1;
      baam.push(make_pair(x,y));
      continue;
    }
    map[y][x]=1;
    baam.push(make_pair(x,y));
    
    int tail_x=baam.front().first, tail_y=baam.front().second;
    map[tail_y][tail_x]=0;
    baam.pop();

  }

  cout<<t;

  return 0;
}