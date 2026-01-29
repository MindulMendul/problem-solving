#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[4]={0,0,-1,1};
int ddy[4]={-1,1,0,0};
int visited[100][100];
int field[100][100];

vector<pair<int, int>> transfer;

void print_field(){
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<field[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

void dang(){
    int s=0, e=0;
    while(e<transfer.size()){
        int ex=transfer[e].second, ey=transfer[e].first;
        e++;
        if(field[ey][ex]==0) continue;
        int sx=transfer[s].second, sy=transfer[s].first;
        s++;
        if(e>s) {
            field[sy][sx]=field[ey][ex];
            field[ey][ex]=0;
        }
    }
}

long long int explode(){
    int s=-1, e=0;
    int num=0, cnt=0;
    long long int res=0;
    while(e<transfer.size()){
        int ex=transfer[e].second, ey=transfer[e].first;
        if(field[ey][ex]==num){
            cnt++; e++;
        } else {
            if(cnt>=4) {
                // 예술은 폭발이다
                while(s<e){
                    int sx=transfer[s].second, sy=transfer[s].first;
                    res+=(long long int) field[sy][sx];
                    field[sy][sx]=0;
                    s++;
                }
            }
            s=e; e++;
            num=field[ey][ex];
            cnt=1;
        }
    }
    return res;
}

void fill(){
    int e=0, num=0, cnt=0;
    vector<int> cur;
    while(e<transfer.size()){
        int ex=transfer[e].second, ey=transfer[e].first;
        if(field[ey][ex]==num){
            cnt++; e++;
        } else {
            e++;
            if(num==0) {
                num=field[ey][ex];
                cnt=1;
                continue;
            }
            cur.push_back(cnt);
            cur.push_back(num);
            num=field[ey][ex];
            cnt=1;
            if(field[ey][ex]==0) break;
        }
    }
    e=0;
    while(e<cur.size() && e<transfer.size()){
        int ex=transfer[e].second, ey=transfer[e].first;
        field[ey][ex]=cur[e++];
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin>>N>>M;
    int x=0, y=0, d=0, p;
    long long int score=0;
    transfer.push_back(make_pair(0,0));
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        visited[i][j]=0;
        cin>>field[i][j];
    }

    visited[0][0]=1;
    while(transfer.size()<N*N){
        int xx=x+dx[d], yy=y+dy[d];
        if(xx<0 || xx>=N || yy<0 || yy>=N || visited[yy][xx]){d=(d+1)%4; continue;}
        visited[yy][xx]=1;
        transfer.push_back(make_pair(yy,xx));
        x=xx; y=yy;
    }
    transfer.pop_back();
    reverse(transfer.begin(), transfer.end());

    for(int tc=1; tc<=M; tc++){
        cin>>d>>p; d--;
        x=N/2; y=N/2;
        for(int i=0; i<p; i++){
            x+=ddx[d]; y+=ddy[d];
            field[y][x]=0;
        }

        long long int explodingArt=1;
        while(explodingArt>0){
            dang();
            explodingArt=explode();
            score+=explodingArt;
        }
        fill();
        //print_field();
    }
    cout<<score;
    return 0;
}
