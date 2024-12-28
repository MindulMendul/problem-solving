#include <iostream>
#include <queue>

#define MAX 2100000000

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int ladder, snake;
  cin>>ladder>>snake;

	int pan[110];
	int visited[110];

	// basic
	for(int i=0; i<110; i++){pan[i]=i; visited[i]=MAX;}

	//ladder
	for(int i=0; i<ladder; i++){
		int x,y; cin>>x>>y;
		pan[x]=y;
		
	}

	//snake
	for(int i=0; i<snake; i++){
		int u,v; cin>>u>>v;
		pan[u]=v;
	}

	//bfs
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	while(!q.empty()){
		pair<int, int> t=q.front(); q.pop();
		if(t.first>100 || t.first==0) continue;
		if(t.first==100) {cout<<t.second; break;}

		if(visited[pan[t.first+1]]>t.second+1){
			q.push(make_pair(pan[t.first+1], t.second+1));
			visited[pan[t.first+1]]=t.second+1;
		}
		if(visited[pan[t.first+2]]>t.second+1){
			q.push(make_pair(pan[t.first+2], t.second+1));
			visited[pan[t.first+2]]=t.second+1;
		}
		if(visited[pan[t.first+3]]>t.second+1){
			q.push(make_pair(pan[t.first+3], t.second+1));
			visited[pan[t.first+3]]=t.second+1;
		}
		if(visited[pan[t.first+4]]>t.second+1){
			q.push(make_pair(pan[t.first+4], t.second+1));
			visited[pan[t.first+4]]=t.second+1;
		}
		if(visited[pan[t.first+5]]>t.second+1){
			q.push(make_pair(pan[t.first+5], t.second+1));
			visited[pan[t.first+5]]=t.second+1;
		}
		if(visited[pan[t.first+6]]>t.second+1){
			q.push(make_pair(pan[t.first+6], t.second+1));
			visited[pan[t.first+6]]=t.second+1;
		}
	}

  return 0;
}