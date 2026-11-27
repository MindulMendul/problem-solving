#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N;
int board[100][100];
int visited[100][100];

int stamp = 0;
pair<int, int> q[10000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(int low, int high){
    // 출발점과 도착점 사전 검사
    if(board[0][0] < low || board[0][0] > high)
        return false;

    if(board[N-1][N-1] < low || board[N-1][N-1] > high)
        return false;

    // visited 초기화 대신 방문 세대 번호 증가
    ++stamp;

    // 고정 크기 배열 큐
    int front = 0, rear = 0;

    q[rear++] = {0, 0};
    visited[0][0] = stamp;

    while(front < rear){
        auto [x, y] = q[front++];

        if(x == N-1 && y == N-1)
            return true;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if(visited[nx][ny] == stamp)
                continue;

            if(board[nx][ny] < low || board[nx][ny] > high)
                continue;

            visited[nx][ny] = stamp;
            q[rear++] = {nx, ny};
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int board_min = 200;
    int board_max = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];

            board_min = min(board_min, board[i][j]);
            board_max = max(board_max, board[i][j]);
        }
    }

    int a = board[0][0];
    int b = board[N-1][N-1];

    // 투 포인터 탐색 범위 제한
    int start = board_min;
    int end = max(a, b);
    int limit = min(a, b);

    int ans = board_max - board_min;

    while(end <= board_max && start <= limit){
        if(bfs(start, end)){
            ans = min(ans, end - start);

            // 이론적으로 가능한 최솟값에 도달
            if(ans == abs(a - b))
                break;

            start++;
        }
        else{
            end++;
        }
    }

    cout << ans;

    return 0;
}