/// 7579.cpp
/// 기본적으로 1-0 knapsack 문제인 듯
// 푸는 방법은 dp로 알려져있으니 그걸 이용하면 되겠다.
// 개수가 적으니까 정렬해서 cost==0 인 애들을 먼저 추려서 더해주었고
// 추렸는데 정답보다 커지면 거기서 종료
// 아직 해야하면 거기서부터 1-0 knapsack 풀면 되겠다.

/// 1-0 knapsack 푸는 방법
// dp[ind][memory] 로 메모이제이션할거얌~
// dp[ind][memory] 의 값은 ind를 넣지 않은 경우 or ind를 넣은 경우 무게를 비교해서 더 cost가 낮은 값을 저장할 예정 
// dp[ind][memory]=min(dp[ind-1][memory], mem[ind](cost)+dp[memory-mem[ind](mem)]);
/// 근데 문제가 있음.
// 이거 memory<=10'000'000 인데? 그러면 이거 ind<=100이니까 연산 불가능함.
// 1-0 knapsack 보다 더 좋은 방법을 찾아야겠는데...??

// 그렇다면, cost를 기준으로 풀 수는 없을까?
// dp[ind][cost] 로 메모이제이션해서 cost로 쓸 수 있는 가장 최대값을 저장하는 식으로 해보자.
// 즉, dp[ind][cost]는 mem[ind](cost, memory) 에 대해서 기존의 값과 비교하여 더 최적해를 찾는 dp인 거지
// dp[ind][cost]=최대값(mem[ind]를 넣지 않았을 때, mem[ind]를 넣고 계산한 최적해)
// dp[ind][cost]=max(dp[ind-1][cost], mem[ind](memory)+dp[ind-1][cost-mem[ind](cost)])
// 이러면 dp[ind][cost] 를 cost 별로 순서대로 돌렸을 떄 dp>=M 가 되는 최초의 지점이 정답이 됨.

// 주의 ) 만약 내가 배열의 크기를 바꿨으면, 크기도 그만큼 바뀌었다는 걸 반영하도록 해야 한다.
// 그러니까 예를 들어 N을 받아서 배열을 만들었는데,
// 나중에 그 배열의 크기가 바뀌면 N값도 그만큼 감산해서 계산해야 한다.

#include <iostream>
#include <vector>

using namespace std;

// cost, memory
typedef pair<int, int> cm;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, sum=0;
  cin>>N>>M;

  vector<cm> mem(N);
  for(int i=0; i<N; i++) cin>>mem[i].second;
  for(int i=0; i<N; i++) {cin>>mem[i].first; sum+=mem[i].first;}
  
  // B.C.) dp[0][cost]=(mem[ind].cost>=cost)?mem[ind].memory:0;
  // dp[ind][cost]=max(dp[ind-1][cost], mem[ind](memory)+dp[ind-1][cost-mem[ind](cost)])
  vector<vector<int>> dp(N, vector<int>(sum+1, 0));

  for(int c=mem[0].first; c<=sum; c++){
    dp[0][c]=mem[0].second;
  }

  for(int i=1; i<N; i++){
    for(int c=0; c<=sum; c++){
      if(c<mem[i].first)
        dp[i][c]=dp[i-1][c];
      else 
        dp[i][c]=max(dp[i-1][c], mem[i].second+dp[i-1][c-mem[i].first]);
    }
  }
  
  for(int c=0; c<=sum; c++){
    if(dp[N-1][c]>=M){
      cout<<c; return 0;
    }
  }
}
