// 일단 구간 별로 갈 수 있는 방법을 다 찾아보자.
// 해봤자 100*100*2 니까 연산은 문제가 없음
// 구간 별로는 bfs로 완탐 걸어서 풀고,
// 구간을 구한 뒤에는 DP로 풀면 되겠다.

// (나이트, N일 때 현재 최소값) => min((나이트, N-1일 때 최소값), (비숍, N-1일 때 최소값)+1, (룩, N-1일 때 최소값)+1) 
// (비숍, N일 때 현재 최소값) => min((나이트, N-1일 때 최소값)+1, (비숍, N-1일 때 최소값), (룩, N-1일 때 최소값)+1) 
// (룩, N일 때 현재 최소값) => min((나이트, N-1일 때 최소값)+1, (비숍, N-1일 때 최소값)+1, (룩, N-1일 때 최소값)) 
// 정답 = min((나이트, N*N일 때 현재 최소값), (비숍, N*N일 때 현재 최소값), (룩, N*N일 때 현재 최소값))

#include <iostream>
#include <algorithm>
#include <queue>
 
using namespace std;

#define MAX 1'000'000'000

int N;
int board[10][10];
pair<int, int> seq[101];

// N에서 N+1번째까지 갈 때 거리
int knight_dis[100];
int bishop_dis[100];
int look_dis[100];

// N에서 N+1번째까지 갈 때 DP
int knight_dp[100];
int bishop_dp[100];
int look_dp[100];

// 말이 움직이는 패턴
int kdx[8]={1,2,2,1,-1,-2,-2,-1};
int kdy[8]={-2,-1,1,2,2,1,-1,-2};
int bdx[4]={1,1,-1,-1};
int bdy[4]={-1,1,1,-1};
int ldx[4]={1,0,-1,0};
int ldy[4]={0,1,0,-1};

void print(); 

int min3(int a, int b, int c){
  return min(a, min(b, c));
}

int bfs(int n){
  int visited[N][N];
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) visited[i][j]=0;

  queue<pair<int, pair<int, int>>> q;
  q.push(make_pair(0, seq[n]));
  visited[seq[n].first][seq[n].second]=1;
  while(!q.empty()){
    int x=q.front().second.second, y=q.front().second.first, cost=q.front().first;
    if(x==seq[n+1].second && y==seq[n+1].first) return cost; // 같은 위치면 도착
    q.pop();

    // 나이트 움직임
    for(int d=0; d<8; d++){
      int xx=x+kdx[d], yy=y+kdy[d];
      if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
      q.push(make_pair(cost+1, make_pair(yy,xx)));
    }

    // 비숍 움직임
    for(int d=0; d<4; d++){
      for(int z=1; true; z++){
        int xx=x+bdx[d]*z, yy=y+bdy[d]*z;
        if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
        q.push(make_pair(cost+1, make_pair(yy,xx)));
      }
    }

    // 룩 움직임

  }

  return MAX; // 못 가는 경우가 생길 수 있음
}
 
int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
    cin>>board[i][j];
    seq[board[i][j]].first=i;
    seq[board[i][j]].second=j;
  }

  // 갈 수 있는 거리 재기
  // 말_dis[n] = n -> n+1 까지 가는데 걸리는 거리
  knight_dis[0]=0; bishop_dis[0]=0; look_dis[0]=0;
  for(int i=1; i<=N*N; i++){
    knight_dis[i]=knight_bfs(i);
    bishop_dis[i]=bishop_bfs(i);
    look_dis[i]=look_bfs(i);
  }

  // 갈 수 있는 DP 재기
  knight_dp[0]=0; bishop_dp[0]=0; look_dp[0]=0;
  for(int i=1; i<N*N; i++){
    knight_dp[i]=min3(knight_dp[i-1]+knight_dis[i], bishop_dp[i-1]+knight_dis[i]+1, look_dp[i-1]+knight_dis[i]+1);
    bishop_dp[i]=min3(knight_dp[i-1]+bishop_dis[i]+1, bishop_dp[i-1]+bishop_dis[i], look_dp[i-1]+bishop_dis[i]+1);
    look_dp[i]=min3(knight_dp[i-1]+look_dis[i]+1, bishop_dp[i-1]+look_dis[i]+1, look_dp[i-1]+look_dis[i]);
  }

  // print();

  cout<<min3(knight_dp[N*N-1], bishop_dp[N*N-1], look_dp[N*N-1]);
  return 0;
}

void print(){
  cout<<"knight\n";
  for(int i=0; i<N*N; i++){
    if(knight_dis[i]>MAX-10) cout<<"M ";
    else cout<<knight_dis[i]<<" ";
  }cout<<endl;

  for(int i=0; i<N*N; i++){
    if(knight_dp[i]>MAX-10) cout<<"M ";
    else cout<<knight_dp[i]<<" ";
  }cout<<endl<<endl;

  cout<<"bishop\n";
  for(int i=0; i<N*N; i++){
    if(bishop_dis[i]>MAX-10) cout<<"M ";
    else cout<<bishop_dis[i]<<" ";
  }cout<<endl;

  for(int i=0; i<N*N; i++){
    if(bishop_dp[i]>MAX-10) cout<<"M ";
    else cout<<bishop_dp[i]<<" ";
  }cout<<endl<<endl;

  cout<<"look\n";
  for(int i=0; i<N*N; i++){
    if(look_dis[i]>MAX-10) cout<<"M ";
    else cout<<look_dis[i]<<" ";
  }cout<<endl;

  for(int i=0; i<N*N; i++){
    if(look_dp[i]>MAX-10) cout<<"M ";
    else cout<<look_dp[i]<<" ";
  }cout<<endl<<endl;
}