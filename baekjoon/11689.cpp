#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

long long int N, ans;
vector<int> prime;
unordered_set<int> us;
vector<long long int> v;

void initPrime(){
  prime.push_back(2);

  for(int i=3; i<1'000'001; i++){
    bool flag=true;
    for(int p:prime){
      if(p*p>i) break;
      if(i%p==0) {
        flag=false;
        break;
      }
    }

    if(flag) prime.push_back(i);
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N; ans=N;
  if(N==1){
    cout<<1;
    return 0;
  }

  initPrime();
  for(int p:prime){
    if(ans%p==0){
      us.insert(p);
      while(ans%p==0){
        ans/=p;
      }
    }
  }
  if(ans>1'000'000)v.push_back(ans);
  ans=N;

  for(int np:us){
    v.push_back((long long int)np);
  }

  if(v.size()==0){
    cout<<N-1;
    return 0;
  }

  for(int i=1; i<pow(2,v.size()); i++){
    int n=i;
    vector<bool> b;
    while(n>0){
      if(n%2==1) b.push_back(true);
      else b.push_back(false);
      n/=2;
    }

    long long int mul=1;
    long long int s=1;
    for(int j=b.size()-1; j>=0; j--){
      int bb=b[j];
      if(bb==1) {
        mul*=(long long int) v[j];
        s*=-1;
      }
    }

    ans+=s*(N/mul);
  }

  cout<<ans;
  
  return 0;
}
