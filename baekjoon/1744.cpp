#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N; cin>>N;
  vector<long long int> v(N);
  for(int i=0; i<N; i++) cin>>v[i];
	if(N==1){cout<<v[0]; return 0;}
	if(N==2){cout<<max(v[0]*v[1], v[0]+v[1]); return 0;}
	
	sort(v.begin(), v.end());
	
	long long int ans=0;
  int s=0, e=N-1;
	while(s<N-2 && v[s]<0 && v[s+1]<0){
		ans+=v[s]*v[s+1]; s+=2;
	}
	while(e>2 && s<e-2){
		ans+=max(v[e]*v[e-1], v[e]+v[e-1]); e-=2;
	}

	if(e-s==1){
		ans+=max(v[e]*v[e-1], v[e]+v[e-1]);
	} else if(e==s){
		ans+=v[s];
	} else {
		ans+=max(v[s]+v[s+1]+v[s+2], max(v[s]*v[s+1]+v[s+2], v[s]+v[s+1]*v[s+2]));
	}

	cout<<ans;

  return 0;
}
