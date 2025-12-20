#include <iostream>
#include <deque>

using namespace std;

#define MAX 100'000'000

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int N, M;
int board[100][100];
int cost[100][100];

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin>>M>>N; 

    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        for(int j=0; j<M; j++){
            board[i][j]=(int) str[j]-'0';
            cost[i][j]=MAX;
        }
    }

    cost[0][0]=0;

    deque<pair<int, int>> dq;
    dq.push_back({0,0});
    while(!dq.empty()){
        int y=dq.front().first, x=dq.front().second;
        dq.pop_front();

        if(y==N-1 && x==M-1) {
            cout<<cost[y][x];
            return 0;
        }

        for(int d=0; d<4; d++){
            int xx=x+dx[d], yy=y+dy[d];
            if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
            int new_c=cost[y][x]+board[yy][xx];
            if(cost[yy][xx]<=new_c) continue;
            cost[yy][xx]=new_c;
            if(board[yy][xx]==1) dq.push_back({yy, xx});
            else dq.push_front({yy,xx}); 
        }
    }

    cout<<cost[N-1][M-1];
    return 0;
}