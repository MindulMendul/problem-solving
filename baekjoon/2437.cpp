#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	//init
	int N; cin>>N;
	vector<int> v;
	for(int i=0; i<N; i++){
		int e; cin>>e;
		v.push_back(e);
	}
	sort(v.begin(), v.end());

	int sum=0;
	for(int i=0; i<N; i++){
		int elem=v[i];
		if(sum+1<elem) {
			cout<<sum+1;
			return 0;
		}
		sum+=elem;
	}
	
	cout<<sum+1;
  return 0;
}