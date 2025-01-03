// 해당 문제는 단순 구현으로 풀면 됨.
// 주사위 굴리는 방향을 잘 맞춰서 값이 틀어지지 않게만 손보면 끝
// 또, 문제의 조건에 맞게 바닥면 숫자 복사하는 것도 구현하면 됨

// 주의할 점은, 문제의 조건이 조금 이상함.
// (x,y) 에서, x가 세로고, y가 가로로 주어짐
// 그것만 주의해서 잘 보면 어렵지 않게 풀 수 있는 문제

#include <iostream>
#include <vector>

using namespace std;

vector<int> dice={0,0,0,0,0,0};
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};

// 방향에 맞게 주사위 값을 돌리는 함수
void rollDice(int dir){
	int dice_0=dice[0];
	switch(dir){
		case 1: // right
			dice[0]=dice[4]; dice[4]=dice[5]; dice[5]=dice[2]; dice[2]=dice_0;
		break;
		case 2: // left
			dice[0]=dice[2]; dice[2]=dice[5]; dice[5]=dice[4]; dice[4]=dice_0;
		break;
		case 3: // up
			dice[0]=dice[1]; dice[1]=dice[5]; dice[5]=dice[3]; dice[3]=dice_0;
		break;
		case 4: // down
			dice[0]=dice[3]; dice[3]=dice[5]; dice[5]=dice[1]; dice[1]=dice_0;
		break;
	}
}

// 바닥면에 숫자 복사하는 함수
void copyFloor(int x, int y, vector<vector<int>>& field){
	if(field[y][x]==0) field[y][x]=dice[5];
	else {dice[5]=field[y][x]; field[y][x]=0;}
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	// init
	int N, M, x, y, K;
	cin>>N>>M>>y>>x>>K;
	vector<vector<int>> field(N, vector<int>(M));
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>field[i][j];

	// K번 만큼 명령어 수행
	for(int cmd=0; cmd<K; cmd++){
		int d; cin>>d; // 이동할 방향 지정
		int xx=x+dx[d], yy=y+dy[d]; // 이동할 좌표 지정
		if(xx<0 || xx>=M || yy<0 || yy>=N) continue; // 범위를 벗어나면 명령어 스킵
		x=xx; y=yy; // 범위 안이면 좌표를 이동
		rollDice(d); // 이동한 방향으로 주사위를 돌리는 함수
		copyFloor(x, y, field); // 바닥면 복사 함수
		cout<<dice[0]<<'\n'; // 주사위 맨 위 출력
	}
	
  return 0;
}