#include <iostream>
#include <vector>

using namespace std;

int N;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

// 동작 시 숫자 합치기
void join(vector<vector<int>> &b, int i, int j, int d){
	if(b[i][j]==0) return;
	int xx=j-dx[d], yy=i-dy[d];
	while(xx>=0 && xx<N && yy>=0 && yy<N){
		if(b[yy][xx]>0){
			if(b[i][j]==b[yy][xx]){
				b[i][j]+=b[yy][xx];
				b[yy][xx]=0;
			}
			break;
		}
		xx-=dx[d]; yy-=dy[d];
	}
}

// 동작 시 숫자 움직이기
void move(vector<vector<int>> &b, int i, int j, int d){
	if(b[i][j]==0) return;
	int xx=j, yy=i;
	while(xx+dx[d]>=0 && xx+dx[d]<N && yy+dy[d]>=0 && yy+dy[d]<N){
		if(b[yy+dy[d]][xx+dx[d]]!=0) break;
		xx+=dx[d], yy+=dy[d];
	}
	if(xx==j && yy==i) return;
	b[yy][xx]=b[i][j];
	if(!(xx==i && yy==j))b[i][j]=0;
}

// 슬라이드 동작
vector<vector<int>> cmd(vector<vector<int>> res, int d){
	// 병합할 숫자를 먼저 잘 합쳐준 뒤에 숫자를 움직여야 함
	// 숫자 병합과 움직임은 방향쪽에 제일 가까운 부분부터 움직여야 함
	// ex) -> 방향이면 서치는   5 4 3 2 1  순서로 해야 함

	if(d==0){
		for(int j=N-1; j>=0; j--) for(int i=0; i<N; i++) join(res, i, j, d);
		for(int j=N-1; j>=0; j--) for(int i=0; i<N; i++) move(res, i, j, d);
	}
	else if(d==1){
		for(int i=N-1; i>=0; i--) for(int j=0; j<N; j++) join(res, i, j, d);
		for(int i=N-1; i>=0; i--) for(int j=0; j<N; j++) move(res, i, j, d);
	}
	else if(d==2){
		for(int j=0; j<N; j++) for(int i=0; i<N; i++) join(res, i, j, d);
		for(int j=0; j<N; j++) for(int i=0; i<N; i++)	move(res, i, j, d);
	}
	else if(d==3){
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) join(res, i, j, d);
		for(int i=0; i<N; i++) for(int j=0; j<N; j++)	move(res, i, j, d);
	}

	return res;
}

// 각 보드판 중에서 제일 큰 숫자 찾기
int getScore(vector<vector<int>>& board){
	int ans=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(ans<board[i][j])ans=board[i][j];
		}
	}
	return ans;
}

// 각각의 방향 마다 cmd를 입력해서 제일 높은 점수 찾기
int dfs(vector<vector<int>> board, int cnt){
	if(cnt==5) return getScore(board);
	int ans=0;
	for(int d=0; d<4; d++){
		int score=dfs(cmd(board, d), cnt+1);
		if(ans<score) ans=score;
	}
	return ans;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	//init
	cin>>N;
	vector<vector<int>> board;
	for(int i=0; i<N; i++){
		vector<int> v;
		for(int j=0; j<N; j++){
			int e; cin>>e;
			v.push_back(e);
		}
		board.push_back(v);
	}

	//calculate
	cout<<dfs(board, 0);

  return 0;
}