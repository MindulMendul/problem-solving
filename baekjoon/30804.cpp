#include <iostream>

using namespace std;

static int tanghuru[200000];
static int q[2];
static int cnt[10]={0,0,0,0,0, 0,0,0,0,0};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, s=0, e=0; cin>>N;
  for(int i=0; i<N; i++){
    cin>>tanghuru[i];
  }

  int ans=0, type=0;
  while(e<N){
    if(cnt[tanghuru[e]]++ == 0){
      type++;
    }

    while(type>2){
      if(--cnt[tanghuru[s]] == 0){
        type--;
      }
      s++;
    }
    if(ans<e-s+1) {ans=e-s+1;}
    e++;
  }

  cout<<ans;

  return 0;
}
