// BFS로 조사해서 가능한 곳을 선택해서 구하면 되는 구현 문제.
// pair<int, pair<int, int>> 로 조건을 구했는데, 각각 (거리, x좌표, y좌표) 라고 생각하고 문제를 풀었음.

#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

int N, x, y, shark, ans, hungry;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

// 조건에 맞게 비교연산자 세팅
// (거리 우선, y좌표 우선, x좌표 우선)
struct cmp {
  bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>>  b){
    if(a.first!=b.first) return a.first>b.first;
    if(a.second.second!=b.second.second) return a.second.second>b.second.second;
    return a.second.first>b.second.first;
  }
};

// BFS를 이용해서 잡아먹을 물고기 위치를 선정함.
// 만약, 물고기가 없다면 거리가 INF인 물고기를 반환함.
pair<int, pair<int, int>> findFish(vector<vector<int>>& tank){
  // 우선순위큐로 후보 물고기 중에 정답 물고기를 top으로 받음 
  priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>> >, cmp> pq;
  pq.push(make_pair(INF, make_pair(100, 100)));

  // 기본 BFS 세팅
  vector<vector<int>> visited(N, vector<int>(N, 0));
  queue<pair<int, pair<int, int>>> q;
  visited[y][x]=1;
  q.push(make_pair(0, make_pair(x,y)));

  while(!q.empty()){
    int tcnt=q.front().first, tx=q.front().second.first, ty=q.front().second.second; q.pop();

    // 근데 이제 거리가 후보 물고기들보다 멀면 애초에 더 탐색할 필요 없이 탐색을 멈춤.
    // BFS라서 탐색하는 애들은 전부 거리가 가까운 애들부터 먼 애들 순으로 검색한다는 사실이 보장됨.
    if(tcnt>pq.top().first) break;


    for(int d=0; d<4; d++){
      // 탐색할 좌표 지정.
      int xx=tx+dx[d], yy=ty+dy[d];

      // 조건에 맞지 않으면 검색할 이유가 없음.
      if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
      if(tank[yy][xx]>fish) continue;
      if(visited[yy][xx]) continue;

      // 조건에 맞으면 BFS를 위해 큐에 후보지 갱신해주기.
      visited[yy][xx]=1;
      q.push(make_pair(tcnt+1, make_pair(xx, yy)));

      // 그 중에서 조건에 맞으면 후보 물고기로 등록
      if(tank[yy][xx]>0 && tank[yy][xx]<fish)  pq.push(make_pair(tcnt+1,make_pair(xx, yy)));
    }
  }
  
  // 정답 물고기는 후보 물고기 중 첫 번째
  return pq.top();
}

// 아기 상어는 물고기를 찾아 움직인다네~
void moveFish(vector<vector<int>>& tank){
  while(true){
    // 이동할 위치 탐색
    pair<int, pair<int, int>> target=findFish(tank);
    
    // 엄마 모셔와야 하는 경우
    if(target.first==INF) { cout<<ans; return; }

    // 엄마 안 모셔와도 되는 경우
    ans+=target.first;
    x=target.second.first; y=target.second.second;
    tank[y][x]=0; hungry++;
    if(hungry==shark){ hungry=0; shark++; }
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N; shark=2; hungry=0; ans=0;
  vector<vector<int>> tank(N, vector<int>(N,0));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>>tank[i][j];
      if(tank[i][j]==9) { x=j; y=i; tank[i][j]=0; }
    }
  }

  moveFish(tank);

  return 0;
}
