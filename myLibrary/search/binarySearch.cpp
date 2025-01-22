// binary search 할 떄,
// while 문 안에 mid를 나중에 갱신해주는 게 유리
// 그래야 mid 값이 확실하게 하나로 고정되기 때문.
// 만약, mid 값을 먼저 지정하고 그 다음에 s, e 값을 바꾸면
// mid, mid+1 중에 후보지를 또 선택해주어야 하는 번거로움이 생김
// mid=(s+e)/2; 로 미리 선언 후, (s, e) 값 지정한 뒤에 mid를 갱신하면
// 마지막에 mid 값이 무조건 내가 찾는 값이 됨. 

#include <iostream>
#include <vector>

using namespace std;

int a[10]={1,2,3,4,5,6,7,8,9,10};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  int f=7;
  int s=0, e=9, mid=(s+e)/2;
  while(s<=e){
    if(a[mid]<=f) e=mid-1;
    else s=mid+1;
    mid=(s+e)/2;
  }

  cout<<mid;
  
  return 0;
}