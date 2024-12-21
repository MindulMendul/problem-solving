#include <iostream>

using namespace std;

string str;

int count(int s, int e, char a){
  int res=0;
  for(int i=s; i<e; i++){
    if(str[i]==a) res++;
  }
  return res;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  cin>>str;
  int str_size=str.size(), w_size=count(0, str_size, 'a'), ans=1001;
  str+=str;

  for(int i=0; i<str_size; i++){
    int b_cnt=count(i, i+w_size, 'b');
    if(b_cnt<ans) ans=b_cnt;
  }
  
  cout<<ans;
  return 0;
}