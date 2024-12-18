#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long int> liq;

long long int ans;
int mm, ml, mr;

void getLiq(int m){
  int l, r;
  l=m+1; r=liq.size()-1;
  while(l<r){
    long long int sum=liq[m]+liq[l]+liq[r];
    if(abs(sum)<ans) {
      ans=abs(sum);
      mm=m; ml=l; mr=r;
    }

    if(sum<0){ l++; }
    else { r--; }
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N;
  for(int i=0; i<N; i++){
    long long int a; cin>>a;
    liq.push_back(a);
  }

  sort(liq.begin(), liq.end());
  mm=0; ml=1; mr=liq.size()-1;
  ans=liq[0]+liq[1]+liq[liq.size()-1]; if(ans<0) ans*=-1;

  for(int i=0; i<N-2; i++){
     getLiq(i);
  }

  cout<<liq[mm]<<" "<<liq[ml]<<" "<<liq[mr];
  
  return 0;
}
