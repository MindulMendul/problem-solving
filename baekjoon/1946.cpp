#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.first<b.first;
	}
};

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	for(int tc=1; tc<=T; tc++){
		cin>>N;
		vector<pair<int, int>> arr(N);
		for(int i=0; i<N; i++) {
			int a, b; cin>>a>>b; arr[i]={a,b};
		}

		sort(arr.begin(), arr.end(), cmp());

		int ans=1;
		int max_second=arr[0].second;
		for(int i=1; i<N; i++){
			if(max_second>arr[i].second) {
				max_second=arr[i].second;
				ans++;
			} 
		}

		cout<<ans<<'\n';
	}

	return 0;
}

