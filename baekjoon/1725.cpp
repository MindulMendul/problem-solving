#include <iostream>
#include <stack>

using namespace std;

typedef long long int lli;

int N;
lli arr[100'001];

int main() {
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	lli ans=0;
	for(int i=0; i<N; i++) cin>>arr[i];
	arr[N]=0;
	stack<lli> stack;
	for(int i=0; i<=N+1; i++){
		while(stack.size()>0 && arr[stack.top()]>arr[i]){
			lli sero=arr[stack.top()];
			stack.pop();
			lli garo=stack.empty()?i:(i-1-stack.top());
			lli rec=garo*sero;
			if(ans<rec) ans=rec;
		}
		stack.push(i);
	}

	cout<<ans<<'\n';
	return 0;
}