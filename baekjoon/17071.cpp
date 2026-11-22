/*
아이디어.
수빈이가 갈 수 있는 곳은 time 고려해서 다 들르도록 하기.
그걸 dp[거리][2] 으로 나눠서 dp[][0]은 짝수시간 최소 도달시간, dp[][1]은 홀수시간 최소도달시간 으로 함.
동생 최대 time 이내에 dp를 다 계산시킨 뒤에
마지막에 동생이 움직여서 확인하면 됨...!
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2100000000

vector<int> dong;

int dp[500001][2];

int N, K;

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	int i=1;
	while(K<=500000){
		dong.push_back(K); K+=i++;
	}
  for(i=0; i<=500000; i++){
    dp[i][0]=MAX;
    dp[i][1]=MAX;
  }
  
  // 수빈이가 갈 수 있는 곳 다 체크
	queue<pair<int, int>> q;
	q.push(make_pair(0, N));
  dp[N][0]=0;
	while(!q.empty()){
		int t=q.front().first, n=q.front().second; q.pop();
		if(t>=dong.size()) continue;

    int tt=(t+1)%2;
		if(n<500000 && dp[n-1][tt]>t+1) {
      q.push(make_pair(t+1, n-1));
      dp[n-1][tt]=t+1;
    }
    if(n>0 && dp[n+1][tt]>t+1) {
      q.push(make_pair(t+1, n+1));
      dp[n+1][tt]=t+1;
    }
		if(n>0 && n<=250000 && dp[2*n][tt]>t+1) {
      q.push(make_pair(t+1, 2*n));
      dp[2*n][tt]=t+1;
    }
	}

  // 동생이 움직였을 때 수빈이가 먼저 온 흔적이 있는지 체크
  for(i=0; i<dong.size(); i++){
    int ii=i%2;
    
    // 동생이 수빈이보다 나중에(동시에) 도착했는데 그 시간 차이가 짝수인 경우만 해당됨.
    int t_diff=i-dp[dong[i]][ii];
    if(t_diff>=0 && t_diff%2==0){
      cout<<i;
      return 0;
    }
  }

  cout<<-1;
	return 0;
}