/// 암만 봐도 이해가 전혀 안 돼서 그냥 답지 보고 했다.
// 해당 문제는 ( 이전 정답 + 현재 상태 = 현재 정답 ) 꼴의 문제임을 감안하고 풀면 O(N) 으로 풀 수 있는 문제라고 함
// 즉, 누적합 문제가 되겠다!
// 이렇게 색깔이 다른 문제에서 누적합 냄새가 난다면, 미리 누적합을 구하고 이분탐색으로 접근하는 방식은 X
// 정답을 계속 구해가면서 누적합을 쌓아가는 방식으로 구하면 정답을 구할 수 있다!

// 풀이 방법은, 먼저 전체 공을 크기 순으로 정렬하여, 색깔 누적합과, 나와 같은 크기의 공 누적합을 다른 방식으로 누적하여 구하는 식으로 접근해야 한다.
// 나와 같은 색깔 누적합을 쭉 구하면 그것들은 나머지 값에서 빼는 방식으로 배제할 수 있다.
// 나와 같은 크기의 공 누적합을 따로 구하면, (모든 공 누적합)에서 (나와 같은 크기 공 누적합) 을 빼면, 나보다 작은 크기 공 누적합 만 볼 수 있다.
// 나는 (나와 같은 색깔)과 (나와 같은 크기)에 모두 속하므로 그 값만 빼주면 된다.
// (해당 공이 먹을 수 있는 크기합) = (이전까지 모든 공 크기 누적합) - (해당 공과 같은 색깔의 공 크기 누적합) - (해당 공과 같은 크기의 공 크기 누적합) + (해당 공 크기)

// 이 아래 말이 무슨 말인지 잘 모르겠다.. 저 조건 안에서 해결이 안 되는 예외사항인가...?
// 전에 있던 공이 나와 같은 색깔의 공인데, 크기가 같은 공이라면, 정답이 같아야 한다는 점을 알아야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// pip = <index, <color, size>>
typedef pair<int, pair<int, int>> pip;

struct cmp {
  bool operator()(pip a, pip b){
    if(a.second.first==b.second.first && a.second.second==b.second.second) return a.first<b.first;
    if(a.second.second==b.second.second) return a.second.first<b.second.first;
    return a.second.second<b.second.second;
  }
};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  int N; cin>>N;
  vector<pip> ball(N);
  vector<int> same_size(2000);
  vector<int> same_color(N);
  vector<int> ans(N);
  for(int i=0; i<N; i++){
    int color, size; cin>>color>>size;
    ball[i]=make_pair(i, make_pair(color-1, size));
  }
  sort(ball.begin(), ball.end(), cmp());

  int sum=0;
  for(int i=0; i<N; i++){
    int ind=ball[i].first;
    int color=ball[i].second.first;
    int size=ball[i].second.second;

    sum+=size;
    same_color[color]+=size;
    same_size[size-1]+=size;
    if(i>0 && ball[i-1].second.first==color && ball[i-1].second.second==size){
       ans[ind] = ans[ball[i-1].first];
    } else {
      ans[ind]=sum-same_color[color]-same_size[size-1]+size; 
    }
  }

  for(int i=0; i<N; i++){
    cout<<ans[i]<<'\n';
  }

  return 0;
}
