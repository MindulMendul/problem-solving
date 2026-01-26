#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> adj[10'001];
int d[10'001];
int scc_id[10'001];
int finish[10'001];
int id_cnt=0;
int scc_cnt=0;
vector<int> scc_stack;
vector<int> scc_ans[10'001];
bool scc_ans_visited[10'001];

int dfs(int ind){
  d[ind]=++id_cnt;
  int parent=d[ind];
  scc_stack.push_back(ind);

  for(int i=0; i<adj[ind].size(); i++){
    int next=adj[ind][i];
    if(d[next]==0) parent=min(parent, dfs(next));
    else if(!finish[next]) parent=min(parent, d[next]);
  }

  // 본인이 대빵인 경우
  if(parent==d[ind]){
    scc_cnt++;

    while(true){
      int top=scc_stack[scc_stack.size()-1];
      scc_ans[scc_cnt].push_back(top);
      scc_stack.pop_back();

      scc_id[top]=scc_cnt;
      finish[top]=true;
      
      if(top==ind) break;
    }
  }
  return parent;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // init
  cin>>N>>M;
  for(int i=0; i<M; i++){
    int a, b; cin>>a>>b;
    adj[a].push_back(b);
  }
  for(int i=1; i<=N; i++){
    d[i]=0;
    scc_id[i]=0;
    finish[i]=false;
  }

  // calculate
  for(int i=1; i<=N; i++){
    if(d[i]==0) dfs(i);
  }

  cout<<scc_cnt<<"\n";
  for(int i=0; i<=scc_cnt; i++){
    scc_ans_visited[i]=false;
  }

  for(int i=1; i<=N; i++){
    if(scc_ans_visited[scc_id[i]]) continue;
    scc_ans_visited[scc_id[i]]=true;
    sort(scc_ans[scc_id[i]].begin(),scc_ans[scc_id[i]].end());
    for(int j=0; j<scc_ans[scc_id[i]].size(); j++){
      cout<<scc_ans[scc_id[i]][j]<<" ";
    }cout<<"-1\n";
  }

  return 0;
}
