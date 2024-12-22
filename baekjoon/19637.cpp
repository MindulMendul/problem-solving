#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<string, int>> medal;

string ifif(int power){
  string res="";
  int s=0, e=medal.size()-1, mid;
  while(s<=e){
    mid=(s+e)/2;
    if(power<=medal[mid].second){
      e=mid-1;
    } else {
      s=mid+1;
    }
  }

  if(power>medal[mid].second) return medal[mid+1].first;
  else return medal[mid].first;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  cin>>N>>M;
  for(int i=0; i<N; i++){
    string s; int n;
    cin>>s>>n;
    medal.push_back(make_pair(s,n));
  }

  for(int i=0; i<M; i++){
    int a; cin>>a;
    cout<<ifif(a)<<'\n';
  }
  
  return 0;
}