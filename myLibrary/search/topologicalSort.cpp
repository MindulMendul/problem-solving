// 방향 트리 그래프에만 가능한 탐색법(정렬법)
// 제일 머리들을 순차적으로 검색하고
// 검색이 끝나면 해당 토폴로지에서 지운 뒤에
// 다시 제일 머리들을 순차적으로 검색하는 방법
// bfs와 그래프를 이용해서 구현하면 쉬움!

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[1001];
vector<int> degree(1001, 0);

int main(){
  int N, M; cin>>N>>M;

  // 토폴로지 만드는 중
  // degree: 해당 노드로 오는 길이 몇 개나 있는지 개수
  for(int i=0; i<M; i++){
    int t, s, e;
    cin>>t>>s;
    for(int j=1; j<t; j++){
      cin>>e;
      edge[s].push_back(e);
      degree[e]++;
      s=e;
    }
  }

  // degree 가 0 인 애들을 먼저 탐색할 예정
  queue<int> q;
  vector<int> ans;
  for(int i=1; i<=N; i++){
    if(degree[i]==0) q.push(i);
  }

  // bfs로 degree 가 0인 애들을 순차적으로 탐색함.
  // 탐색 중에는 degree가 바뀌는 애들이 반드시 존재하므로 그에 따라 degree 값을 바꾸어야 함
  // 바꾼 degree 역시 0이면 탐색해야 함
  while(!q.empty()){
    int qq=q.front(); q.pop();
    ans.push_back(qq);
    for(int e: edge[qq]){
      if(--degree[e]==0) q.push(e);
    }
  }

  // 만약 탐색 후보지의 개수가 전체 토폴로지의 노드 수보다 작으면 반드시 사이클이 존재함
  // 사이클이 존재하는 그래프는 위상정렬을 할 수 없음
  if(ans.size()!=N){
    cout<<0;
    return 0;
  }
  
  for(int a:ans){
    cout<<a<<'\n';
  }

  return 0;
}
