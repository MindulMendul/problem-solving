#include <iostream>
#include <vector>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> v;
  int H, W; cin>>H>>W;
  for(int i=0; i<W; i++){
    int h; cin>>h;
    v.push_back(h);
  }

  // 왼쪽부터 two pointer로 search
  int s=0, e=0, ans=0;
  while(e<W){
    if(s==e) e++;
    else {
      if(v[s]<=v[e]){
        int hh=v[s++]; // 물이 고이는 높이
        while(s<e) ans+=hh-v[s++];
      } else e++;
    }
  }

  int bc=s; // 왼쪽에서 search한 데까지만 오른쪽에서 search하면 됨
  s=W-1; e=W-1;

  // 오른쪽 남은 부분만 two pointer로 search
  while(s>=bc){
    if(s==e) s--;
    else {
      if(v[s]>=v[e]){
        int hh=v[e--]; // 물이 고이는 높이
        while(s<e) ans+=hh-v[e--];
      } else s--;
    }
  }

  cout<<ans;

  return 0;
}