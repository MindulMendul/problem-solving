#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

lli cost[100001];
vector<int> visited;
lli max_cost=-1;
int max_node=-1;
int N, M;
vector<pair<int, lli>> edge[100001];

void dfs(int ind, lli c){
	visited[ind]=1;
	cost[ind]=c;
	if(max_cost<c){
		max_cost=c;
		max_node=ind;
	}

	for(int i=0; i<edge[ind].size(); i++){
		pair<int, lli> t=edge[ind][i];
		int cur=t.first;
    lli dis=t.second;
		if(visited[cur]) continue;
		dfs(cur, c+dis);
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N; M=N-1;

  // making tree
	for(int i=0; i<N; i++){
		int s; cin>>s;
    int e; lli c;
    cin>>e;
    while(e>0){
      cin>>c;
      edge[s].push_back(make_pair(e,c));
			edge[e].push_back(make_pair(s,c));
      cin>>e;
    }
	}

	visited.resize(N+1,0);
	dfs(1, 0); // 뿌리에서 가장 먼 노드를 찾음
	visited.assign(N+1,0);
	dfs(max_node, 0); // 뿌리에서 가장 먼 노드에서 가장 먼 노드의 거리가 지름임

	cout<<max_cost;

  return 0;
}
