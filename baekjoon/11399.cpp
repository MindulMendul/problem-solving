#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  vector<int> money;
  cin>>N;
  for(int i=0; i<N; i++){
    int m; cin>>m;
    money.push_back(m);
  }

  sort(money.begin(), money.end());

  int sum=0, sum_part=0;
  for(int i=0; i<N; i++){
    sum_part+=money.at(i);
    sum+=sum_part;
  }

  cout<<sum;
  return 0;
}