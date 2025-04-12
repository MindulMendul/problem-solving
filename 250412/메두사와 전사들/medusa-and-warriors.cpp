#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int rdx[4]={-1,1,0,0};
int rdy[4]={0,0,-1,1};
int field[50][50];
int light[50][50];
int tmp_light[50][50];
int cnt_warrior[50][50];
int sr, sc, er, ec;
int cnt_move_warrior;
int stone_warrior;
int attack_warrior;

int back_x[50][50];
int back_y[50][50];
vector<pair<int, int> > warrior;
vector<pair<int, int> > route;

int get_distance(int x1, int y1, int x2, int y2){
    int xx=x1-x2; if(xx<0) xx*=-1;
    int yy=y1-y2; if(yy<0) yy*=-1;
    return xx+yy;
}

void init_cnt_warrior(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cnt_warrior[i][j]=0;
        }
    }
    for(int m=0; m<warrior.size(); m++){
        cnt_warrior[warrior[m].second][warrior[m].first]++;
    }
}

void init_tmp_light(){
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) tmp_light[i][j]=0;
}

void init_route(){
    init_tmp_light();
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {back_x[i][j]=0; back_y[i][j]=0;}
    queue<pair<int, int> > q;
    q.push(make_pair(sc, sr));
    tmp_light[sr][sc]=1;

    int tx, ty, flag=false;
    while(!q.empty()){
        pair<int, int> top=q.front(); q.pop();
        int x=top.first, y=top.second;

        if(x==ec && y==er){
            tx=x; ty=y;
            flag=true;
            break;
        }

        for(int d=0; d<4; d++){
            int xx=x+dx[d], yy=y+dy[d];
            if(xx<0 || xx>=N || yy<0 || y>=N) continue;
            if(tmp_light[yy][xx]) continue;
            if(field[yy][xx]) continue;
            q.push(make_pair(xx,yy));
            tmp_light[yy][xx]=1;
            back_x[yy][xx]=x;
            back_y[yy][xx]=y;
        }
    }

    if(!flag) return;

    while(!(tx==sc && ty==sr)){
        route.push_back(make_pair(tx, ty));
        int txx=tx, tyy=ty;
        tx=back_x[tyy][txx];
        ty=back_y[tyy][txx];
    }
    
    reverse(route.begin(), route.end());
}

void copy_light(){
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) light[i][j]=tmp_light[i][j];
}

int cnt_stone(){
    int res=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(cnt_warrior[i][j]>0 && tmp_light[i][j]==1) res+=cnt_warrior[i][j];
        }
    }
    return res;
}

int sight_up(){
    tmp_light[sr][sc]=1;
    for(int i=1; i<=N; i++){
        int x=sc, y=sr-i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(cnt_warrior[y+1][x]>0 || tmp_light[y+1][x]!=1) tmp_light[y][x]=2;
        else tmp_light[y][x]=1;
    }

    for(int i=1; i<=N; i++){
        int x=sc+i, y=sr-i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(tmp_light[y+1][x-1]==1 && cnt_warrior[y+1][x-1]==0) tmp_light[y][x]=1;
        for(int j=1; j<N; j++){
            int xx=x, yy=y-j;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(tmp_light[yy][xx]==2 || cnt_warrior[yy+1][xx]>0 || tmp_light[yy+1][xx]!=1) {
                tmp_light[yy][xx]=2;
                if(xx+1<N) tmp_light[yy][xx+1]=2;
            }
            else tmp_light[yy][xx]=1;
        }
    }

    for(int i=1; i<=N; i++){
        int x=sc-i, y=sr-i;
        if(x<0 || x>=N || y<0 || y>=N) break;
         if(tmp_light[y+1][x+1]==1 && cnt_warrior[y+1][x+1]==0) tmp_light[y][x]=1;
        for(int j=1; j<N; j++){
            int xx=x, yy=y-j;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(tmp_light[yy][xx]==2 || cnt_warrior[yy+1][xx]>0 || tmp_light[yy+1][xx]!=1) {
                tmp_light[yy][xx]=2;
                if(xx>0) tmp_light[yy][xx-1]=2;
            }
            else tmp_light[yy][xx]=1;
        }
    }

    tmp_light[sr][sc]=0;
    return cnt_stone();
}

