#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> edge[40'001];
int depth[40'001];
int dis[40'001];
int ancestor[40'001][17];

void makeTree(){
	queue<int> q;
	q.push(1); // set the root node
	depth[1]=1;
	dis[1]=0;
	while(!q.empty()){
		int parent=q.front(); q.pop();
		for(int c=0; c<edge[parent].size(); c++){
			int child=edge[parent][c].first, c_dis=edge[parent][c].second;
			if(depth[child]) continue;
			
			q.push(child);
			depth[child]=depth[parent]+1;
			dis[child]=dis[parent]+c_dis;
			ancestor[child][0]=parent;
			for(int i=1; i<=16; i++){
				ancestor[child][i]=ancestor[ancestor[child][i-1]][i-1];
			}
		}
	}
}

int getAncestor(int a, int b){
	if(depth[a]<depth[b]) swap(a,b);
	// 높이를 같게!
	// 2진수에 걸맞은 점프를 하기 위함!
	for(int i=16; i>=0; i--){
		if(depth[b]<=depth[ancestor[a][i]]){
			a=ancestor[a][i];
		}
	}

	if(a==b) return a; // 이미 같은 조상이면 a를 출력
	for(int i=16; i>=0; i--){
		if(ancestor[a][i]!=ancestor[b][i]){
			a=ancestor[a][i];
			b=ancestor[b][i];
		}
	}

	return ancestor[a][0];
}

int getDis(int a, int b){
	return dis[a]+dis[b]-2*dis[getAncestor(a, b)];
}

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i=0; i<=N; i++){
		depth[i]=0;
		for(int j=0; j<17; j++) ancestor[i][j]=0;
	}

	for(int n=0; n<N-1; n++){
		int a, b, d; cin>>a>>b>>d;
		edge[a].push_back({b,d});
		edge[b].push_back({a,d});
	}

	depth[0]=-1;
	dis[0]=0;

	makeTree();
	cin>>M;
	for(int m=0; m<M; m++){
		int a, b; cin>>a>>b;
		cout<<getDis(a, b)<<"\n";
	}

	return 0;
}