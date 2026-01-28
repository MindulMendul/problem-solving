#include <iostream>
#include <string>

using namespace std;

int T, N, M;
int broken[10];
int dp[10][1024];

void solution(){
  cin>>N>>M;
  string str;
  for(int i=0; i<N; i++){
    cin>>str;
    broken[i]=0;
    for(int j=0; j<M; j++){
      broken[i]=(broken[i]<<1);
      if(str[j]=='x') broken[i]+=1;
    }
  }
  for(int i=0; i<N; i++) for(int j=0; j<(1<<M); j++) dp[i][j]=-1;
  
  // 첫 줄은 다른 줄과 상황이 다름
  for(int curr=0; curr<(1<<M); curr++){
    if((curr & broken[0])!=0) continue; // 부러진 곳에 앉아있다면 스킵
    if (curr & (curr << 1)) continue; // 양 옆에 컨닝하면 스킵
    dp[0][curr]=__builtin_popcount(curr);
  }

  // 두 번째 줄부터는 점화식 활용
  for(int row=1; row<N; row++){
    for(int curr=0; curr<(1<<M); curr++){
      if((curr & broken[row])!=0) continue; // 부러진 곳에 앉아있다면 스킵
      if (curr & (curr << 1)) continue; // 양 옆에 컨닝하면 스킵
      for(int prev=0; prev<(1<<M); prev++){
        if(dp[row-1][prev]==-1) continue; // 앞 자리가 불가능하다면 스킵
        if (curr & (prev << 1)) continue; // 왼쪽 위 대각선에 컨닝하면 스킵
        if (curr & (prev >> 1)) continue; // 오른쪽 위 대각선에 컨닝하면 스킵
        dp[row][curr]=max(dp[row][curr], __builtin_popcount(curr)+dp[row-1][prev]);
      }
    }
  }

  int ans=0;
  for(int curr=0; curr<(1<<M); curr++){
    if(ans<dp[N-1][curr]) ans=dp[N-1][curr];
  }
  cout<<ans<<"\n";
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>T;
  for(int tc=1; tc<=T; tc++){
    solution();
  }

  return 0;
}
