// lad 0: 빈 거
// lad 1: 다리가 있는 거
// lad -1 이하: 다리를 둘 수 없는 거
// 다리를 놓을 수 있는 조건은 반드시 해당 자리가 0이어야 함
// 또한, 다리를 철거해도 여전히 놓을 수 없는 자리가 있을 수 있으므로
// -1은 쌓일 수 있다는 점을 응용.

// 알고리듬 분석.
// 0. 최대 다리를 3개 놓을 수 있도록 완전 탐색을 하는 방법을 짜면 됨.
// 1. 다리를 놓는다.
// 2. 각 위치에 따라 내려가본다.
// 3. 모든 위치가 제대로 내려왔다면 해당 다리 개수를 반환한다.
// 4. 만약 어디에도 가능하지 않다면 -1을 출력한다.

// 문제 풀다가 한 가지 허점 발견..
// 3번에서, 바로 해당 다리 개수를 반환하면 안 됨.
// 해당 값은 여전히 후보지고, 더 작은 값이 가능하면 그 값으로 바꾸어야 함 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, H;

// 다리 만들어주는 함수
void makeDari(vector<vector<int>>& lad, int x, int y){
  lad[y][x]=1;
  if(x>0 && lad[y][x-1]<1) lad[y][x-1]--;
  if(x<N-2 && lad[y][x+1]<1) lad[y][x+1]--;
}

// 다리 제거하는 함수
void removeDari(vector<vector<int>>& lad, int x, int y){
  lad[y][x]=0;
  if(x>0 && lad[y][x-1]<0) lad[y][x-1]++;
  if(x<N-2 && lad[y][x+1]<0) lad[y][x+1]++;
}

// ind 가 제대로 ind에 도착하는지 확인하는 함수
int goTarget(vector<vector<int>>& lad, int ind){
  int res=ind, dep=0;
  while(dep<H){
    if(res>0 && lad[dep][res-1]==1) res--;
    else if(res<N-1 && lad[dep][res]==1) res++;
    dep++;
  }
  return res==ind;
}

// 모든 ind가 제대로 도착하는지 확인하는 함수
bool checkLadder(vector<vector<int>>& lad){
  for(int i=0; i<N; i++) if(!goTarget(lad, i)) return false;
  return true;
}

// 디버깅용 레더 출력 함수
void printLadder(vector<vector<int>>& lad){
  for(int i=0; i<H; i++){
    for(int j=0; j<N-1; j++){
      cout<<lad[i][j]<<" ";
    }cout<<endl;
  }cout<<endl;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M>>H;
  vector<vector<int>> ladder(H, vector<int>(N-1, 0));

  for(int i=0; i<M; i++){
    int x, y; cin>>y>>x;
    makeDari(ladder, x-1, y-1);
  }
  //printLadder(ladder);
  
  // 다리를 한 개도 안 놓았는데 정답이면 0 출력하고 끝.
  if(checkLadder(ladder)) {
    //printLadder(ladder);
    cout<<0; return 0;
  }

  // 다리를 놓을 수 있는 후보지는 총 (N-1)*H 개.
  // 그것을 하나하나 ind로 분석하여 백트래킹 시도
  // 2차원 배열을 1차원 배열로 바꾸는 트릭을 이용하여 인덱싱함.
  int ans=4;
  for(int i=0; i<(N-1)*H; i++){
    int x1=i/H, y1=i%H;
    if(ladder[y1][x1]!=0) continue;
    makeDari(ladder, x1, y1);
    if(checkLadder(ladder)) {
      //printLadder(ladder);
      if(ans>1)ans=1;
    }

    for(int j=i+1; j<(N-1)*H; j++){
      int x2=j/H, y2=j%H;
      if(ladder[y2][x2]!=0) continue;
      makeDari(ladder, x2, y2);
      if(checkLadder(ladder)) {
       // printLadder(ladder);
        if(ans>2)ans=2;
      }

      for(int k=j+1; k<(N-1)*H; k++){
        int x3=k/H, y3=k%H;
        if(ladder[y3][x3]!=0) continue;
        makeDari(ladder, x3, y3);
        if(checkLadder(ladder)) {
          //printLadder(ladder);
          if(ans>3)ans=3;
        }
        removeDari(ladder, x3, y3);
      }

      removeDari(ladder, x2, y2);
    }

    removeDari(ladder, x1, y1);
  }
  
  // ans가 여전히 3 이하로 나오지 않으면 -1 출력.
  if(ans<4) cout<<ans;
  else cout<<-1;
  return 0;
}
