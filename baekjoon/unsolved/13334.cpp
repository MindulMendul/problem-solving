/// 정렬해서 스위핑하면 되는 문제같긴 한데..
// 그러면 s 와 e를 잡고 search하는 two pointer 문제로 변형 가능하네.
// 슬라이딩 윈도우 같은 건 h, o 값의 범위가 너무 길어서 힘들 듯..

// 일단 h가 작은 걸로. 같다면 o가 작은 걸로 정렬
// 정렬된 애를 s로 잡고 s.h를 기준으로 d 길이의 선로를 뻗음
// 순서대로 e가 서치해서 e.o<=s.h+d 이면 e를 다음 후보로 넘김
// 그러다가 e.o>h+d 이면, 그 순간에는 조건을 벗어난 것이므로 정답을 기록
// 그리고 s를 pop 하고 다음 애를 s로 잡고, s.h+d를 갱신함.
// 이러면 O(N) 이겠다!

/// 아직 멍청하군! 예외케이스가 있다!
// 0 10 / 1 11 / 2 8 / d=10 인 경우, 2 8을 search하지 않고 넘어가는 문제가 있단 말이다.
// 그래서 도착 위치를 기준으로 

// 라인 스위핑 문제래.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
  }
};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, d; cin>>N;
  vector<pair<int, int>> human(N);
  for(int i=0; i<N; i++){
    int h, o;
    cin>>h>>o;
    if(h>o) {int tmp=h; h=o; o=tmp;}
    human[i]=make_pair(h, o);
  }
  cin>>d;
  
  int ans=0, s=0, e=0;
  sort(human.begin(), human.end(), cmp());

  for(auto p:human){
    cout<<p.first<<" "<<p.second<<endl;
  }
  
  while(e<N){
    pair<int, int> t=human[s];
    int D=t.first+d;
    while(e<N){
      if(human[e].second>D) break;
      e++;
    }
    int tmp_ans=e-s;
    if(ans<tmp_ans) ans=tmp_ans;
    s++;
  }

  cout<<ans;

  return 0;
}
