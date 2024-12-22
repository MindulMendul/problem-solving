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
  int s=0, e=9, mid;
  while(s<=e){
    mid=(s+e)/2;
    if(a[mid]<=f){
      e=mid-1;
    } else {
      s=mid+1;
    }
  }

  cout<<mid;
  
  return 0;
}