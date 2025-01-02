// https://www.acmicpc.net/problem/14503
// field 0: 청소 안 된 곳
// field 1: 벽
// field 2: 청소 된 곳

// 단순 구현 문제기 때문에
// 4방향 서치하는 동안 field 값의 상태를 확인하여
// 순서에 따라 알고리듬을 구현
// clean 코드에 문제의 조건에 맞는 순서를 작성

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ans, N, M, x, y, d;
int field[50][50];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

void clean(){
	// 로봇 청소기가 멈출 때까지 무한 반복
	while(true){
		// 1.
		// 만약 자리에 청소가 안 되어 있다면 청소하고 ans 값을 1 올림
		if(field[y][x]==0){
			field[y][x]=2; ans++;
		}

		// 2.
		bool flag=false; // 만약 4방향 서치를 했는데 발견하면 굳이 3번 코드로 넘어갈 이유가 x
		for(int dd=0; dd<4; dd++){
			int dir=(dd+d)%4; // dir 방향으로 주변 4칸 서치
			int xx=x+dx[dir], yy=y+dy[dir]; // 4칸 서치할 좌표
			if(xx<0 || xx>=M || yy<0 || yy>=N) continue; // 범위 밖으로 나가면 해당사항 x
			if(field[yy][xx]>0) continue; // 청소가 되어있거나, 벽이 있다면 해당사항 x

			// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸을 발견
			d=(d+3)%4; // 반드시 0,1,2,3 이 되도록 반시계 90도 도는 코드
			if(field[y+dy[d]][x+dx[d]]==0) {x+=dx[d]; y+=dy[d];}
			flag=true; break;
		}
		if(flag) continue; // 2번에서 서치 성공했다면 굳이 3번으로 넘어갈 이유가 x

		// 3. 
		int xx=x-dx[d], yy=y-dy[d]; // 후진할 공간 서치할 좌표
		if(xx<0 || xx>=M || yy<0 || yy>=N) break; // 범위 벗어나면 로봇 청소기 멈춤
		if(field[yy][xx]==1) break; // 벽이 있다면 로봇 청소기 멈춤
		x=xx; y=yy; // 벽이 없다면 이동해도 됨
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	// init
	ans=0;
	cin>>N>>M>>y>>x>>d;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>field[i][j]; // 초기화
		}
	}

	// calculate
	clean();
	cout<<ans; // 결과 출력

  return 0;
}