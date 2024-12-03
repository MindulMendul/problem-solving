#include <iostream>

using namespace std;

int sticker[2][100001];
int dp[2][100001];
int N;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin>>T;

	for(int tc=1; tc<=T; tc++){
		cin>>N;
		for(int i=0; i<N; i++){cin>>sticker[0][i];}
		for(int i=0; i<N; i++){cin>>sticker[1][i];}

		if(N==1) {
			cout<<max(sticker[0][0], sticker[1][0])<<'\n';
			continue;
		}

		dp[0][0]=sticker[0][0];
		dp[1][0]=sticker[1][0];
		dp[0][1]=sticker[1][0]+sticker[0][1];
		dp[1][1]=sticker[0][0]+sticker[1][1];

		for(int i=2; i<N; i++){
			dp[0][i]=sticker[0][i]+max(dp[1][i-2], max(dp[1][i-1], dp[0][i-2]));
			dp[1][i]=sticker[1][i]+max(dp[0][i-2], max(dp[0][i-1], dp[1][i-2]));
		}
		cout<<max(dp[0][N-1], max(dp[1][N-1], max(dp[0][N-2], dp[1][N-2])))<<'\n';
	}

  return 0;
}