int sight_down(){
    tmp_light[sr][sc]=1;
    for(int i=1; i<=N; i++){
        int x=sc, y=sr+i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(cnt_warrior[y-1][x]>0 || tmp_light[y-1][x]!=1) tmp_light[y][x]=2;
        else tmp_light[y][x]=1;
    }

    for(int i=1; i<=N; i++){
        int x=sc-i, y=sr+i;
        if(x<0 || x>=N || y<0 || y>=N) break;
         if(tmp_light[y-1][x+1]==1 && cnt_warrior[y-1][x+1]==0) tmp_light[y][x]=1;
        for(int j=1; j<N; j++){
            int xx=x, yy=y+j;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(tmp_light[yy][xx]==2 || cnt_warrior[yy-1][xx]>0 || tmp_light[yy-1][xx]!=1) {
                tmp_light[yy][xx]=2;
                if(xx>0) tmp_light[yy][xx-1]=2;
            }
            else tmp_light[yy][xx]=1;
        }
    }

    for(int i=1; i<=N; i++){
        int x=sc+i, y=sr+i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(tmp_light[y-1][x-1]==1 && cnt_warrior[y-1][x-1]==0) tmp_light[y][x]=1;
        for(int j=1; j<N; j++){
            int xx=x, yy=y+j;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(tmp_light[yy][xx]==2 || cnt_warrior[yy-1][xx]>0 || tmp_light[yy-1][xx]!=1) {
                tmp_light[yy][xx]=2;
                if(xx+1<N) tmp_light[yy][xx+1]=2;
            }
            else tmp_light[yy][xx]=1;
        }
    }

    tmp_light[sr][sc]=0;
    return cnt_stone();
}

int sight_left(){
    tmp_light[sr][sc]=1;
    for(int i=1; i<=N; i++){
        int x=sc-i, y=sr;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(cnt_warrior[y][x+1]>0 || tmp_light[y][x+1]!=1) tmp_light[y][x]=2;
        else tmp_light[y][x]=1;
    }
    

    for(int i=1; i<=N; i++){
        int x=sc-i, y=sr+i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(tmp_light[y-1][x+1]==1 && cnt_warrior[y-1][x+1]==0) tmp_light[y][x]=1;
        for(int j=1; j<N; j++){
            int xx=x-j, yy=y;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(tmp_light[yy][xx]==2 || cnt_warrior[yy][xx+1]>0 || tmp_light[yy][xx+1]!=1) {
                tmp_light[yy][xx]=2;
                if(yy+1<N) tmp_light[yy+1][xx]=2;
            }
            else tmp_light[yy][xx]=1;
        }
    }

    for(int i=1; i<=N; i++){
        int x=sc-i, y=sr-i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(tmp_light[y+1][x+1]==1 && cnt_warrior[y+1][x+1]==0) tmp_light[y][x]=1;
        for(int j=1; j<N; j++){
            int xx=x-j, yy=y;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(tmp_light[yy][xx]==2 || cnt_warrior[yy][xx+1]>0 || tmp_light[yy][xx+1]!=1) {
                tmp_light[yy][xx]=2;
                if(yy>0) tmp_light[yy-1][xx]=2;
            }
            else tmp_light[yy][xx]=1;
        }
    }

    tmp_light[sr][sc]=0;
    return cnt_stone();
}

int sight_right(){
    tmp_light[sr][sc]=1;
    for(int i=1; i<=N; i++){
        int x=sc+i, y=sr;
        if(x<0 || x>=N || y<0 || y>=N) break;
        if(cnt_warrior[y][x-1]>0 || tmp_light[y][x-1]!=1) tmp_light[y][x]=2;
        else tmp_light[y][x]=1;
    }

    for(int i=1; i<=N; i++){
        int x=sc+i, y=sr+i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        for(int j=0; j<N; j++){
            int xx=x+j, yy=y;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            tmp_light[yy][xx]=1;
        }
    }
    for(int i=1; i<=N; i++){
        int x=sc+i, y=sr-i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        for(int j=0; j<N; j++){
            int xx=x+j, yy=y;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            tmp_light[yy][xx]=1;
        }
    }

    for(int i=1; i<=N; i++){
        int x=sc+i, y=sr+i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        for(int j=0; j<N; j++){
            int xx=x+j, yy=y;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(cnt_warrior[yy][xx]>0 || tmp_light[yy][xx]!=1) {
                tmp_light[yy][xx+1]=2;
                if(yy+1<N) tmp_light[yy+1][xx+1]=2;
            }
        }
    }

    for(int i=1; i<=N; i++){
        int x=sc+i, y=sr-i;
        if(x<0 || x>=N || y<0 || y>=N) break;
        for(int j=0; j<N; j++){
            int xx=x+j, yy=y;
            if(xx<0 || xx>=N || yy<0 || yy>=N) break;
            if(cnt_warrior[yy][xx]>0 || tmp_light[yy][xx]!=1) {
                tmp_light[yy][xx+1]=2;
                if(yy>0) tmp_light[yy-1][xx+1]=2;
            }
        }
    }

    tmp_light[sr][sc]=0;
    return cnt_stone();
}

