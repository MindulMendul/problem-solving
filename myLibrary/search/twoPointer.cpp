// #1806 번 문제
// s, e 를 잡고
// 조건에 부합하지 않으면 e를 늘리고
// 조건에 부합하면 s를 당기는 방식으로 구현
// 첫 조건은 s==e 일 때 e++로 e를 밀어서 구현하고
// 마지막 조건은 e>=N일 때 조건에 부합할 때까지 s를 당기면 됨

#include <iostream>

using namespace std;

int N, S;
int elem[100'001];

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>S;
	for(int i=0; i<N; i++){
		cin>>elem[i];
	}

	int s=0, e=0, sum=0, ans=100'001;
	while(s<N){
		if(s==e || sum<S){
			if(e>=N) break;
			sum+=elem[e++];
		} else {
			if(e-s<ans){ans=e-s;}
			sum-=elem[s++];
		}
	}

	if(ans<100'001) cout<<ans;
	else cout<<0;

  return 0;
}
