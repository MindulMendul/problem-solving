#include <iostream>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, ans=0; cin>>N;
  int arr[N], dp[N];
  for(int i=0; i<N; i++){
    cin>>arr[i]; dp[i]=1;
    for(int j=i-1; j>=0; j--){
      if(arr[i]>arr[j]){
        if(dp[i]<dp[j]+1) dp[i]=dp[j]+1;
      }
    }

    if(ans<dp[i]) ans=dp[i];
  }

  cout<<ans;

  return 0;
}
