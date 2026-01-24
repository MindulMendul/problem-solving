#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

int T, N, M;
vector<int> adj[MAX];

int d[MAX];
bool finished[MAX];
int id_cnt;
vector<int> stack;

int scc_id[MAX];
int scc_cnt;

int dfs(int ind){
	// init
	d[ind]=id_cnt++;
	int parent=d[ind];
	stack.push_back(ind);

	// find parent
	for(int i=0; i<adj[ind].size(); i++){
		int adj_id=adj[ind][i];
		if(d[adj_id]==0) parent=min(parent, dfs(adj_id));
		else if(!finished[adj_id]) parent=min(parent, d[adj_id]);
	}

	//make scc
	if(parent==d[ind]){
		scc_cnt++;
		while(true){
			int top=stack[stack.size()-1];
			stack.pop_back();

			scc_id[top]=scc_cnt;
			finished[top]=true;
			
			if(top==ind) break;
		}
	}

	return parent;
}

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	for(int tc=0; tc<T; tc++){
		// init
		cin>>N>>M;
		stack.clear();
		id_cnt=0;
		scc_cnt=0;
		for(int i=0; i<N; i++) {
			adj[i].clear();
			d[i]=0;
			finished[i]=false;
			scc_id[i]=0;
		}

		for(int i=0; i<M; i++){
			int s, e; cin>>s>>e;
			adj[s].push_back(e);
		}

		// calculate
		dfs(i);
	}

	return 0;
}