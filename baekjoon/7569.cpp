#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> pip;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M, N, H;
  queue<pair<int, pip>> q;
  cin>>M>>N>>H;
  int tomato[H][N][M];
  int cnt_fresh=0;

  for(int i=0; i<H; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<M; k++){
        cin>>tomato[i][j][k];
        // 만약 1이면 queue에 넣고, 0이면 후레시한 토마토 개수만 확인
        if(tomato[i][j][k]==1) q.push(make_pair(0, make_pair(i, make_pair(j, k))));
        else if(tomato[i][j][k]==0) cnt_fresh++;
      }
    }
  }

  int ans=0;
  
  // 후레시한 토마토가 있을 때까지 bfs
  while(!q.empty()){
    pair<int, pip> t=q.front(); q.pop();
    
    int day=t.first, i=t.second.first, j=t.second.second.first, k=t.second.second.second;
    if(day>ans) ans=day;
    
    //여기부터는 tomato[i][j][k] 가 무조건 후레시하다는 게 전제.
    if(i+1<H && tomato[i+1][j][k]==0){
      tomato[i+1][j][k]=1; cnt_fresh--;
      q.push(make_pair(day+1, make_pair(i+1, make_pair(j, k))));
    }

    if(i>0 && tomato[i-1][j][k]==0){
      tomato[i-1][j][k]=1; cnt_fresh--;
      q.push(make_pair(day+1, make_pair(i-1, make_pair(j, k))));
    }

    if(j+1<N && tomato[i][j+1][k]==0){
      tomato[i][j+1][k]=1; cnt_fresh--;
      q.push(make_pair(day+1, make_pair(i, make_pair(j+1, k))));
    }

    if(j>0 && tomato[i][j-1][k]==0){
      tomato[i][j-1][k]=1; cnt_fresh--;
      q.push(make_pair(day+1, make_pair(i, make_pair(j-1, k))));
    }

    if(k+1<M && tomato[i][j][k+1]==0){
      tomato[i][j][k+1]=1; cnt_fresh--;
      q.push(make_pair(day+1, make_pair(i, make_pair(j, k+1))));
    }

    if(k>0 && tomato[i][j][k-1]==0){
      tomato[i][j][k-1]=1; cnt_fresh--;
      q.push(make_pair(day+1, make_pair(i, make_pair(j, k-1))));
    }
  }

  // 계산결과 출력
  if(cnt_fresh>0) {
    cout<<-1; return 0;
  }

  cout<<ans;
  return 0;
}