#include <iostream>
#include <vector>

using namespace std;

vector<long long int> prime(664579);

void sieve(){
	vector<int> eratosthenes(10'000'001, 0);
	eratosthenes[0]=1;
	eratosthenes[1]=1;
	int cnt=1; prime[0]=2;
	for(int n=3; n*n<10'000'000; n+=2){
		if(eratosthenes[n]==1) continue;
		for(int nn=n*n; nn<10'000'000; nn+=n*2){
			eratosthenes[nn]=1;
		}
	}
	for(int n=3; n<10'000'000; n+=2){
		if(eratosthenes[n]==0) prime[cnt++]=(long long int)n;
	}

	prime.resize(cnt);
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	// init
	long long int A, B, ans=0;
	cin>>A>>B;
	
	sieve();

	for(long long int p:prime){
		long long int pp=p*p;
		while(pp<=B){
			if(A<=pp) ans++;
			if (pp>B/p) break;
			pp*=p;
		}
	}
	cout<<ans;

  return 0;
}