void sight(){
    stone_warrior=0;
    int stone;
    init_cnt_warrior();
    init_tmp_light(); stone=sight_up();
    if(stone_warrior<stone){stone_warrior=stone; copy_light();}
    init_tmp_light(); stone=sight_down();
    if(stone_warrior<stone){stone_warrior=stone; copy_light();}
    init_tmp_light(); stone=sight_left();
    if(stone_warrior<stone){stone_warrior=stone; copy_light();}
    init_tmp_light(); stone=sight_right();
    if(stone_warrior<stone){stone_warrior=stone; copy_light();}
}

void move_warrior(){
    cnt_move_warrior=0; attack_warrior=0;
    for(int m=warrior.size()-1; m>=0; m--){
        int wx=warrior[m].first, wy=warrior[m].second;
        int cur_wx=wx, cur_wy=wy;
        int prev_dis=get_distance(sc,sr,wx,wy);
        if(light[wy][wx]==1) continue;
        for(int d=0; d<4; d++){
            int xx=wx+dx[d], yy=wy+dy[d];
            if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
            if(light[yy][xx]==1) continue;
            int cur_dis=get_distance(sc,sr,xx,yy);
            if(cur_dis<prev_dis){
                cur_wx=xx; cur_wy=yy;
                prev_dis=cur_dis;
            }
        }
        if(!(cur_wx==wx && cur_wy==wy)){
            cnt_move_warrior++;
        }
        if(cur_wx==sc && cur_wy==sr){
            attack_warrior++;
            warrior.erase(warrior.begin()+m);
            continue;
        }
        warrior[m].first=cur_wx;
        warrior[m].second=cur_wy;
        wx=cur_wx;
        wy=cur_wy;

        for(int d=0; d<4; d++){
            int xx=wx+rdx[d], yy=wy+rdy[d];
            if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
            if(light[yy][xx]==1) continue;
            int cur_dis=get_distance(sc,sr,xx,yy);
            if(cur_dis<prev_dis){
                cur_wx=xx; cur_wy=yy;
                prev_dis=cur_dis;
            }
        }
        if(!(cur_wx==wx && cur_wy==wy)){
            cnt_move_warrior++;
        }
        if(cur_wx==sc && cur_wy==sr){
            attack_warrior++;
            warrior.erase(warrior.begin()+m);
            continue;
        }
        warrior[m].first=cur_wx;
        warrior[m].second=cur_wy;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin>>N>>M;
    cin>>sr>>sc>>er>>ec;
    for(int i=0; i<M; i++) {
        int x, y; cin>>y>>x;
        warrior.push_back(make_pair(x,y));
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>field[i][j];
        }
    }
    init_route();
    if(route.size()==0) {
        cout<<-1;
        return 0;
    }
   
    for(int turn=1; turn<route.size(); turn++){
        // 1. 메두사 이동
        sc=route[turn-1].first;
        sr=route[turn-1].second;
        for(int m=warrior.size()-1; m>=0; m--){
            if(warrior[m].first==sc && warrior[m].second==sr){
                warrior.erase(warrior.begin()+m);
            }
        }

        sight();

        // if(turn>6){
        //     cout<<"turn"<<turn<<"\n";
        //     for(int i=0; i<N; i++){
        //         for(int j=0; j<N; j++){
        //             cout<<light[i][j]<<"/"<<cnt_warrior[i][j]<<" ";
        //         }cout<<endl;
        //     }
        // }
        move_warrior();
        // cout<<"warr"<<warrior.size()<<endl;

        cout<<cnt_move_warrior<<" "<<stone_warrior<<" "<<attack_warrior<<"\n";
    }

    cout<<0;
    return 0;
}