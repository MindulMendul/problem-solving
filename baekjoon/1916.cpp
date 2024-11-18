// https://velog.io/@717lumos/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BCDijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#3-3-%EC%BD%94%EB%93%9C-%EA%B5%AC%ED%98%84
// https://m.blog.naver.com/ndb796/221234424646

#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

vector<pair<int, int>> edge[1000];
int dp[1001];
int N, M;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b){
    return a.second>b.second;
  }
};

void dijkstra(int s){
  dp[s]=0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push(make_pair(s, 0));

  while(!pq.empty()){
    int ind=pq.top().first;
    int dis=pq.top().second;
    pq.pop();
    if(dp[ind]<dis) continue; // 이미 메모이제이션된 값보다 크면 볼 필요 x
    for(int i=0; i<edge[ind].size(); i++){
      int next_ind = edge[ind][i].first;
      int next_dis = dis+edge[ind][i].second;
      if(next_dis<dp[next_ind]){
        dp[next_ind]=next_dis;
        pq.push(make_pair(next_ind, next_dis));
      }
    }
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // memoization init
  cin>>N>>M;
  for(int i=0; i<N; i++){
    dp[i]=INF;
  }

  // edge init
  for(int i=0; i<M; i++){
    int s, e, cost; cin>>s>>e>>cost;
    edge[s-1].push_back(make_pair(e-1, cost));
  }

  int s, e; cin>>s>>e; s--; e--;

  dijkstra(s);
  cout<<dp[e];

  return 0;
}
