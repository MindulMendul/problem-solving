#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int _min, _max;
vector<long long int> square;
bool visited[1'000'001];

void search(){
	if(_max<4) return;
	for(long long int d=0; d<floor(sqrt(_max))-1; d++){
		long long int num=(_min/square[d])*square[d]; // 초기값
		if(num<_min) num+=square[d];
		while(num<=_max){
			visited[num-_min]=true;
			num+=square[d];
		}
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	//init
	cin>>_min>>_max;
	for(long long int i=2; i<=1'000'000; i++) square.push_back(i*i);
	for(int i=0; i<1'000'000; i++) visited[i]=false;
	
	search();

	int ans=_max-_min+1;
	for(int i=0; i<=1'000'000; i++) if(visited[i]) ans--;
	cout<<ans;

  return 0;
}