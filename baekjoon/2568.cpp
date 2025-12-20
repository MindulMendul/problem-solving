#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2100000000

int N;
int arr[100'000];
int brr[100'000];
vector<pair<int, int>> us_arr;
vector<int> lis;
int ind[100'000];

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
  }
};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  for(int i=0; i<N; i++){
    int x, y; cin>>x>>y;
    us_arr.push_back(make_pair(x, y));
  }
  
  sort(us_arr.begin(), us_arr.end(), cmp());
  for(int i=0; i<N; i++){
    arr[i]=us_arr[i].first;
    brr[i]=us_arr[i].second;
  }
  
  for(int i=0; i<N; i++){
    if(lis.size()==0 || lis[lis.size()-1]<brr[i]){
      ind[i]=lis.size();
      lis.push_back(brr[i]);
    } else {
      int s=0, e=lis.size()-1;
      int mid;
      while(s<e){
        mid=(s+e)/2;
        if(lis[mid]<brr[i]) s=mid+1;
        else e=mid;
      }
      lis[s]=brr[i];
      ind[i]=s;
    }
  }

  cout<<N-lis.size()<<"\n";
  int find_ind=lis.size()-1;
  for(int i=N-1; i>=0; i--){
    if(ind[i]==find_ind){
      arr[i]=MAX;
      find_ind--;
    }
  }

  for(int i=0; i<N; i++){
    if(arr[i]==MAX) continue;
    cout<<arr[i]<<'\n';
  }
  
  return 0;
}
