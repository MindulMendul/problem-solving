#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
int moum, jaum;
vector<char> c;

char v[15];

bool isMoum(char c){
  if(c=='a') return true;
  else if(c=='e') return true;
  else if(c=='i') return true;
  else if(c=='o') return true;
  else if(c=='u') return true;
  return false;
}

void dfs(int dep, int ind){
  v[dep]=c[ind];
  if(isMoum(c[ind])){moum++;} else {jaum++;}
  if(dep+1==L && moum>0 && jaum>1){
    for(auto e:v){cout<<e<<'\n';}
  }
  if(isMoum(c[ind])){moum--;} else {jaum--;}
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  cin>>L>>C;
  
  for(int i=0; i<C; i++){
    char a; cin>>a;
    if(a==97)
    c.push_back(a);
  }
  sort(c.begin(), c.end());

  moum=0; jaum=0;
  dfs(0, 0);

  return 0;
}
