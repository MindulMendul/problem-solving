#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2100000000

int N, M, K, W, ans;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int map[20][20];
int cold[20][20];
int cold_add[20][20];
int cold_aircon[20][20];
int visited[20][20];
int wall[20][20][4];
vector<pair<int, int>> company;
vector<pair<int, int>> aircon; // 0:r 1:l 2:u 3:d

bool check_company(){
    for(int i=0; i<company.size(); i++){
        int x=company[i].first, y=company[i].second;
        if(cold[y][x]<K) return false;
    }
    return true;
}

void init_cold_add(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cold_add[i][j]=0;
        }
    }
}

void init_visited(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j]=0;
        }
    }
}

void bfs_left(int sx, int sy){
    if(wall[sy][sx][1]==1) return;
    sx-=1; if(sx<0)return; if(visited[sy][sx]==1) return;
    queue<pair<pair<int, int>,int>> q;
    q.push(make_pair(make_pair(sx, sy), 5));
    visited[sy][sx]=1;
    cold_add[sy][sx]=5;
    while(!q.empty()){
        int x=q.front().first.first, y=q.front().first.second, temp=q.front().second;
        q.pop();
        if(x==0) continue; if(temp<=1) continue;
        if(y>0 && wall[y][x][2]==0 && wall[y-1][x][1]==0 && visited[y-1][x-1]==0){
            q.push(make_pair(make_pair(x-1,y-1), temp-1));
            visited[y-1][x-1]=1;
            cold_add[y-1][x-1]=temp-1;
        }
        if(wall[y][x][1]==0 && visited[y][x-1]==0){
            q.push(make_pair(make_pair(x-1,y), temp-1));
            visited[y][x-1]=1;
            cold_add[y][x-1]=temp-1;
        }
        if(y+1<N && wall[y][x][3]==0 && wall[y+1][x][1]==0 && visited[y+1][x-1]==0){
            q.push(make_pair(make_pair(x-1,y+1), temp-1));
            visited[y+1][x-1]=1;
            cold_add[y+1][x-1]=temp-1;
        }
    }
}

void bfs_up(int sx, int sy){
    if(wall[sy][sx][2]==1) return;
    sy-=1; if(sy<0)return; if(visited[sy][sx]==1) return;
    queue<pair<pair<int, int>,int>> q;
    q.push(make_pair(make_pair(sx, sy), 5));
    visited[sy][sx]=1;
    cold_add[sy][sx]=5;
    while(!q.empty()){
        int x=q.front().first.first, y=q.front().first.second, temp=q.front().second;
        q.pop();
        if(y==0) continue; if(temp<=1) continue;
        if(x>0 && wall[y][x][1]==0 && wall[y][x-1][2]==0 && visited[y-1][x-1]==0){
            q.push(make_pair(make_pair(x-1,y-1), temp-1));
            visited[y-1][x-1]=1;
            cold_add[y-1][x-1]=temp-1;
        }
        if(wall[y][x][2]==0 && visited[y-1][x]==0){
            q.push(make_pair(make_pair(x,y-1), temp-1));
            visited[y-1][x]=1;
            cold_add[y-1][x]=temp-1;
        }
        if(x+1<M && wall[y][x][0]==0 && wall[y][x+1][2]==0 && visited[y-1][x+1]==0){
            q.push(make_pair(make_pair(x+1,y-1), temp-1));
            visited[y-1][x+1]=1;
            cold_add[y-1][x+1]=temp-1;
        }
    }
}

void bfs_right(int sx, int sy){
    if(wall[sy][sx][0]==1) return;
    sx+=1; if(sx>=M) return; if(visited[sy][sx]==1) return;
    queue<pair<pair<int, int>,int>> q;
    q.push(make_pair(make_pair(sx, sy), 5));
    visited[sy][sx]=1;
    cold_add[sy][sx]=5;
    while(!q.empty()){
        int x=q.front().first.first, y=q.front().first.second, temp=q.front().second;
        q.pop();
        if(x==M-1) continue; if(temp<=1) continue;
        if(y>0 && wall[y][x][2]==0 && wall[y-1][x][0]==0 && visited[y-1][x+1]==0){
            q.push(make_pair(make_pair(x+1,y-1), temp-1));
            visited[y-1][x+1]=1;
            cold_add[y-1][x+1]=temp-1;
        }
        if(wall[y][x][0]==0 && visited[y][x+1]==0){
            q.push(make_pair(make_pair(x+1,y), temp-1));
            visited[y][x+1]=1;
            cold_add[y][x+1]=temp-1;
        }
        if(y+1<N && wall[y][x][3]==0 && wall[y+1][x][0]==0 && visited[y+1][x+1]==0){
            q.push(make_pair(make_pair(x+1,y+1), temp-1));
            visited[y+1][x+1]=1;
            cold_add[y+1][x+1]=temp-1;
        }
    }
}

