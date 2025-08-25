// https://yabmoons.tistory.com/561

#include <iostream>
#include <vector>

using namespace std;

int arr[1'000'000]; // arr = input array
int ind[1'000'000]; // ind = index
vector<int> lis; //LIS = Longest Increasing Subsequence

// 아이디어 : LIS와 INDEX 배열을 이용해서 구하는 것.

// LIS는 최장증가부분수열을 대략적으로 알려주는 배열
// 수열의 i번째 원소가 [0~i-1] 의 원소 중에 몇 번째로 큰지만 확인하기.
// i번째 원소가 LIS 원소 중에 가장 크면 LIS의 오른쪽에 추가, 그게 아니면 사이에 넣어주기.
// LIS는 이분탐색을 이용해서 찾아줄 거임.
// ex) i번쨰 원소가 20, LIS=[10, 30] 일 때는 LIS=[10->20, 30] 으로 변경하게 하기
// ex2) i번쨰 원소가 40, LIS=[10, 30] 일 때는 LIS=[10, 30, 40] 으로 추가.
// 이렇게 하면 최장증가부분수열의 길이는 LIS의 길이와 동일해짐.

// INDEX는 LIS를 이용해 대략적으로 찾아둔 수열을 정확히 찾아주는 배열
// i번째 원소가 LIS의 j번째 위치에 들어갔다면, INDEX[i]=j 로 입력.
// i번째 원소가 LIS의 몇 번째 위치에 들어갔는지 기록해두면, 역순으로 찾을 수 있음
// LIS.size()-1부터 0까지, INDEX 값을 역순으로 찾아 기록해두면 끝.


int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  for(int i=0; i<N; i++) cin>>arr[i];

  for(int i=0; i<N; i++){
    if(lis.size()==0 || lis[lis.size()-1]<arr[i]){
      lis.push_back(arr[i]);
      ind[i]=lis.size()-1;
    } else {
      int s=0, e=lis.size()-1;
      while(s<e){
        int mid=(s+e)/2;
        if(lis[mid]<arr[i]) s=mid+1;
        else e=mid;
      }
      lis[s]=arr[i];
      ind[i]=s;
    }
  }
  cout<<lis.size()<<'\n'; // 여기까지가 길이 구현

  vector<int> ans;
  int found_ind=lis.size()-1;
  for(int i=N-1; i>=0; i--){
    if(ind[i]==found_ind) {
      ans.push_back(arr[i]);
      found_ind--;
    }
  }

  for(int i=ans.size()-1; i>=0; i--){
    cout<<ans[i]<<" ";
  }

  return 0;
}
