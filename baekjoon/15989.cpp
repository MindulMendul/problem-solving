#include <iostream>
#include <vector>

using namespace std;

int TC;
vector<int> dp;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	dp.push_back(1);
	dp.push_back(1);
	dp.push_back(2);
	dp.push_back(3);
	dp.push_back(4);

	for(int i=5; i<=10000; i++){
		dp.push_back(dp[i-3]+dp[i-2]-dp[i-5]+1);
	}
	dp[0]=0;

  cin>>TC;
	for(int tc=0; tc<TC; tc++){
		int a; cin>>a;
		cout<<dp[a]<<'\n';
	}
	
  return 0;
}
