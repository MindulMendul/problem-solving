#include <iostream>
#include <queue>

using namespace std;

typedef long long int lli;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  lli A, B;
  bool flag=false;
  cin>>A>>B;
  queue<pair<lli, lli>> q;
  q.push(make_pair(A,1));
  while(!q.empty()){
    pair<lli, lli> h=q.front(); q.pop();
    if(B==h.first){
      cout<<h.second;
      flag=true;
      break;
    } else if(B>h.first){
      q.push(make_pair(h.first*10+1, h.second+1));
      q.push(make_pair(h.first*2, h.second+1));
    }
  }
  if(!flag){cout<<-1;}
  return 0;
}
