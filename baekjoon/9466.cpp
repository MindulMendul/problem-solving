/// 사이클을 찾으면 되는 문제
// 다 돌아서 사이클이 되는 지점이 있다면, 그 사이클에 해당하는 숫자를 후보지에서 지우면 되는 식으로 구현
// visited=0 으로 초기화
// 탐색을 시작한 곳 i에서, visited[i]=0 이면 visited[i]=1 로 하고 다음을 탐색함
// 탐색한 곳이 visited[i]=1 이면 visited[i]=2로 하고 다음을 탐색함
// 탐색한 곳이 visited[i]=2 이면 탐색을 다시 시도하고, visited[i]=2가 나올 때까지 visited[i]=1 인 곳을 -1로 변경함
// visited[i]=-1 의 개수가 정답

#include <iostream>

using namespace std;

int student[100'001];
int visited[100'001];

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin>>T;
  for(int tc=1; tc<=T; tc++){
    int N; cin>>N;
    for(int i=1; i<=N; i++) {visited[i]=0; cin>>student[i];}
    for(int i=1; i<=N; i++){
      if(visited[i]==-1) continue;
      int j=i;
      while(visited[j]<2){
        if(visited[j]==-1) break; // 이미 가망없는 애는 탐색을 포기
        visited[j]++; // 사이클이 생길 때까지 탐색을 계속함
        j=student[j];
      }

      j=i;
      while(visited[j]<2){
        if(visited[j]==-1) break; // 이미 가망없는 애는 탐색을 포기
        visited[j]=-1; // 사이클이 만들어지지 않으면 -1 체크해주기
        j=student[j];
      }
    }

    int ans=0;
    for(int i=1; i<=N; i++){
      if(visited[i]==-1) ans++;
    }
    cout<<ans<<"\n";
  }

  return 0;
}
