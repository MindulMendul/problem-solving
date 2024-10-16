#include <iostream>
#include <queue>

using namespace std;

#define INF 99999999

static bool friends[101][101];
int N, M;

int bfs(int s){
	queue<pair<int,int>> q;
	q.push(make_pair(s, 1));
	bool arr[N+1];
	for(int i=1; i<=N; i++) arr[i]=false;
	arr[s]=true;
	int cnt=1, sum=0;
	while(!q.empty()){
		pair<int, int> t=q.front(); q.pop();
		for(int i=1; i<=N; i++){
			if(friends[t.first][i]){
				if(!arr[i]){
					q.push(make_pair(i, t.second+1));
					arr[i]=true;
					sum+=t.second;
					cnt++;
				}
			}
		}
		if(cnt==N){break;}
	}

	return sum;
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	// init
	cin>>N>>M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			friends[i][j]=false;
		}
	}

	for(int i=0; i<M; i++){
		int x, y;
		cin>>x>>y;
		friends[x][y]=true;
		friends[y][x]=true;
	}

	// calculate
	int ind=INF, cnt=INF;
	for(int i=1; i<=N; i++){
		int tmp_cnt=bfs(i);
		if(cnt>tmp_cnt) {cnt=tmp_cnt; ind=i;}
	}

	cout<<ind;
}
