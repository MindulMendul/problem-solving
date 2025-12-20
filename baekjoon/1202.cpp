#include <iostream>
#include <algorithm>
#include <queue>
 
using namespace std;

int N, K;
pair<int, int> gem[300001];
int bag[300001];

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>K;
  for(int i=0; i<N; i++) {
    int m, v; cin>>m>>v;
    gem[i]=make_pair(m,v);
  } for(int i=0; i<K; i++) cin>>bag[i];

  sort(gem, gem+N);
  sort(bag, bag+K);
  
  priority_queue<int> pq;

  int ind=0;
  long long sum=0;

  for (int i=0; i<K; i++) {
    while (ind<N && bag[i]>=gem[ind].first) {
      pq.push(gem[ind].second);
      ind++;
    }

    if (!pq.empty()) {
      sum+=pq.top();
      pq.pop();
    }
  }

  cout<<sum;

  return 0;
}
