#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long int> v;

bool is_good(int ind){
	int s=0, e=v.size()-1;
	while(s<e){
		if(s==ind) {s++; continue;}
		if(e==ind) {e--; continue;}
		long long int sum=v[s]+v[e];
		if(sum==v[ind]) return true;
		else if(sum<v[ind]) s++;
		else e--;
	}
	return false;
}

int main() {
	//freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i=0; i<N; i++){
		long long int a; cin>>a; v.push_back(a);
	}
	sort(v.begin(), v.end());

	int ans=0;
	for(int ind=0; ind<v.size(); ind++){
		if(is_good(ind)) ans++;
	}
	
	cout<<ans;
	return 0;
}