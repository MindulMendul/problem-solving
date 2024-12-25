#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin>>N;
  int mid;
  cin>>mid;
  if(N==1){cout<<mid; return 0;}

  priority_queue<int, vector<int>, less<int>> _min;
  priority_queue<int, vector<int>, greater<int>> _max;

  cout<<mid<<'\n';
  for(int i=0; i<N-1; i++){
    int s; cin>>s;
    if(mid<=s) _max.push(s);
    else _min.push(s);

    
    if(_max.size()>_min.size()+1){
      int M=_max.top(); _max.pop();
      _min.push(mid);
      mid=M;
    }
    else if(_min.size()>_max.size()){
      int M=_min.top(); _min.pop();
      _max.push(mid);
      mid=M;
    }
    cout<<mid<<'\n';
  }
  
  return 0;
}