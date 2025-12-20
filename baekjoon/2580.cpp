#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> left_loc;
int board[9][9];

void print_board(){
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<board[i][j]<<" ";
        }cout<<"\n";
    }
}

bool num_check(int num, int x, int y){
    for(int i=0; i<9; i++){
        if(board[y][i]==num) return false;
        if(board[i][x]==num) return false;
    }

    for(int i=(y/3)*3; i<(y/3+1)*3; i++){
        for(int j=(x/3)*3; j<(x/3+1)*3; j++){
            if(board[i][j]==num) return false;
        }
    }

    return true;
}

bool dfs(int dep){
    int x=left_loc[dep].second, y=left_loc[dep].first;
    if(dep==left_loc.size()) {
        return true;
    }
    for(int i=1; i<=9; i++){
        if(!num_check(i,x,y)) continue;
        board[y][x]=i;
        if(dfs(dep+1)) return true;
        board[y][x]=0;
    }
    return false;
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>board[i][j];
            if(board[i][j]==0) left_loc.push_back(make_pair(i,j));
        }
    }

    dfs(0);
    print_board();

    return 0;
}