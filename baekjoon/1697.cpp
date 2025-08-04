#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int visited[100'001];
  for(int i=0; i<=100000; i++) visited[i]=2100000000;

  int n, k;
  cin>>n>>k;
  queue<pair<int, int>> q;
  q.push(make_pair(n,0));
  visited[n]=true;
  
  while(!q.empty()){
    int cur_x=q.front().first, cur_turn=q.front().second;
    q.pop();
    if(cur_x==k) {
      cout<<cur_turn;
      return 0;
    }
    if(cur_x-1>=0 && visited[cur_x-1]>cur_turn+1) {q.push(make_pair(cur_x-1, cur_turn+1)); visited[cur_x-1]=cur_turn+1;}
    if(cur_x+1<=100000 && visited[cur_x+1]>cur_turn+1) {q.push(make_pair(cur_x+1, cur_turn+1)); visited[cur_x+1]=cur_turn+1;}
    if(cur_x*2>=0 && cur_x*2<=100000 && visited[cur_x*2]>cur_turn+1) {q.push(make_pair(cur_x*2, cur_turn+1)); visited[cur_x*2]=cur_turn+1;}
  }
}