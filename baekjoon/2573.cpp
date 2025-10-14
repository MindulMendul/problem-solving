#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int board[300][300];
int N, M;

int cnt_piece(){
    int cnt=0;

    bool visited[N][M];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            visited[i][j]=(board[i][j]==0);
        }
    }

    queue<pair<int, int>> q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            if(visited[i][j]) continue;
            visited[i][j]=true;
            q.push(make_pair(i,j));
            while(!q.empty()){
                int x=q.front().second, y=q.front().first;
                q.pop();
                for(int d=0; d<4; d++){
                    int xx=x+dx[d], yy=y+dy[d];
                    if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
                    if(visited[yy][xx]) continue;
                    visited[yy][xx]=true;
                    q.push(make_pair(yy, xx));
                }
            }
            cnt++;
        }
    }

    return cnt;
}

void melt(){
    int tmp_board[N][M];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            tmp_board[i][j]=board[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            for(int d=0; d<4; d++){
                if(tmp_board[i][j]==0) break;
                int xx=j+dx[d], yy=i+dy[d];
                if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
                if(board[yy][xx]>0) continue;
                tmp_board[i][j]--;
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            board[i][j]=tmp_board[i][j];
        }
    }
}

void print(){
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

	cin>>N>>M;

    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>board[i][j];
    for(int t=0; t<1001; t++){
        //print();
        int cnt=cnt_piece();
        if(cnt==0) {cout<<0; return 0;}
        if(cnt>1) {cout<<t; return 0;}
        melt();
    }

    cout<<0;
    return 0;
}