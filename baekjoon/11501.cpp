#include <iostream>

using namespace std;

int T, N;
long long int arr[1'000'000];

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);

  cin>>T;
  for(int tc=1; tc<=T; tc++){
    cin>>N;
    long long int ans=0;
    for(int i=0; i<N; i++) {
      cin>>arr[i];
      ans-=arr[i];
    }

    long long int __max=arr[N-1];
    for(int i=N-1; i>=0; i--) {
      if(__max<arr[i]) __max=arr[i];
      arr[i]=__max;
      ans+=arr[i];
    }

    cout<<ans<<"\n";
  }  
  
  return 0;
}
