#include <iostream>
#include <queue>

using namespace std;

int N;
char arr[100][100];
int visited[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //init
  cin>>N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>>arr[i][j];
      visited[i][j]=0;
    }
  }

  //calculate
  int a1=0, a2=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      queue<pair<int, int>> q;
      if(!visited[i][j]) {
        q.push(make_pair(i,j));
        a1++;
      }
      while(q.size()>0){
        pair<int, int> point=q.front(); q.pop();
        int x=point.first, y=point.second;
        if(visited[x][y]) continue;
        visited[x][y]=1;
        char color=arr[x][y];
        for(int d=0; d<4; d++){
          if(x+dx[d]<0 || x+dx[d]>=N || y+dy[d]<0 || y+dy[d]>=N) continue;
          if(arr[x+dx[d]][y+dy[d]]==color){
            q.push(make_pair(x+dx[d],y+dy[d]));
          }
        }
      }
    }
  }

  //calculate
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      queue<pair<int, int>> q;
      if(visited[i][j]) {
        q.push(make_pair(i,j));
        a2++;
      }
      while(q.size()>0){
        pair<int, int> point=q.front(); q.pop();
        int x=point.first, y=point.second;
        if(!visited[x][y]) continue;
        visited[x][y]=0;
        char color=arr[x][y];
        for(int d=0; d<4; d++){
          if(x+dx[d]<0 || x+dx[d]>=N || y+dy[d]<0 || y+dy[d]>=N) continue;
          if(arr[x+dx[d]][y+dy[d]]==color){
            q.push(make_pair(x+dx[d],y+dy[d]));
          } else if(arr[x+dx[d]][y+dy[d]]=='G' && color=='R'){
            q.push(make_pair(x+dx[d],y+dy[d]));
          } else if(arr[x+dx[d]][y+dy[d]]=='R' && color=='G'){
            q.push(make_pair(x+dx[d],y+dy[d]));
          }  
        }
      }
    }
  }

  cout<<a1<<" "<<a2;

  return 0;
}
