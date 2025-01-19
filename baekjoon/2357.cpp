#include <iostream>

using namespace std;

int N, M;
int elem[100'000];
int _min[400'001];
int _max[400'001];

int initMin(int s, int e, int i){
  if(s==e) return _min[i]=elem[s];
  int mid=(s+e)/2;
  int left=initMin(s,mid,2*i);
  int right=initMin(mid+1,e,2*i+1);
  return _min[i]=min(left,right);
}

int getMin(int s, int e, int i, int l, int r){
  if(e<l || s>r) return 1000000001;
  if(l<=s && e<=r) return _min[i];
  int mid=(s+e)/2;
  int left=getMin(s,mid,2*i,l,r);
  int right=getMin(mid+1,e,2*i+1,l,r);
  return min(left, right);
}

int initMax(int s, int e, int i){
  if(s==e) return _max[i]=elem[s];
  int mid=(s+e)/2;
  int left=initMax(s,mid,2*i);
  int right=initMax(mid+1,e,2*i+1);
  return _max[i]=max(left,right);
}

int getMax(int s, int e, int i, int l, int r){
  if(e<l || s>r) return -1;
  if(l<=s && e<=r) return _max[i];
  int mid=(s+e)/2;
  int left=getMax(s,mid,2*i,l,r);
  int right=getMax(mid+1,e,2*i+1,l,r);
  return max(left, right);
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  for(int i=0; i<N; i++) {
    cin>>elem[i];
  }

  initMin(0, N-1, 1);
  initMax(0, N-1, 1);

  for(int tc=1; tc<=M; tc++){
    int a, b; cin>>a>>b;
    cout<<getMin(0,N-1,1,a-1,b-1)<<' '<<getMax(0,N-1,1,a-1,b-1)<<'\n';
  }

  return 0;
}