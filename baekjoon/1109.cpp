#include <iostream>
#include <vector>
#include <queue>

#define MAX 2100000000

using namespace std;

int N, M;

int ddx[8] = {-1, 1, 0, -1, 1, -1, 0, 1};
int ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

char map[50][50];
int field[50][50];
int height[625];
int answer[625];
int parent[625];
int island_x[625], island_y[625];
int visited[50][50];

void set_island(int island_id, int x, int y) {
	queue<pair<int, int>> q;
	field[x][y] = island_id;
	island_x[island_id] = x;
	island_y[island_id] = y;
	q.push({x, y});
	while(!q.empty()) {
		auto qx=q.front().first, qy=q.front().second; q.pop();
		for(int d=0; d<8; d++) {
			int xx = qx + ddx[d], yy = qy + ddy[d];
			if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
			if(map[xx][yy] == '.') continue;
			if(field[xx][yy] != MAX) continue;
			field[xx][yy] = island_id;
			q.push({xx, yy});
		}
	}
}

void init_island() {
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			visited[i][j]=field[i][j];
		}
	}
}

int get_parent(int island_id, int x, int y) {
	init_island();
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = island_id;
	while(!q.empty()) {
		int qx = q.front().first, qy = q.front().second; q.pop();
		for(int d=0; d<4; d++) {
			int xx = qx + dx[d], yy = qy + dy[d];
			if(xx < 0 || xx >= N || yy < 0 || yy >= M) {
				height[island_id]=0;
				//cout<<"island_id: "<<island_id<<"\n";
				return island_id;
			}
			if(visited[xx][yy] != MAX) continue;
			visited[xx][yy] = island_id;
			q.push({xx, yy});
		}
	}

	init_island();
	q.push({x, y});
	int res=MAX;
	while(!q.empty()) {
		int qx = q.front().first, qy = q.front().second; q.pop();
		for(int d=0; d<4; d++) {
			int xx = qx + dx[d], yy = qy + dy[d];
			if(visited[xx][yy] == island_id) continue;
			visited[xx][yy] = island_id;
			if(field[xx][yy] != MAX) {
				res = min(res, field[xx][yy]);
				continue;
			}
			q.push({xx, yy});
		}
	}
	return res;
}

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i=0; i<625; i++) {
		height[i] = 0;
		parent[i] = i;
		answer[i] = 0;
	}

	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			field[i][j] = MAX;
		}
	}

	int ind = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]=='.') continue;
			if(field[i][j] != MAX) continue;
			set_island(ind++, i, j);
		}
	}

	if(ind==0) {
		cout<<"-1";
		return 0;
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]=='.') continue;
			if(parent[field[i][j]] != field[i][j]) continue;
			if(island_x[field[i][j]] != i || island_y[field[i][j]] != j) continue;
			int p=get_parent(field[i][j], i, j);
			parent[field[i][j]] = p;
		}
	}

	for(int i=ind-1; i>=0; i--){
		if(height[i] == MAX) height[i] = 0;
		if(parent[i] == i) continue;
		height[parent[i]] = max(height[parent[i]], height[i]+1);
	}

	// for(int i=0; i<ind; i++){
	// 	if(height[i] == MAX) continue;
	// 	cout<<i<<" "<<parent[i]<<" "<<height[i]<<"\n";
	// }

	for(int i=0; i<ind; i++){
		if(height[i] == MAX) continue;
		answer[height[i]]++;
	}

	for(int i=0; i<M; i++){
		if(answer[i] == 0) continue;
		cout<<answer[i]<<" ";
	}

	return 0;
}
