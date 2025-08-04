#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int len; cin>>len;
  vector<int> arr, stack;
  for(int i=0; i<len; i++) {int a; cin>>a; arr[i]=a;}
  for(int i=0; i<len; i++) cout<<arr[i]<<" ";
  cout<<'\n';

  for(int i=len-1; i>=0; i--){
    if(stack.size()>0) {while(stack[stack.size()-1]>arr[i]) stack.pop_back();}
    stack.push_back(arr[i]);
  }

  for(int i=0; i<stack.size(); i++){
    cout<<stack[i]<<" ";
  }cout<<'\n';
  
  return 0;
}
