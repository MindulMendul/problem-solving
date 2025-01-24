#include <iostream>
#include <vector>

#define DIV 1'000'000'007 // 이 값이 소수라서 가능

using namespace std;

typedef long long int lli;

vector<lli> elem(1'000'000);
vector<lli> _mul(4'000'001);

lli initMul(int s, int e, int i){
  if(s==e) {return _mul[i]=elem[s];}
  int mid=(s+e)/2;
  lli l=initMul(s, mid, 2*i);
  lli r=initMul(mid+1, e, 2*i+1);
  return _mul[i]=(l*r)%DIV;
}

lli getMul(int s, int e, int i, int l, int r){
  if(e<l || r<s) return 1;
  if(l<=s && e<=r) return _mul[i];
  int mid=(s+e)/2;
  lli left=getMul(s, mid, 2*i, l, r);
  lli right=getMul(mid+1, e,2*i+1, l, r);
  return (left*right)%DIV;
}

void updateMul(int s, int e, int i, int t, lli v){
  if(t<s || e<t) return;
  if(s==e) {_mul[i]=v; return;}
  int mid=(s+e)/2;
  updateMul(s, mid, 2*i, t, v);
  updateMul(mid+1, e,2*i+1, t, v);
  _mul[i]=(_mul[2*i]*_mul[2*i+1])%DIV;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, K; cin>>N>>M>>K;
  for(int i=0; i<N; i++) cin>>elem[i];
  initMul(0, N-1, 1);
  for(int i=0; i<M+K; i++){
    int a; cin>>a;
    if(a==1){
      int b; lli c; cin>>b>>c;
      updateMul(0, N-1, 1, b-1, c);
      elem[b-1]=c;
    } else if(a==2){
      int b, c; cin>>b>>c;
      cout<<getMul(0,N-1,1,b-1,c-1)<<'\n';
    }
  }
  return 0;
}
