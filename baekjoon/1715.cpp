#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  priority_queue<long long int> pq;
  for(int i=0; i<N; i++){
    int a; cin>>a;
    pq.push(-a);
  }

  long long int sum=0;
  while(pq.size()>1){
    long long int a=pq.top(); pq.pop();
    long long int b=pq.top(); pq.pop();
    sum-=a+b;
    pq.push(a+b);
  }
  cout<<sum;
  
  return 0;
}
