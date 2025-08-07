#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  vector<pair<int, int>> val(N+1);
  vector<int> dp(N+2,0);
  for(int i=1; i<=N; i++) cin>>val[i].first>>val[i].second;

  for(int i=1; i<=N; i++){
    dp[i]=max(dp[i], dp[i-1]);
    int ind=i+val[i].first; if(ind-1>N) continue;
    dp[ind]=max(dp[ind], dp[i]+val[i].second);
  }
  dp[N+1]=max(dp[N+1], dp[N]);
  cout<<dp[N+1];

  return 0;
}
