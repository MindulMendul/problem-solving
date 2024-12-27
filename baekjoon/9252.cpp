#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s1, s2;
  cin>>s1>>s2;
  int dp[s1.size()+1][s2.size()+1];

  for(int i=0; i<=s1.size(); i++){
    for(int j=0; j<=s2.size(); j++){
      dp[i][j]=0;
    }
  }

  for(int i=1; i<=s1.size(); i++){
    for(int j=1; j<=s2.size(); j++){
      if(s1[i-1]==s2[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
      } else {
        dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  int i=s1.size(), j=s2.size();
  string ans="";
  while(i>=1 && j>=1){
    if(dp[i][j]==dp[i-1][j]){i--;}
    else if(dp[i][j]==dp[i][j-1]){j--;}
    else {i--; j--; ans+=s2[j];}
  }

  reverse(ans.begin(), ans.end());
  cout<<dp[s1.size()][s2.size()]<<'\n'<<ans;
  
  return 0;
}

//     a c a y k p
//   0 0 0 0 0 0 0
// c 0 0 1 1 1 1 1
// a 0 1 1 2 2 2 2
// p 0 1 1 2 2 2 2
// c 0 1 2 2 2 2 2
// a 0 1 2 3 3 3 3
// k 0 1 2 3 3 4 4
// z 0 1 2 3 3 4 4