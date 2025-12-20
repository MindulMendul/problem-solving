#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2100000000

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int N, M;
int map[1500][1500];
int ice[1500][1500];
int route[1500][1500];
pair<int, int> S;
pair<int, int> E;

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);
	
  S=make_pair(-1, -1);
	E=make_pair(-1, -1);
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			char x; cin>>x;
			if(x=='.') map[i][j]=0;
			else if(x=='X') map[i][j]=1;
			else {
				if(S.first==-1){
					map[i][j]=2;
					S=make_pair(i,j);
				} else {
					map[i][j]=3;
					E=make_pair(i,j);
				}
			}

			if(x=='X') ice[i][j]=MAX;	else ice[i][j]=0;
			route[i][j]=MAX;
		}
	}

	// step 1. 얼음 녹이기
  queue<pair<int, int>> q;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==1) continue;
      q.push(make_pair(j, i));
		}
	}

  while(!q.empty()){
    int x=q.front().first, y=q.front().second;
    q.pop();
    for(int d=0; d<4; d++){
      int xx=x+dx[d], yy=y+dy[d];
      if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
      if(ice[yy][xx]<=ice[y][x]+1) continue;
      ice[yy][xx]=ice[y][x]+1;
      q.push(make_pair(xx,yy));
    }
  }

	// step 2. 백조 길 찾기
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

  route[S.first][S.second] = 0;
  pq.push({0, {S.first, S.second}});

  while(!pq.empty()){
    int cur_cost=pq.top().first;
    int y=pq.top().second.first, x=pq.top().second.second;
    pq.pop();

    if(route[y][x]<cur_cost) continue;

    if(y==E.first && x==E.second) {
      cout<<cur_cost;
      return 0;
    }

    // 다익스트라
    for(int d=0; d<4; d++){
      int xx=x+dx[d], yy=y+dy[d];
      if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
      int next_cost = max(cur_cost, ice[yy][xx]);
      if(route[yy][xx] > next_cost){
        route[yy][xx] = next_cost;
        pq.push({next_cost, {yy, xx}});
      }
    }
  }

	cout<<route[E.first][E.second];
  return 0;
}