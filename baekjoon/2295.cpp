/// 이분탐색으로 푸는 문제라고 아예 카테고리를 박았으니, 푸는 것도 이분탐색을 써야겠다.
// 먼저, d 값을 미리 정해서, 그것에 해당하는 x, y, z를 찾는 것이 제일 best인 듯
// 만약 쌩으로 찾을 거면 N^4 정도 걸릴 듯. (최악의 경우, 1조 번의 계산..)
// d, y, z를 미리 지정해준 뒤에, x를 이분탐색으로 찾는다면 더 빨리 찾을 수 있을 듯
// 즉, y, z를 구한 뒤에 x를 이분탐색으로 풀고,
// 만약 이분탐색을 끝나도 못 찾으면 d값을 수정해서 푸는 식으로 구현하면 조금 더 최적화될 듯.
// 여전히 N^3*logN 인데, 아직은 안 될 것 같은데... 

// d 값은 자연수이므로, x,y,z<d 임이 보장된다.
// x<=y<=z 인데, y+y+z<d 이면, 애초에 x+y+z=d 일 리가 없다. 즉, 저 조건에서는 x 검사를 건너뛴다.
// 3*z<d 이면 애초에 조건을 만족하는 x,y,z 가 없다. 즉, d를 낮추어 다시 검사하기.
// 검사해서 만족하는 d가 나오면, 그게 정답이다. 어차피 제일 큰 d 후보부터 찾아보기 때문에 가능하다.

/// 역시 저 방법은 N^3*logN 이라서 문제가 있는 게 맞았다.
// 더 쉬운 방법 중에 N^2*logN 이 있었다... (답지를 봐버린... ㅠㅠ)
// 어차피 (x,y,z)의 값이 중요한 건 아니다.
// 즉, (x+y) 를 모두 저장한 뒤에, (z,d) 쌍을 찾는다면 금방 찾을 수 있을 듯.
// (x+y) 는 set을 이용해서 N^2*logN (정렬까지 할 거거든) 만에 만들 수 있음.
// 이후에 (z,d) 쌍을 돌면서 조건을 만족하는 (x+y) 값을 찾으면 d를 반환하면 됨. 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// cost, memory
typedef pair<int, int> cm;

int isAnswer(vector<int>& v, int x, int y, int z, int d){
  return v[x]+v[y]+v[z]==v[d];
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  vector<int> v(N);
  set<int> sset;
  for(int i=0; i<N; i++) cin>>v[i];
  sort(v.begin(), v.end());

  // 가능한 x+y 값으로 xy 채우기
  for(int x=0; x<N-1; x++){
    for(int y=x; y<N-1; y++){
      sset.insert(v[x]+v[y]);
    }
  }
  vector<int> xy(sset.size());
  int i=0;
  for(int e:sset) xy[i++]=e;
  

  // 큰 d부터 순서대로 탐색.
  for(int d=N-1; d>=1; d--){
    // 큰 z부터 순서대로 탐색.
    for(int z=d-1; z>=0; z--){
      // x+y 는 이분탐색으로 찾음.
      int s=0, e=xy.size()-1, mid=(s+e)/2;
      while(s<e){
        if(xy[mid]+v[z]==v[d]) {cout<<v[d]; return 0;}
        else if(xy[mid]+v[z]<v[d]) s=mid+1;
        else e=mid-1;
        mid=(s+e)/2;
      }
      
      if(xy[mid]+v[z]==v[d]) {cout<<v[d]; return 0;}
    }
  }

  cout<<v[1];
  return 0;
}
