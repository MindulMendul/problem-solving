#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
  int d;
  int s;
  int m;
} fireball;

int N, M, K;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};
queue<fireball> map[50][50];
queue<fireball> after_map[50][50];

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin>>N>>M>>K;
  for(int i=0; i<M; i++){
    int y, x, m, s, d;
    cin>>y>>x>>m>>s>>d;
    fireball fb; fb.m=m; fb.s=s; fb.d=d;
    map[y-1][x-1].push(fb);
  }

  for(int tc=1; tc<=K; tc++){  
    // cout<<"TC"<<tc<<endl;  
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        // if(map[i][j].empty()){
        //   cout<<"0/0/0 ";
        // }
        while(!map[i][j].empty()){
          fireball fb=map[i][j].front(); map[i][j].pop();
          
          int xx=j+fb.s*dx[fb.d], yy=i+fb.s*dy[fb.d];
          xx%=N; yy%=N; if(xx<0) xx+=N; if(yy<0) yy+=N;
          after_map[yy][xx].push(fb);
         // cout<<fb.m<<"/"<<fb.s<<"/"<<fb.d<<" ";
        }
      }//cout<<endl;
    }//cout<<endl;

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        int _size=after_map[i][j].size();
        if(_size==0) continue;
        if(_size==1){
          map[i][j].push(after_map[i][j].front());
          after_map[i][j].pop();
          continue;
        }
        fireball fb_sum; 
        fb_sum.d=after_map[i][j].front().d; fb_sum.s=0; fb_sum.m=0;
        bool flag=false;
        while(!after_map[i][j].empty()){
          fireball fb=after_map[i][j].front(); after_map[i][j].pop();
          fb_sum.m+=fb.m; fb_sum.s+=fb.s;
          if(!flag && (fb_sum.d+fb.d)%2==1) flag=true;
        }

        fb_sum.m=fb_sum.m/5;
        fb_sum.s=fb_sum.s/_size;
        fb_sum.d=flag?1:0;
        if(fb_sum.m==0) continue;
        
        map[i][j].push(fb_sum); fb_sum.d+=2;
        map[i][j].push(fb_sum); fb_sum.d+=2;
        map[i][j].push(fb_sum); fb_sum.d+=2;
        map[i][j].push(fb_sum);
      }
    }
  }

  int ans=0;
  //cout<<"FINAL\n";
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      // if(map[i][j].empty()){
      //     cout<<"0/0/0 ";
      //   }
      while(!map[i][j].empty()){
        fireball fb=map[i][j].front(); map[i][j].pop();
        //cout<<fb.m<<"/"<<fb.s<<"/"<<fb.d<<" ";
        ans+=fb.m;
      }
    }//cout<<endl;
  }

  cout<<ans;
  return 0;
}
