#include <iostream>
#include <vector>

using namespace std;

#define MAX 2000000000

long long int N;
vector<long long int> A;
vector<long long int> S;

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	A.push_back(0); A.push_back(1);
	S.push_back(0); S.push_back(1);
	int i=1;
	while(S[i]<N) {
		i++;
		long long int A_next=1+A[i-A[A[i-1]]];
		A.push_back(A_next);
		S.push_back(S[i-1]+A_next);
	}
	cout<<i;
	
	return 0;
}
