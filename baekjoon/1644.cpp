#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> prime, ans;

int isPrime(int num){
	for(int i=0; i<prime.size(); i++){
		if(prime[i]*prime[i]>num) return true;
		if(num%prime[i]==0) return false;
	}
	return true;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N; prime.push_back(2);
	for(int i=3; i<4'000'000; i++){
		if(isPrime(i)) {
			prime.push_back(i);
		}
	}

	// for(auto e: prime){
	// 	cout<<e<<" ";
	// }cout<<endl;

	int s=0, e=0, sum=0;
	while(s<N){
		//if(s>280000)cout<<s<<"("<<prime[s]<<") / "<<e<<"("<<prime[e]<<") "<<sum<<endl;
		if(s==e){sum+=prime[e++]; continue;}
		if(sum<=N){
			if(sum==N){
				ans.push_back(1);
			}
			sum+=prime[e++];
			if(e>prime.size()) break;
		} else {
			if(prime[s]>N) break;
			sum-=prime[s++];
		}
	}

	cout<<ans.size();
  return 0;
}
