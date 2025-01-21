#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getLoc(int x, int y) return 9*y+x;

// 숫자를 채우면 그 라인에서 후보군을 없앰
void fillSudoku(vector<vector>& sudoku, vector<vector<int>>& num, int loc, int val){
  int x=loc%9, y=loc/9;
  
  // col
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      int l=loc(x,i);
      if(num[l][j]==val) {
        num[l][j]=0;
        break;
      }
    }
  }

  // row
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      int l=loc(i,y);
      if(num[l][j]==val) {
        num[l][j]=0;
        break;
      }
    }
  }

  // square
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      int l=loc(i,y);

      (x/3)*3+(y/3);
      if(num[l][j]==val) {
        num[l][j]=0;
        break;
      }
    }
  }
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> sudoku(9, vector<int>(9));
  vector<vector<int>> num(81, vector<int>(9));
  vector<int> v;

  for(int i=0; i<9; i++){
    string str; cin>>str;
    for(int j=0; j<9; j++){
      sudoku[i][j]=str[j]-'0';
      if(sudoku[i][j]==0){
        v.push_back(9*i+j);
      }
    }
  }



  return 0;
}