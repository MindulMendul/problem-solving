#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<pair<int, int>> wait_cup;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  for(int i=0; i<N; i++){
    int x, y; cin>>x>>y;
    wait_cup.push(make_pair(x, y));
  }

  int ans=0;
  priority_queue<int> pq;
  int _max=wait_cup.top().first;
  for(int i=_max; i>0; i--){
    while(!wait_cup.empty() && wait_cup.top().first>=i){
      pq.push(wait_cup.top().second);
      wait_cup.pop();
    }
    
    if(!pq.empty()){
      ans+=pq.top();
      pq.pop();
    }
  }
  
  cout<<ans;
  return 0;
}
