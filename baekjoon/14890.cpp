////
// 차이가 두 칸 이상 나면 무조건 안 되고
//
// 차이가 한 칸 나면, 그곳에서부터 L칸까지는 개수가 다 맞을 때까지 확인
// 근데 개수가 다 맞지 않거나, 범위를 벗어나면 x
// 범위가 들어맞으면 거기까지 j를 당겨주고 j++ 해주기.
//
// 차이가 안 나면 그냥 j++ 해주면 됨
///

#include <iostream>
#include <vector>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, L;
  cin>>N>>L;
  vector<vector<int>> v(N,vector<int>(N,0));
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>v[i][j];
  
  int ans=0;

  // 가로선
  for(int i=0; i<N; i++){
    int j=1, h=v[i][0], hj, flag=true;
    vector<int> balpan(N);
    while(j<N){
      hj=v[i][j];
      if(h-hj>1 || hj-h>1) {flag=false; break;}
      else if(hj==h) {j++; continue;}
      else if(h-hj==1){
        if(j+L>N) {flag=false; break;}
        int k=1;
        while(k<L){
          if(v[i][j+k]!=hj) {flag=false; j=N; break;}
          if(balpan[j+k]) {flag=false; j=N; break;}
          k++;
        }
        if(flag){for(k=0; k<L; k++){balpan[j+k]=1;}}
        h=hj;
      } else if(hj-h==1){
        if(j-L<0) {flag=false; break;}
        int k=1;
        while(k<=L){
          if(v[i][j-k]!=h) {flag=false; j=N; break;}
          if(balpan[j-k]) {flag=false; j=N; break;}
          k++;
        }
        if(flag){for(k=1; k<=L; k++){balpan[j-k]=1;}}
        h=hj;
      }
      j++;
    }

    if(flag) {ans++;}
  }

  // 세로선
  for(int i=0; i<N; i++){
    int j=1, h=v[0][i], hj, flag=true;
    vector<int> balpan(N);
    while(j<N){
      hj=v[j][i];
      if(h-hj>1 || hj-h>1) {flag=false; break;}
      else if(hj==h) {j++; continue;}
      else if(h-hj==1){
        if(j+L>N) {flag=false; break;}
        int k=0;
        while(k<L){
          if(v[j+k][i]!=hj) {flag=false; j=N; break;}
          if(balpan[j+k]) {flag=false; j=N; break;}
          k++;
        }
        if(flag){for(k=0; k<L; k++){balpan[j+k]=1;}}
        h=hj;
      } else if(hj-h==1){
        if(j-L<0) {flag=false; break;}
        int k=1;
        while(k<=L){
          if(v[j-k][i]!=h) {flag=false; j=N; break;}
          if(balpan[j-k]) {flag=false; j=N; break;}
          k++;
        }
        if(flag){for(k=1; k<=L; k++){balpan[j-k]=1;}}
        h=hj;
      }
      j++;
    }

    if(flag) {ans++;}
  }

  cout<<ans;

  return 0;
}
