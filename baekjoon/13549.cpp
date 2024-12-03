// https://www.acmicpc.net/source/87138902

#include <iostream>
#include <queue>

#define MAX 200'000

using namespace std;

int dp[MAX];

struct cmp{
	bool operator()(pair<int, int> a, pair<int, int> b){
		if(a.first==b.first) return a.second>b.second;
		return a.first>b.first;
	}
};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K; cin>>N>>K;
	if(N>=K) {cout<<(N-K); return 0;}
	// N<K 임이 보장됨
	
	for(int i=0; i<MAX; i++){dp[i]=MAX;}
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	q.push(make_pair(0, N));
	while(!q.empty()){
		pair<int, int> t=q.top(); q.pop();
		int cnt=t.first, ind=t.second;
		if(cnt<dp[ind]) {dp[ind]=cnt;}
		if(ind*2<=MAX && cnt<dp[ind*2]) q.push(make_pair(cnt, ind*2));
		if(ind+1<=MAX && cnt+1<dp[ind+1]) q.push(make_pair(cnt+1, ind+1));
		if(ind>0 && cnt+1<dp[ind-1]) q.push(make_pair(cnt+1, ind-1));
	}
	cout<<dp[K];

  return 0;
}
