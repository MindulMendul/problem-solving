#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int R, C, M;
int board[100][100];
int tmp_board[100][100];
int visited[100][100];

int shark_x[10001];
int shark_y[10001];
int shark_spd[10001];
int shark_dir[10001];
int shark_size[10001];

void print_board(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<((char)(board[i][j]+'A'-1))<<" ";
        }cout<<endl;
    }cout<<endl;
}

void init_tmp_board(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            tmp_board[i][j]=0;
        }
    }
}

void copy_board(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            board[i][j]=tmp_board[i][j];
            shark_x[board[i][j]]=j;
            shark_y[board[i][j]]=i;
        }
    }
}

int find_shark(int h_x){
    for(int i=0; i<R; i++) if(board[i][h_x]>0) return board[i][h_x];
    return -1;
}

void kill_shark(int shark_i){
    board[shark_y[shark_i]][shark_x[shark_i]]=0;
    shark_size[shark_i]=-1;
}

bool is_dead_shark(int shark_i){
    return shark_size[shark_i]==-1;
}

void move_shark(int shark_i){
    int sx=shark_x[shark_i];
    int sy=shark_y[shark_i];
    int sd=shark_dir[shark_i];
    int ss=shark_spd[shark_i];

    sx+=dx[sd]*ss; sx%=2*(C-1);
    sy+=dy[sd]*ss; sy%=2*(R-1);
    //cout<<(char)(shark_i+'A'-1)<<"/"<<sx<<","<<sy<<"\n";
    if(sx<0) {sx=-sx; shark_dir[shark_i]=2;}
    else if(sx>=C) {sx=2*(C-1)-sx; shark_dir[shark_i]=3;}
    if(sx<0) {sx=-sx; shark_dir[shark_i]=2;}
    else if(sx>=C) {sx=2*(C-1)-sx; shark_dir[shark_i]=3;}

    if(sy<0) {sy=-sy; shark_dir[shark_i]=1;}
    else if(sy>=R) {sy=2*(R-1)-sy; shark_dir[shark_i]=0;}
    if(sy<0) {sy=-sy; shark_dir[shark_i]=1;}
    else if(sy>=R) {sy=2*(R-1)-sy; shark_dir[shark_i]=0;}

    // 해당 위치에 겹치는 상어가 있는지 체크
    // 이거 문제점! 상어를 전부 움직인 다음에 체크하는 게 올바른 구현법임!
    if(tmp_board[sy][sx]>0){
        if(shark_size[shark_i]>shark_size[tmp_board[sy][sx]]){
            //cout<<"kill"<<tmp_board[sy][sx]<<endl;
            kill_shark(tmp_board[sy][sx]);
            tmp_board[sy][sx]=shark_i;
        } else {
            //cout<<"kill"<<shark_i<<endl;
            kill_shark(shark_i);
        }
    } else {
        tmp_board[sy][sx]=shark_i;
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin>>R>>C>>M;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            board[i][j]=0;
        }
    }

    for(int i=1; i<=M; i++){
        cin>>shark_y[i]>>shark_x[i]>>shark_spd[i]>>shark_dir[i]>>shark_size[i];
        shark_y[i]--;
        shark_x[i]--;
        shark_dir[i]--;
        board[shark_y[i]][shark_x[i]]=i;
    }

    int ans=0;
    for(int h_x=0; h_x<C; h_x++){
        // step 1. 낚시왕 이동
        // 은 h_x++ 로 이미 구현 끝
 
        // step 2. 낚시왕이 상어 잡는 거
        int shark_i=find_shark(h_x);
        if(shark_i>-1){// 잡은 상어가 있을 떄만 더해주기
            ans+=shark_size[shark_i];
            kill_shark(shark_i);
        }

        // step 3. 상어 이동
        init_tmp_board();
        for(int i=1; i<=M; i++){
            if(is_dead_shark(i)) continue; // 죽은 상어라면 의미 없음
            move_shark(i);
        }
        copy_board();
    }

    cout<<ans;

    return 0;
}