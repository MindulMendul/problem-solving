#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  vector<int> num(N+1, 0);
  for(int i=0; i<N; i++){
    int tmp; cin>>tmp;
    if(num[tmp-1]>0) num[tmp]=num[tmp-1];
    else num[tmp]=tmp;
  }

  int ans=0, cnt=0;
  for(int i=N; i>=1; i--){
    cnt++;
    if(num[i]==i){
      if(ans<cnt) {ans=cnt;}
      cnt=0;
    }
  }

  cout<<N-ans;

  return 0;
}