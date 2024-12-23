#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S, T;
  cin>>S>>T;

  queue<string> q;
  unordered_map<string, int> um;
  q.push(T);
  while(!q.empty()){
    string t=q.front(); q.pop();
    if(um.count(t)) continue;

    if(t==S) {
      cout<<1;
      return 0;
    } else if(S.size()<t.size())  {
      if(t[0]=='B'){
        string tmp=t;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        q.push(tmp);
      }
      if(t[t.size()-1]=='A'){
        t.pop_back();
        q.push(t);
      }
    }
  }
  
  cout<<0;
  return 0;
}