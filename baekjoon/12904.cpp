#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S, T;
  cin>>S>>T;

  while(S.size()<T.size()){
    if(T[T.size()-1]=='B'){
        T.pop_back();
        reverse(T.begin(), T.end());
    } else if(T[T.size()-1]=='A'){
        T.pop_back();
    }
  }
  
  cout<<(S==T);
  return 0;
}