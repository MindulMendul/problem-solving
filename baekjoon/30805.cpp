#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b){
		if(a.first!=b.first) return a.first>b.first;
		return a.second<b.second;
	}
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	//init
	int N, M;
	vector<pair<int, int>> a, b;
	cin>>N; for(int i=0; i<N; i++){ int tmp; cin>>tmp; a.push_back(make_pair(tmp, i)); }
	cin>>M; for(int i=0; i<M; i++){ int tmp; cin>>tmp; b.push_back(make_pair(tmp, i)); }

	sort(a.begin(), a.end(), cmp());
	sort(b.begin(), b.end(), cmp());

	vector<int> ans;
	while(a.size()>0 && b.size()>0){
		while(a.size()>0 && b.size()>0 && a[0].first!=b[0].first){
			if(a[0].first>b[0].first){
				a.erase(a.begin());
			} else {
				b.erase(b.begin());
			}
		}
		
		if(a.size()==0 || b.size()==0) break;
		
		ans.push_back(a[0].first);
		for(int i=a.size()-1; i>0; i--){
			if(a[0].second>a[i].second) a.erase(a.begin()+i);
		}
		for(int i=b.size()-1; i>0; i--){
			if(b[0].second>b[i].second) b.erase(b.begin()+i);
		}
		a.erase(a.begin());
		b.erase(b.begin());
	}

	cout<<ans.size()<<'\n';
	for(auto e:ans){
		cout<<e<<" ";
	}

  return 0;
}