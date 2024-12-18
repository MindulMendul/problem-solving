#include <iostream>
#include <vector>
#include <map>

using namespace std;


int T, a_n, b_n;
vector<int> a;
vector<int> b;
map<int, long long int> am;
map<int, long long int> bm;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  cin>>T;

  cin>>a_n;
  for(int i=0; i<a_n; i++){
    int tmp; cin>>tmp;
    a.push_back(tmp);
  }

  cin>>b_n;
  for(int i=0; i<b_n; i++){
    int tmp; cin>>tmp;
    b.push_back(tmp);
  }

  // create map
  for(int i=0; i<a_n; i++){
    int a_sum=a[i];
    if(am.count(a_sum)==0){am[a_sum]=1;}
    else {am[a_sum]+=1;}

    for(int j=i+1; j<a_n; j++){
      a_sum+=a[j];
      if(am.count(a_sum)==0){am[a_sum]=1;}
      else {am[a_sum]+=1;}
    }
  }

  for(int i=0; i<b_n; i++){
    int b_sum=b[i];
    if(bm.count(b_sum)==0){bm[b_sum]=1;}
    else {bm[b_sum]+=1;}

    for(int j=i+1; j<b_n; j++){
      b_sum+=b[j];
      if(bm.count(b_sum)==0){bm[b_sum]=1;}
      else {bm[b_sum]+=1;}
    }
  }

  // two pointer
  int s=0, e=0;
  long long int ans=0;
  auto as=am.begin(), be=bm.end(); be--;
  while(as!=am.end() && be!=bm.begin()){
    auto ap=*as, bp=*be;
    if(ap.first+bp.first<T) as++;
    else {
      if(ap.first+bp.first==T) ans+=ap.second*bp.second;
      be--;
    }
  }

  while(as!=am.end()){
    auto ap=*as, bp=*be;
    if(ap.first+bp.first==T) ans+=ap.second*bp.second;
    as++;
  }

  while(be!=bm.begin()){
    auto ap=*as, bp=*be;
    if(ap.first+bp.first==T) ans+=ap.second*bp.second;
    be--;
  }

  if(as==am.end() && be==bm.begin()){
    if((*as).first+(*be).first==T) ans+=(*as).second*(*be).second;
  }
  
  cout<<ans;
	
  return 0;
}
