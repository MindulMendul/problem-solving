#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char Delimiter) {
  istringstream iss(str); 
  string buffer;

  vector<string> result;

  while (getline(iss, buffer, Delimiter)) {
    result.push_back(buffer);
  }

  return result;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin>>T;
  for(int tc=1; tc<=T; tc++){
    int N;
    bool flag=false;
    string cmd, arr;
    cin>>cmd>>N>>arr;
    arr=arr.substr(1, arr.size()-2);
    vector<string> vtmp=split(arr, ',');
    vector<string> v;
  
    for(int i=0; i<vtmp.size(); i++){
      v.push_back(vtmp[i]);
    }

    int h=0, t=v.size()-1, dir=0;
    for(int i=0; i<cmd.size(); i++){
      if(cmd[i]=='R'){
        dir=(dir==0)?1:0;
      } else if(cmd[i]=='D'){
        if(h>t){flag=true; cout<<"error"<<'\n'; break;}
        if(dir==0) h++; else t--;
      }
    }

    if(flag) continue;

    cout<<'[';
    if(dir==0){
      for(int i=h; i<=t; i++){
        cout<<v[i];
        if(i+1<=t) cout<<',';
      }
    } else {
      for(int i=t; i>=h; i--){
        cout<<v[i];
        if(i-1>=h) cout<<',';
      }
    }
    
    cout<<"]\n";
  }

  return 0;
}
