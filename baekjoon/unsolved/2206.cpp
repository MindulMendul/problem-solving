#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001][2];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N, M;
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>arr[i][j];
		}
	}

	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0,make_pair(0,0)));
	while(!q.empty()){
		pair<int, pair<int, int>> t=q.front(); q.pop();
		int ans=t.first, y=t.second.first, x=t.second.second;
		if(y==N-1 && x==M-1) {cout<<ans;	return 0;}
		for(int i)
	}
	cout<<-1;
  return 0;
}
