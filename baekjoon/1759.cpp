#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> c;

bool isMoum(char c){
  if(c=='a') return true;
  else if(c=='e') return true;
  else if(c=='i') return true;
  else if(c=='o') return true;
  else if(c=='u') return true;
  return false;
}

void dfs(string s, int dep, int ind, int moum, int jaum){
  if(dep==L){
    if(moum>=1 && jaum>=2){cout<<s<<'\n';}
    return;
  }
  

  for(int i=ind; i<C; i++){
    int m=moum, j=jaum;
    if(isMoum(c[i])) m++; else j++;
    dfs(s+c[i], dep+1, i+1, m, j);
  }

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
    c.push_back(a);
  }
  sort(c.begin(), c.end());
  dfs("", 0, 0, 0, 0);

  return 0;
}
