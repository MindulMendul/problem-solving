#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K; cin>>N>>K;
  vector<int> coins;
  for(int i=0; i<N; i++){
    int coin; cin>>coin;
    coins.push_back(coin);
  }

  int i=coins.size()-1, ans=0;
  while(K>0){
    if(K>=coins[i]){
      K-=coins[i];
      ans++;
    } else {
      i--;
    }
  }
  cout<<ans;

  return 0;
}
