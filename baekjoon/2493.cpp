// <코드 설명>
// i번 째를 기준으로 i-1번 째 탑이 i번째 탑보다 크면 그 값이 국소적으로 최대값을 가짐 (이 값을 국소최대값이라 정의)
// 왼쪽을 봤을 때 국소최대값이 현재 탑보다 크면 그 값이 정답
// 국소최대값이 현재 탑보다 작으면 그것보다 왼쪽에 있는 국소최대값을 탐색
// 근데 이제 국소최대값이 현재 탑보다 작으면, 그 값은 더이상 검색할 필요가 없음
// 결론) 스택으로 국소최대값 후보를 넣어두고, top만 확인하면 된다!

// 국소최대값이 현재 탑보다 작으면, 그 값은 더이상 검색할 필요가 없는 이유
// 예시로, 6 4 3 5 2 7을 보자.
// 국소최대값을 배열에 추가하면 [6] => [6 4] => [6 4 5] => [6 4 5 7] 로 갱신됨
// 이때 배열 안에 4는 탐색될 일이 없음
// 왜냐하면 이미 5를 검색하는 동안 4<5 였기 때문
// 현재 탑보다 작아지는 순간, 현재 탑 자체가 검색하던 국소최대값보다 효율적인 국소최대값이 되어버림
// 그래서 검색할 필요 가 없다.

#include <iostream>
#include <vector>

using namespace std;

int main(){
  // 그냥 빠르게 하는 코드
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;

  vector<int> elem; // 탑의 높이 저장하는 배열
  vector<int> ans; // 정답 배열
  vector<int> mm; // 국소최댓값 스택
  int _max=0, prev=100'000'001; // 가장 왼쪽에 엄청 높은 탑이 있다고 가정

  elem.push_back(prev); // 가상의 탑 넣기
  ans.push_back(prev); // 가상의 탑 넣기

  for(int i=1; i<=N; i++){
    int a; cin>>a; // 현재 탑 높이 읽기
    elem.push_back(a); // 탑의 높이 저장
    if(prev>a){ // 왼쪽 탑이 더 크면
      _max=i-1; // 거기가 국소최댓값
      mm.push_back(i-1); // 후보지 저장
    }
    else if(prev<a) {
      while(elem[mm[mm.size()-1]]<=a){ // 
        mm.pop_back(); // 후보지 ㅂㅂ
      }
      _max=mm[mm.size()-1]; // 후보지 중 정답을 고름
    }

    ans.push_back(_max); // 정답을 스택에 넣음
    prev=a; // 이전 탑 값 갱신
  }

  // 만약 모든 값이 가상의 탑 인덱스인 0을 가리키고 있는 거라면, 수신하고 있는 탑이 없다는 말임
  // 0이 가장 작은 인덱스이므로, 정답 배열의 최대값이 0이라면 수신하고 있는 탑이 없다는 뜻
  // 즉, 이것만 예외로 0 출력
  _max=-1; for(int i=1; i<=N; i++){if(_max<ans[i]) _max=ans[i];}
  if(_max==0) {
    cout<<0;
    return 0;
  }
  
  // 가상의 탑을 제외한 나머지 출력
  for(int i=1; i<=N; i++){
    cout<<ans[i]<<" ";
  }
  
  return 0;
}