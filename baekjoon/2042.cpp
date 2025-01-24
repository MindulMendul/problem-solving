#include <iostream>
#include <vector>

// #define MIN_INF -9'223'372'036'854'775'808

using namespace std;

typedef long long int lli;

vector<lli> elem(1'000'000);
vector<lli> _sum(4'000'001);

lli initSum(int s, int e, int i){
  if(s==e) {return _sum[i]=elem[s];}
  int mid=(s+e)/2;
  lli l=initSum(s, mid, 2*i);
  lli r=initSum(mid+1, e, 2*i+1);
  return _sum[i]=l+r;
}

lli getSum(int s, int e, int i, int l, int r){
  if(e<l || r<s) return 0;
  if(l<=s && e<=r) return _sum[i];
  int mid=(s+e)/2;
  lli left=getSum(s, mid, 2*i, l, r);
  lli right=getSum(mid+1, e,2*i+1, l, r);
  return left+right;
}

void updateSum(int s, int e, int i, int t, lli d){
  if(t<s || e<t) return;
  _sum[i]+=d;
  if(s==e) return;
  int mid=(s+e)/2;
  updateSum(s, mid, 2*i, t, d);
  updateSum(mid+1, e,2*i+1, t, d);
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, K; cin>>N>>M>>K;
  for(int i=0; i<N; i++) cin>>elem[i];
  initSum(0, N-1, 1);
  for(int i=0; i<M+K; i++){
    int a; cin>>a;
    if(a==1){
      int b; lli c; cin>>b>>c;
      updateSum(0,N-1,1,b-1,c-elem[b-1]);
      elem[b-1]=c;
    } else if(a==2){
      int b, c; cin>>b>>c;
      cout<<getSum(0,N-1,1,b-1, c-1)<<'\n';    
    }
  }
  return 0;
}
