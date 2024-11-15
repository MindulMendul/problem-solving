#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin>>N;
  set<int> s;
  vector<int> v;
  unordered_map<int, int> um;
  for(int i=0; i<N; i++){
    int a; cin>>a;
    s.insert(a);
    v.push_back(a);
  }

  int i=0;
  for (auto e : s){
    um[e]=i++;
  }

  for(int i=0; i<N; i++){
    cout<<um[v[i]]<<' ';
  }

  return 0;
}
