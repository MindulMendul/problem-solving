#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> liq;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N;
  for(int i=0; i<N; i++){
    int a; cin>>a;
    liq.push_back(a);
  }

  int ans, ml, mr, l, r;
  ml=l=0; mr=r=liq.size()-1;
  ans=liq[l]+liq[r]; if(ans<0) ans*=-1;
  while(l<r){
    int sum=liq[l]+liq[r];
    if(abs(sum)<abs(ans)) {
      ans=sum;
      ml=l; mr=r;
    }

    if(sum<0){
      l++;
    } else {
      r--;
    }
  }

  cout<<liq[ml]<<" "<<liq[mr];
  
  return 0;
}
