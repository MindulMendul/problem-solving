#include <iostream>
#include <string>

#define MAX 2100000000

using namespace std;

int paper[6];
int board[10][10];
int ans=MAX;

bool check_paper(int l, int i, int j){
  for(int y=0; y<l; y++) for(int x=0; x<l; x++) {
    int yy=i+y, xx=j+x;
    if(yy>=10 || xx>=10) return false;
    if(board[i+y][j+x]==0) return false;
  }

  return true;
}

void attach_paper(int l, int i, int j){
  for(int y=0; y<l; y++) for(int x=0; x<l; x++)
    board[i+y][j+x]=0;
}

void detach_paper(int l, int i, int j){
  for(int y=0; y<l; y++) for(int x=0; x<l; x++)
    board[i+y][j+x]=1;
}

bool is_finish(){
  for(int y=0; y<10; y++) for(int x=0; x<10; x++)
    if(board[y][x]==1) return false;
  return true;
}

void back_track(int cnt, int ind){
  int i=ind/10, j=ind%10;
  if(i==10) {
    ans=min(ans, cnt);
    return;
  }

  if(board[i][j]==0) {
    back_track(cnt, ind+1);
    return;
  }

  for(int l=5; l>=1; l--){
    if(paper[l]==0) continue;
    if(!check_paper(l, i, j)) continue;
    paper[l]--;
    attach_paper(l, i, j);
    back_track(cnt+1, ind+l);
    paper[l]++;
    detach_paper(l, i, j);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      cin>>board[i][j];
    }
  }

  paper[0]=0;
  for(int l=1; l<=5; l++) paper[l]=5;

  back_track(0,0);
  if(ans==MAX) cout<<-1;
  else cout<<ans;
  
  return 0;
}
