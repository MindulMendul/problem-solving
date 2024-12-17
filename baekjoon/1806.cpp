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
