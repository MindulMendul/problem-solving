// https://www.acmicpc.net/problem/6988

#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  vector<int> tile(N);
  vector<int> dis[N];
  for(int i=0; i<N; i++) cin>>tile[i];
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      dis[i].push_back(tile[j]-tile[i]);
    }
  }
  int ans=0, cnt=0, sum=0;
  // if (i번째 타일에서 j개만큼 떨어진 타일의 dis == j에서 k개 만큼 떨어진 타일의 dis) : 
  // i+=j; j+=k;
  // 만약 j에서 k로 search하다가 못 찾으면 해당 탐색은 끝. (즉, k>=dis[j].size()) 
  for(int s=0; s<N; s++){
    for(int d=s+1; d<N; d++){
      cnt=0; sum+=tile[s];
      int i=s, j=d-s-1, k=0;


      while(k<dis[i+j+k].size()){
        if(dis[i+j][j]==dis[i+j+k][k]) {
          i+=j; j+=k;
          sum+=tile[i];
          cnt++;
        }
        k++;
      }
      
      if(cnt>=3 && ans<sum) {ans=sum;}
    }
  }

  cout<<ans;
  return 0;
}