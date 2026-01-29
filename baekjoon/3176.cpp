#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2'100'000'000

using namespace std;

int N, M;
vector<pair<int, int>> edge[100'001];
int depth[100'001];
int min_dis[100'001][18], max_dis[100'001][18];
int ancestor[100'001][18];

void makeTree(){
	queue<int> q;
	q.push(1); // set the root node
	depth[1]=1;
	while(!q.empty()){
		int parent=q.front(); q.pop();
		for(int c=0; c<edge[parent].size(); c++){
			int child=edge[parent][c].first, c_dis=edge[parent][c].second;
			if(depth[child]) continue;
			
			q.push(child);
			depth[child]=depth[parent]+1;
			ancestor[child][0]=parent;
			min_dis[child][0]=c_dis;
			max_dis[child][0]=c_dis;
			for(int i=1; i<18; i++){
				ancestor[child][i]=ancestor[ancestor[child][i-1]][i-1];
				min_dis[child][i]=min(min_dis[child][i-1], min_dis[ancestor[child][i-1]][i-1]);
				max_dis[child][i]=max(max_dis[child][i-1], max_dis[ancestor[child][i-1]][i-1]);
			}
		}
	}
}

pair<int, int> getDis(int a, int b){
	if(depth[a]<depth[b]) swap(a,b);
	// 높이를 같게!
	// 2진수에 걸맞은 점프를 하기 위함!
	int min_res=INF, max_res=0;
	for(int i=17; i>=0; i--){
		if(depth[b]<=depth[ancestor[a][i]]){
			min_res=min(min_res, min_dis[a][i]); max_res=max(max_res, max_dis[a][i]);
			a=ancestor[a][i];
		}
	}

	if(a==b) return {min_res, max_res}; // 이미 같은 조상이면 a를 출력
	
	for(int i=17; i>=0; i--){
		if(ancestor[a][i]!=ancestor[b][i]){
			min_res=min(min_res, min_dis[a][i]); max_res=max(max_res, max_dis[a][i]);
			a=ancestor[a][i];
			min_res=min(min_res, min_dis[b][i]); max_res=max(max_res, max_dis[b][i]);
			b=ancestor[b][i];
		}
	}
	min_res=min(min_res, min_dis[a][0]); max_res=max(max_res, max_dis[a][0]);
	min_res=min(min_res, min_dis[b][0]); max_res=max(max_res, max_dis[b][0]);

	return {min_res, max_res};
}

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i=0; i<=N; i++){
		depth[i]=0;
		for(int j=0; j<18; j++) {
			ancestor[i][j]=0;
			min_dis[i][j]=INF;
			max_dis[i][j]=0;
		}
	}

	for(int n=0; n<N-1; n++){
		int a, b, d; cin>>a>>b>>d;
		edge[a].push_back({b,d});
		edge[b].push_back({a,d});
	}

	depth[0]=-1;

	makeTree();
	cin>>M;
	for(int m=0; m<M; m++){
		int a, b; cin>>a>>b;
		pair<int, int> dis=getDis(a, b);
		cout<<dis.first<<" "<<dis.second<<"\n";
	}

	return 0;
}