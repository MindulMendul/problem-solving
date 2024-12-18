#include <iostream>
#include <queue>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  int TC;
  cin>>TC;

  for(int tc=1; tc<=TC; tc++){
    int cur, goal;
    cin>>cur>>goal;
    queue<pair<int, pair<int, long long int>>> q;
    vector<int> visited; visited.resize(10000, 0);
    visited[cur]=1;
    q.push(make_pair(cur, make_pair(0, 0)));
    while(!q.empty()){
      pair<int, pair<int, long long int>> t=q.front(); q.pop();
      int a=t.first;
      int cnt=t.second.first;
      long long int cmd=t.second.second;
      if(a==goal) {
        vector<int> v;
        while(cnt>0){
          int cmd_d=cmd%4;
          if(cmd_d==0){v.push_back(0);}
          if(cmd_d==1){v.push_back(1);}
          if(cmd_d==2){v.push_back(2);}
          if(cmd_d==3){v.push_back(3);}
          cmd/=4; cnt--;
        }
        for(int i=v.size()-1; i>=0; i--){
          if(v[i]==0) cout<<"D";
          if(v[i]==1) cout<<"S";
          if(v[i]==2) cout<<"L";
          if(v[i]==3) cout<<"R";
        }
        cout<<'\n';
        break;
      }

      int ad=(a*2)%10000, as=(a+9999)%10000, al=(a*10)%10000+a/1000, ar=(a/10)+1000*(a%10);
      if(!visited[ad]) {visited[ad]=1; q.push(make_pair(ad, make_pair(cnt+1, 4*cmd+0)));}
      if(!visited[as]) {visited[as]=1; q.push(make_pair(as, make_pair(cnt+1, 4*cmd+1)));}
      if(!visited[al]) {visited[al]=1; q.push(make_pair(al, make_pair(cnt+1, 4*cmd+2)));}
      if(!visited[ar]) {visited[ar]=1; q.push(make_pair(ar, make_pair(cnt+1, 4*cmd+3)));}
    }
  }
	
  return 0;
}
