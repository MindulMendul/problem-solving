#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin>>N>>M;
  vector<int> vec(N);
  for(int i=0; i<N; i++) cin>>vec[i];
  sort(vec.begin(), vec.end());
  
  int s=0, e=0, diff_min=2000000001;
  while(e<N){
    if(s==e){ e++; continue; }
    int diff_tmp=vec[e]-vec[s];
    if(diff_tmp>=M){
      if(diff_tmp<diff_min) diff_min=diff_tmp;
      s++;
    } else {
      e++;
    }
  }
  cout<<diff_min;

  return 0;
}
