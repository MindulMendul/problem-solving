#include <iostream>

using namespace std;

long long int N, B, C;
long long int ans;
long long int ramen[1'000'002];

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>B>>C; ans=0;
	for (int i = 0; i < N; i++) {
		cin>>ramen[i];
		ans+=ramen[i];
	}

	if(B<=C) {
		// B<=C 인 경우에는 굳이 C로 가격을 쳐줄 이유가 없음.
		// 즉, 모든 라면을 B로 쳐서 결제하면 됨.
		ans*=B;
	} else {
		long long int cur=0;
		ans=0;
		while(cur<N){
			// 해당 공장에 라면이 없으면 넘기기
			if(ramen[cur]==0){
				cur++;
				continue;
			}

			// 다음 공장이 없으면 지금 라면만 사기
			// 다음 공장에 라면이 없으면 지금 공장에서만 사기
			if(cur+1>=N || (cur+1<N && ramen[cur+1]==0)){
				ans+=ramen[cur]*B;
				cur+=2;
				continue;
			}

			//다다음 공장이 없으면 지금 + 다음 공장에서만 다 사기
			// 다다음 공장에 라면이 없으면 지금 + 다음 공장에서만 다 사기
			if(cur+2>=N || (cur+2<N && ramen[cur+2]==0)){
				if(ramen[cur]>=ramen[cur+1]){
					ans+=ramen[cur+1]*C+ramen[cur]*B;
				} else {
					ans+=ramen[cur]*C+ramen[cur+1]*B;
				}
				cur+=3;
				continue;
			}

			// 다다음 공장에 라면이 있으면 다 사기
			long long int _min;
			if(ramen[cur+1]>ramen[cur+2]){
				// cur+1>cur+2 이면 2개 사기가 더 이득임
				_min=min(ramen[cur], ramen[cur+1]-ramen[cur+2]);
				ans+=_min*(B+C);
				ramen[cur]-=_min; ramen[cur+1]-=_min;
			} else {
				// 아니라면 3개 사기가 이득임
				_min=min(ramen[cur], min(ramen[cur+1], ramen[cur+2]));
				ans+=_min*(B+2*C);
				ramen[cur]-=_min; ramen[cur+1]-=_min; ramen[cur+2]-=_min;
			}
			
			
		}
	} 
	cout<<ans;

  return 0;
}