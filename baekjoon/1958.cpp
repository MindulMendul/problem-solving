#include <iostream>

using namespace std;

int lcs(string s1, string s2, string s3) {
  int dp[s1.size()+1][s2.size()+1][s3.size()+1];

  for(int i=0; i<=s1.size(); i++){
    for(int j=0; j<=s2.size(); j++){
      for(int k=0; k<=s3.size(); k++){
        dp[i][j][k]=0;
      }
    }
  }

  for(int i=1; i<=s1.size(); i++){
    for(int j=1; j<=s2.size(); j++){
      for(int k=1; k<=s3.size(); k++){
        if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]){
          dp[i][j][k]=dp[i-1][j-1][k-1]+1;
        } else {
          dp[i][j][k]=max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
        }
      }
    }
  }

  return dp[s1.size()][s2.size()][s3.size()];
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s1, s2, s3;
  cin>>s1>>s2>>s3;
  cout<<lcs(s1,s2,s3);
  return 0;
}