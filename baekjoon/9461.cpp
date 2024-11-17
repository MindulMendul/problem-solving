#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

vector<lli> mem;

lli P(int n){
  while(n>mem.size()){
    mem.push_back(mem[mem.size()-1]+mem[mem.size()-5]);
  } return mem[n-1];
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  mem.push_back(1);
  mem.push_back(1);
  mem.push_back(1);
  mem.push_back(2);
  mem.push_back(2);

  int T; cin>>T;
  for(int tc=1; tc<=T; tc++){
    int n; cin>>n;
    cout<<P(n)<<'\n';
  }

  return 0;
}
