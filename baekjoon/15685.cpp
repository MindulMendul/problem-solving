#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,-1,-1,-1,0,1,1,1};
int bin[6]={1,2,4,8,16,32};
int gx[4][11];
int gy[4][11];
int map[101][101];

void check_pos(int x, int y){
  if(x<0) return;
  if(x>100) return;
  if(y<0) return;
  if(y>100) return;
  map[y][x]=1;
}

void dragon(int x, int y, int d, int g){
  //cout<<x<<","<<y<<" "<<d<<"/"<<gx[d][g]<<","<<gy[d][g]<<endl;

  if(g==0){
    check_pos(x,y);
    check_pos(x+gx[d][g], y+gy[d][g]);
    return;
  }
  
  dragon(x, y, d, g-1);
  dragon(x+gx[d][g], y+gy[d][g], (d+3)%4, g-1);
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i=0; i<=100; i++){ for(int j=0; j<=100; j++) {map[i][j]=0;} }
  for(int d=0; d<4; d++){
    for(int i=0; i<=10; i++){
      gx[d][i]=dx[(d*2+i)%8]*bin[i/2]; //cout<<gx[d][i]<<",";
      gy[d][i]=dy[(d*2+i)%8]*bin[i/2]; //cout<<gy[d][i]<<" ";
    }//cout<<endl;
  }

  cin>>N;
  for(int i=0; i<N; i++){
    int x, y, d, g;
    cin>>x>>y>>d>>g;
    dragon(x, y, d, g);
  }

  int ans=0;
  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++){
      if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) ans++;
    }
  }

  // for(int i=0; i<=100; i++){
  //   for(int j=0; j<=100; j++){
  //     cout<<map[i][j]<<" ";
  //   }cout<<endl;
  // }

  cout<<ans;

  return 0;
}
