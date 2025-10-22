#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b){
    if(a.second==b.second) return a.first<b.first;
   return a.second<b.second;
  }
};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, d; cin>>N;
  vector<pair<int, int>> human(N);
  for(int i=0; i<N; i++){
    int h, o; cin>>h>>o;
    if(h>o) {int tmp=h; h=o; o=tmp;}
    human[i]=make_pair(h, o);
  }
  cin>>d;
  sort(human.begin(), human.end(), cmp());
  
  int ans=0;
  priority_queue<int> pq;
  for(int i=0; i<N; i++){
    int s=human[i].first, e=human[i].second;
    if(e-s<=d) pq.push(-s);
    else continue;
    while(!pq.empty()){
      if(-pq.top()<e-d) pq.pop();
      else {
        if(ans<pq.size()) ans=pq.size();
        break;
      }
    }
  }

  cout<<ans;

  return 0;
}
