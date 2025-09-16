// 이분탐색 문제
// 최대 거리의 최소값이면, "거리"라는 걸 이분탐색으로 구하면 되지 않을까? 애서 출발.
// 최대 거리가 mid로 상정하고, 이걸 기준으로 설치했다고 가정했을 때,
// 설치가 되면 ans=mid 로 저장하고 mid를 늘려서
// 설치가 안 됐을 때는 mid를 줄여서
// 계속 이분탐색하는 거임!

// 그러면 mid일 때 설치가 가능한지는 어떻게 앎?
// 전 구간에다가 mid 간격으로 설치를 했을 떄, 설치 갯수를 세어서
// M보다 작거나 같으면 길이를 줄여야 하고 (널널하게 설치한 거니까 조금 더 빡빡하게 설치해야지)
// M보다 크면 길이를 늘려야 하고 (빡빡하게 설치한 거니까 조금 더 널널하게 설치해야지)
// 이런 식으로 이분탐색을 진행하면 된다!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;
vector<int> point;

bool need_longer(int mid){
	int cnt=0;
	for(int i=0; i<point.size()-1; i++){
		int dis=point[i+1]-point[i];
		cnt+=dis/mid;
		if(dis%mid==0) cnt--;
	}

	return cnt>M;
}

int main() {
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>L;
	point.push_back(0);
	point.push_back(L);
	for(int i=0; i<N; i++) {
		int a; cin>>a;
		point.push_back(a);
	}
	sort(point.begin(), point.end());
	
	int ans=0;
	int s=1, e=L;
	while(s<=e){
		int mid=(s+e)/2;
		if(need_longer(mid)){
			s=mid+1;
		} else {
			ans=mid;
			e=mid-1;
		}
	}
	
	cout<<ans;

	return 0;
}