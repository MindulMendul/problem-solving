#include <iostream>
#include <vector>
#include <queue>

#define MAX 2100000000

using namespace std;

int N, K;

int subin[100'001];
int ex_subin[100'001];

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	for(int i=0; i<=100000; i++) {
		subin[i]=MAX;
		ex_subin[i]=MAX;
	}
	
	queue<pair<int, int>> q;
	q.push({N, 0});
	subin[N]=0;
	while(!q.empty()){
		int x=q.front().first, time=q.front().second; q.pop();
		if(x==K){
			break;
		}
		if(x-1>=0 && subin[x-1]>time+1){
			subin[x-1]=time+1;
			ex_subin[x-1]=x;
			q.push({x-1, time+1});
		}
		if(x+1<=100'000 && subin[x+1]>time+1){
			subin[x+1]=time+1;
			ex_subin[x+1]=x;
			q.push({x+1, time+1});
		}
		if(x*2<=100'000 && subin[x*2]>time+1){
			subin[x*2]=time+1;
			ex_subin[x*2]=x;
			q.push({x*2, time+1});
		}
	}
	cout<<subin[K]<<"\n";
	vector<int> path;
	for(int i=K; i!=N; i=ex_subin[i]){
		path.push_back(i);
	}
	path.push_back(N);
	for(int i=path.size()-1; i>=0; i--){
		cout<<path[i]<<" ";
	}
	return 0;
}
