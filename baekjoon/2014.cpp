// Greedy하게 푸는 문제

// 사전 약속
// 해당 문제는 prime number의 곱으로 구하기 때문에, 곱했을 때 소인수분해가 일정함.
// 따라서, PQ의 규칙을 잘 정하기만 하면 그리디하게 풀 수 있는 것이다!
// PQ에 담을 값을 선정할 때는, 현재 값 C를 기준으로,
// C가 가지고 있는 소인수 중에 제일 큰 값보다 큰 prime number는 곱하지 않는다.
// 어차피 처음 PQ에 모든 소인수를 다 때려놓고 시작이라, 중복이나 빠지는 수가 발생하지 않는다.

// 0. PQ에 소수를 모두 다 박아넣는다.
// 1. PQ에서 가장 작은 숫자 T를 뽑는다.
// 2. T 값으로부터 소수를 하나하나 곱해서 그 값을 PQ에 다시 넣는다.
// 3. 그러다가 T%p==0 인 경우가 나오면 break 한다.
// 4. T를 stack에 넣는다.
// 5. 1~4를 stack 의 길이가 N이 될 때까지 넣는다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int lli;

int N, K;
vector<lli> s;
priority_queue<lli> pq;

lli p[100];

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>K>>N;
  for(int i=0; i<K; i++) {
    cin>>p[i];
    pq.push(-p[i]);
  }

  while(s.size()<=N){
    lli t=-pq.top(); pq.pop();
    s.push_back(t);
    
    for(int i=0; i<K; i++){
      pq.push(-t*p[i]);
      if(t%p[i]==0) break;
    }
  }

  cout<<s[N-1];

  return 0;
}
 