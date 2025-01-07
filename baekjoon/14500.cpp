// 이건 설명 필요없이 그냥 빡구현하면 됨.

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> tetris[19];

// 테트리미노가 해당 위치에서 몇 점을 먹는지 체크
int getScore(vector<vector<int>>& field, vector<vector<int>>& tet, int x, int y){
	int res=0;
	for(int i=0; i<tet.size(); i++){
		for(int j=0; j<tet[0].size(); j++){
			 if(tet[i][j]) res+=field[y+i][x+j];
		}
	}
	return res;
}

// 테트리미노로 얻는 점수를 모두 탐색함
int search(vector<vector<int>>& field, vector<vector<int>>& tet){
	int res=0;
	for(int i=0; i<=field.size()-tet.size(); i++){
		for(int j=0; j<=field[0].size()-tet[0].size(); j++){
			int score=getScore(field, tet, j, i);
			if(res<score) res=score;
		}
	}
	return res;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	// init
	int N, M; cin>>N>>M;
	vector<vector<int>> field(N, vector<int>(M));
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>field[i][j];

  // 가능한 테트리미노 모양을 모두 저장함
	tetris[0].push_back({1});
	tetris[0].push_back({1});
	tetris[0].push_back({1});
	tetris[0].push_back({1});

	tetris[1].push_back({1,1,1,1});

	tetris[2].push_back({1,1});
	tetris[2].push_back({1,1});

	tetris[3].push_back({1,0});
	tetris[3].push_back({1,0});
	tetris[3].push_back({1,1});

	tetris[4].push_back({0,1});
	tetris[4].push_back({0,1});
	tetris[4].push_back({1,1});

	tetris[5].push_back({1,1});
	tetris[5].push_back({1,0});
	tetris[5].push_back({1,0});

	tetris[6].push_back({1,1});
	tetris[6].push_back({0,1});
	tetris[6].push_back({0,1});

	tetris[7].push_back({1,1,1});
	tetris[7].push_back({1,0,0});

	tetris[8].push_back({1,1,1});
	tetris[8].push_back({0,0,1});

	tetris[9].push_back({1,0,0});
	tetris[9].push_back({1,1,1});

	tetris[10].push_back({0,0,1});
	tetris[10].push_back({1,1,1});

	tetris[11].push_back({1,0});
	tetris[11].push_back({1,1});
	tetris[11].push_back({0,1});

	tetris[12].push_back({0,1});
	tetris[12].push_back({1,1});
	tetris[12].push_back({1,0});

	tetris[13].push_back({0,1,1});
	tetris[13].push_back({1,1,0});

	tetris[14].push_back({1,1,0});
	tetris[14].push_back({0,1,1});

	tetris[15].push_back({0,1});
	tetris[15].push_back({1,1});
	tetris[15].push_back({0,1});

	tetris[16].push_back({1,0});
	tetris[16].push_back({1,1});
	tetris[16].push_back({1,0});

	tetris[17].push_back({0,1,0});
	tetris[17].push_back({1,1,1});

	tetris[18].push_back({1,1,1});
	tetris[18].push_back({0,1,0});

	int ans=0;
  // 테트리미노를 모두 다 전수조사해서 점수를 찾음
	for(int i=0; i<19; i++) {
		int score=search(field, tetris[i]);
		if(ans<score) ans=score;
	}
	cout<<ans;

  return 0;
}