#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin>>N>>M;
  unordered_map<string, bool> um;

  for(int i=0; i<N; i++){
    string listen;
    cin>>listen;
    um[listen]=true;
  }

  vector<string> arr;

  for(int i=0; i<M; i++){
    string see;
    cin>>see;
    if(um.find(see)!=um.end()){
      arr.push_back(see);
    }
  }

  sort(arr.begin(), arr.end());
  cout<<arr.size()<<'\n';
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<'\n';
  }

  return 0;
}
