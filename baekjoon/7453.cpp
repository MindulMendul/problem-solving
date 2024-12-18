#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
vector<long long int> V;
vector<long long int> W;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;

  for(int i=0; i<N; i++){
    int x1, x2, x3, x4;
    cin>>x1>>x2>>x3>>x4;
    a.push_back(x1);
    b.push_back(x2);
    c.push_back(x3);
    d.push_back(x4);
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      long long int aa=(long long int)a[i]+b[j], cc=(long long int)c[i]+d[j];
      V.push_back(aa);
      W.push_back(cc);
    }
  }

  sort(V.begin(), V.end());
  sort(W.begin(), W.end());

  long long int ans=0;
  int s=0, e=W.size()-1;
  while(s<V.size() && e>=0){
    if(V[s]+W[e]==0){
      int ss=1, ee=1;
      while(s+ss<V.size() && V[s]==V[s+ss]) ss++;
      while(e+ee>=0 && W[e]==W[e-ee]) ee++;
      ans+=(long long int) ss*ee;
      s+=ss; e-=ee;
    } else if(V[s]+W[e]<0) {
      s++;
    } else {
      e--;
    }
  }
  
  cout<<ans;

  return 0;
}
