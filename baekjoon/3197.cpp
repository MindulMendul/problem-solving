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

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b){
		if(route[a.second][a.first]!=route[b.second][b.first]) return route[a.second][a.first]-route[b.second][b.first];
		if(a.second!=b.second) return a.second-b.second;
		return a.first-b.first;
	}
};

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
					S=make_pair(j,i);
				} else {
					map[i][j]=3;
					E=make_pair(j,i);
				}
			}

			if(x=='X') ice[i][j]=MAX;	else ice[i][j]=0;
			route[i][j]=MAX;
		}
	}

	// step 1. 얼음 녹이기
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]>0) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(j,i));
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
		}
	}

	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<M; j++){
	// 		cout<<ice[i][j]<<" ";
	// 	}cout<<endl;
	// }cout<<endl;
	// step 2. 백조 길 찾기
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	route[S.second][S.first]=0;
	pq.push(S);
	while(!pq.empty()){
		int flag=false;
		int x=pq.top().first, y=pq.top().second;
		pq.pop();
		for(int d=0; d<4; d++){
			int xx=x+dx[d], yy=y+dy[d];
			if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
			if(route[yy][xx]<=route[y][x]) continue;
			route[yy][xx]=route[y][x];
			if(ice[yy][xx]>route[yy][xx]) route[yy][xx]=ice[yy][xx];
			if(yy==E.first && xx==E.second) {
				flag=true; break;
			}
			pq.push(make_pair(xx,yy));
		}
		if(flag) break;
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<route[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;

	cout<<route[E.second][E.first];
  return 0;
}