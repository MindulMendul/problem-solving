#include <iostream>
#include <vector>

using namespace std;

int cost[10001];
vector<int> visited;
int max_cost=-1, max_node=-1;
int N, M;
vector<pair<int, int>> edge[10001];

void dfs(int c, int ind){
	visited[ind]=1;
	cost[ind]=c;
	if(max_cost<c){
		max_cost=c;
		max_node=ind;
	}

	for(int i=0; i<edge[ind].size(); i++){
		pair<int, int> t=edge[ind][i];
		int cur=t.first, dis=t.second;
		if(visited[cur]) continue;
		dfs(c+dis, cur);
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N; M=N-1;

  // making tree
	for(int i=0; i<M; i++){
		int s, e, c;
		cin>>s>>e>>c;
		edge[s].push_back(make_pair(e,c));
		edge[e].push_back(make_pair(s,c));
	}

	visited.resize(N+1,0);
	dfs(0, 1);
	visited.assign(N+1,0);
	dfs(0, max_node);

	cout<<max_cost;

  return 0;
}
