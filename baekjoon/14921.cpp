#include <iostream>

using namespace std;

int N;
int arr[100'001];

int abs(int x){return x>=0?x:-x;}

int main() {
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i=0; i<N; i++)cin>>arr[i];
	int s=0, e=N-1, ans=2'100'000'000;
	while(s<e){
		int sum=arr[s]+arr[e];
		if(sum==0) {cout<<0; return 0;}
		else {
			if(abs(ans)>abs(sum)) ans=sum;
			if(sum<0) s++;
			else e--;
		}
	}
	cout<<ans;
	return 0;
}