void bfs_down(int sx, int sy){
    if(wall[sy][sx][3]==1) return;
    sy+=1; if(sy>=N) return; if(visited[sy][sx]==1) return;
    queue<pair<pair<int, int>,int>> q;
    q.push(make_pair(make_pair(sx, sy), 5));
    visited[sy][sx]=1;
    cold_add[sy][sx]=5;
    while(!q.empty()){
        int x=q.front().first.first, y=q.front().first.second, temp=q.front().second;
        q.pop();
        if(y==N-1) continue; if(temp<=1) continue;
        if(x>0 && wall[y][x][1]==0 && wall[y][x-1][3]==0 && visited[y+1][x-1]==0){
            q.push(make_pair(make_pair(x-1,y+1), temp-1));
            visited[y+1][x-1]=1;
            cold_add[y+1][x-1]=temp-1;
        }
        if(wall[y][x][3]==0 && visited[y+1][x]==0){
            q.push(make_pair(make_pair(x,y+1), temp-1));
            visited[y+1][x]=1;
            cold_add[y+1][x]=temp-1;
        }
        if(x+1<M && wall[y][x][0]==0 && wall[y][x+1][3]==0 && visited[y+1][x+1]==0){
            q.push(make_pair(make_pair(x+1,y+1), temp-1));
            visited[y+1][x+1]=1;
            cold_add[y+1][x+1]=temp-1;
        }
    }
}

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);
  ans=0;
  cin>>N>>M>>K;
  for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
          cold[i][j]=0;
          visited[i][j]=0;
          cold_add[i][j]=0;
          cold_aircon[i][j]=0;
          for(int d=0; d<4; d++) wall[i][j][d]=0;
          cin>>map[i][j];
          if(map[i][j]==5) company.push_back(make_pair(j,i));
          else if(map[i][j]>0) aircon.push_back(make_pair(j,i));
      }
  }
  
  cin>>W;
  for(int w=0; w<W; w++){
      int x, y, s; cin>>y>>x>>s; x--; y--;
      if(s==0) {wall[y][x][2]=1; wall[y-1][x][3]=1;}
      else if(s==1) {wall[y][x][0]=1; wall[y][x+1][1]=1;}
  }

  // 미리 에어컨 시원해지는 거 구해두기
  for(int aircon_ind=0; aircon_ind<aircon.size(); aircon_ind++){
      int aircon_x=aircon[aircon_ind].first, aircon_y=aircon[aircon_ind].second;
      int aircon_dir=map[aircon_y][aircon_x]-1;

      init_cold_add();
      init_visited();
      if(aircon_dir==1) bfs_left(aircon_x, aircon_y);
      else if(aircon_dir==2) bfs_up(aircon_x, aircon_y);
      else if(aircon_dir==0) bfs_right(aircon_x, aircon_y);
      else if(aircon_dir==3) bfs_down(aircon_x, aircon_y);

      for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
              cold_aircon[i][j]+=cold_add[i][j];
          }
      }
  }

//   for(int i=0; i<N; i++){
//       for(int j=0; j<M; j++){
//           cout<<cold_aircon[i][j]<<' ';
//       }cout<<endl;
//   }cout<<endl;

  for(int time=0; time<=100; time++){
    //   if(time>-1){
    //       for(int i=0; i<N; i++){
    //           for(int j=0; j<M; j++){
    //               cout<<cold[i][j]<<" ";
    //               //cout<<(map[i][j]==1?cold[i][j]:0)<<" ";
    //           }cout<<endl;
    //       }cout<<endl;
    //   }
      
      // step 0. 시원한지 체크하기.
      if(check_company()){cout<<time; return 0;}

      // step 1. 시원하게 하기
      for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
              cold[i][j]+=cold_aircon[i][j];
          }
      }
      // if(time>11){
      //     for(int i=0; i<N; i++){
      //         for(int j=0; j<M; j++){
      //             cout<<cold[i][j]<<" ";
      //             //cout<<(map[i][j]==1?cold[i][j]:0)<<" ";
      //         }cout<<endl;
      //     }cout<<endl;
      // }
      
      // step 2. 공기 섞이기
      init_cold_add();
      for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
              for(int d=0; d<4; d++){
                  int xx=j+dx[d], yy=i+dy[d];
                  if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
                  if(cold[i][j]<=cold[yy][xx]) continue;
                  if(wall[i][j][d]==1) continue;
                  int cold_diff=(cold[i][j]-cold[yy][xx])/4;
                  cold_add[i][j]-=cold_diff;
                  cold_add[yy][xx]+=cold_diff;
              }
          }
      }

      // if(time>11){
      //     for(int i=0; i<N; i++){
      //         for(int j=0; j<M; j++){
      //             cout<<cold_add[i][j]<<" ";
      //             //cout<<(map[i][j]==1?cold[i][j]:0)<<" ";
      //         }cout<<endl;
      //     }cout<<endl;
      // }
      
      for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
              cold[i][j]+=cold_add[i][j];
          }
      }

      // step 3. 가생이 부분 처리하기
      for(int i=0; i<N-1; i++){
        if(cold[N-1-i][0]>0) cold[N-1-i][0]-=1;
        if(cold[i][M-1]>0) cold[i][M-1]-=1;
      }

      for(int i=0; i<M-1; i++){
        if(cold[0][i]>0) cold[0][i]-=1;
        if(cold[N-1][M-1-i]>0) cold[N-1][M-1-i]-=1;
      }
  }

  cout<<101;
  return 0;
}