#include <iostream>

using namespace std;

int map[16][16];
int N;

int garoSearch(int x, int y);
int seroSearch(int x, int y);
int daegakSearch(int x, int y);

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>map[i][j];
  cout<<garoSearch(0, 0);
  
  return 0;
}

int garoSearch(int x, int y){
  if(x<0 || y<0 || x>N || y>=N) return 0;
  if(map[y][x] || map[y][x+1]) return 0;
  if(x==N-2 && y==N-1) return 1;
  map[y][x]=1;
  int ans=garoSearch(x+1, y) + daegakSearch(x+1, y);
  map[y][x]=0;
  return ans;
}

int daegakSearch(int x, int y){
  if(x<0 || y<0 || x>N || y>N) return 0;
  if(map[y][x] || map[y+1][x] || map[y][x+1] || map[y+1][x+1]) return 0;
  if(x==N-2 && y==N-2) return 1;
  map[y][x+1]=1; map[y+1][x]=1; map[y][x]=1;
  int ans=garoSearch(x+1, y+1)+daegakSearch(x+1, y+1)+seroSearch(x+1, y+1);
  map[y][x+1]=0; map[y+1][x]=0; map[y][x]=0;

  return ans;
}

int seroSearch(int x, int y){
  if(x<0 || y<0 || x>=N || y>N) return 0;
  if(map[y][x] || map[y+1][x]) return 0;
  if(x==N-1 && y==N-2) return 1;
  map[y][x]=1;
  int ans=daegakSearch(x, y+1) + seroSearch(x, y+1);
  map[y][x]=0;
  return ans;
}