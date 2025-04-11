#include <iostream>
#include <vector>

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int N,M,H,K;
int field[100][100];
int man_x[10000];
int man_y[10000];
int man_d[10000];
int tree_x[10000];
int tree_y[10000];

vector<pair<int, pair<int, int>>> route;

int get_dis(int x1, int y1, int x2, int y2){
    int xx=x1-x2; if(xx<0) xx*=-1;
    int yy=y1-y2; if(yy<0) yy*=-1;
    return xx+yy;
}

void init_route(int n, int k){
    int move_cnt=0, dir=0, dis=1;
    int x=n/2, y=n/2;
    while(1){
        for(int i=0; i<dis; i++){
            if(x<0 || x>=n || y<0 || y>=n) return;
            route.push_back(make_pair(dir,make_pair(x, y)));

            x+=dx[dir], y+=dy[dir];
        }

        move_cnt++;
        dir=(dir+1)%4;
        if(move_cnt==2){
            move_cnt=0;
            dis++;
        }
    }
}

int find_man(int route_ind,int route_dir, int cur_turn){
    int cnt=0;
    int dir=route[route_ind].first;
    if(route_dir==0) dir=(route[route_ind-1].first+2)%4;
    int rx=route[route_ind].second.first-dx[dir];
    int ry=route[route_ind].second.second-dy[dir];

    for(int i=0; i<3; i++){
        rx+=dx[dir]; ry+=dy[dir];
        //if(cur_turn==42) cout<<"dir"<<dir<<"/"<<rx<<" "<<ry<<"asdf"<<endl;
        if(rx<0 || rx>=N || ry<0 || ry>=N) break;

        for(int m=0; m<M; m++){
            if(man_x[m]==rx && man_y[m]==ry) {
                bool is_tree=false;
                for(int h=0; h<H; h++){
                    if(tree_x[h]==man_x[m] && tree_y[h]==man_y[m]) {
                        is_tree=true;
                        break;
                    }
                }
                if(is_tree) continue;
                //cout<<route[route_ind].second.first<<","<<route[route_ind].second.second<<" / "<<man_x[m]<<","<<man_y[m]<<endl;
                cnt++;
                man_x[m]=-100'000'000;
                man_y[m]=-100'000'000;
            }
        }
    }
    // cout<<cur_turn*cnt<<"/";
    return cur_turn*cnt;
}

int main() {
    cin>>N>>M>>H>>K;
    for(int i=0; i<M; i++) {
        cin>>man_y[i]>>man_x[i]>>man_d[i];
        man_x[i]--; man_y[i]--;
    }
    for(int i=0; i<H; i++) {
        cin>>tree_y[i]>>tree_x[i];
        tree_x[i]--; tree_y[i]--;
    }
    
    init_route(N, K);
    int ans=0, route_ind=0, route_dir=1;
    int rx=route[route_ind].second.first;
    int ry=route[route_ind].second.second;

    for(int turn=1; turn<=K; turn++){
        for(int m=0; m<M; m++){
            if(get_dis(rx, ry, man_x[m], man_y[m])>3) continue;
            int m_x=man_x[m]+dx[man_d[m]], m_y=man_y[m]+dy[man_d[m]];
            if(m_x<0 || m_x>=N || m_y<0 || m_y>=N){
                man_d[m]=(man_d[m]+2)%4;
                m_x=man_x[m]+dx[man_d[m]];
                m_y=man_y[m]+dy[man_d[m]];
            }
            if(m_x==rx && m_y==ry) continue;
            man_x[m]=m_x;
            man_y[m]=m_y;
        }

        route_ind+=(route_dir)?1:-1;
        if(route_ind==route.size()-1) {route_dir=0;}
        else if(route_ind==0){route_dir=1;}

        rx=route[route_ind].second.first;
        ry=route[route_ind].second.second;

        ans+=find_man(route_ind, route_dir, turn);
        // if(turn>15){
        //     cout<<ans<<" ";
        //     cout<<" turn"<<turn<<" dir"<<route[route_ind].first<<" rx"<<rx<<","<<ry<<"/";
        //     for(int m=0; m<M; m++){
        //         if(man_x[m]>-1)cout<<man_x[m]<<","<<man_y[m]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    cout<<ans;
    return 0;
}