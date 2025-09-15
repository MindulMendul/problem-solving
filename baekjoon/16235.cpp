#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int N, M, K;
int map[10][10];
int A[10][10];
deque<int> tree[10][10];
deque<int> next_tree[10][10];

void print_answer(){
	int ans=0;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) ans+=tree[i][j].size();
	cout<<ans;
}

int main() {
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>K;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
		cin>>A[i][j];
		map[i][j]=5;
	}
	for(int i=0; i<M; i++){
		int x, y, z;
		cin>>y>>x>>z;
		tree[y-1][x-1].push_back(z);
	}

	for(int tc=1; tc<=K; tc++){
		// 봄
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
			int dead=0;
			while(!tree[i][j].empty()){
				int z=tree[i][j].front(); tree[i][j].pop_front();
				if(map[i][j]>=z) {
					map[i][j]-=z;
					z+=1;
					if(z%5==0) {
						// 가을
						for(int d=0; d<8; d++){
							int xx=j+dx[d], yy=i+dy[d];
							if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
							next_tree[yy][xx].push_front(1);
						}
					}
					next_tree[i][j].push_back(z);
				} else {
					// 여름
					dead+=z/2;
				}
			}
			map[i][j]+=dead;
		}

		// 겨울
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
			deque<int> new_deque;
			tree[i][j]=next_tree[i][j];
			next_tree[i][j]=new_deque;
		}

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				map[i][j]+=A[i][j];
			}
		}
	}

	print_answer();

	return 0;
}