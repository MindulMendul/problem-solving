#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int N, M; cin>>N>>M;
  unordered_map<string, string> um;

  for(int i=0; i<N; i++){
    string site, pw; cin>>site>>pw;
    um[site]=pw;
  }

  for(int i=0; i<M; i++){
    string site; cin>>site;
    cout<<um[site]<<"\n";
  }

  return 0;
}
