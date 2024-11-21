#include <iostream>
#include <vector>
#include <queue>

#define INF 1050000000

using namespace std;

vector<pair<int, int>> edge_to[1000];
vector<pair<int, int>> edge_from[1000];
int to[1000];
int from[1000];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, X;
    cin>>N>>M>>X; X--;

    // init
    for(int i=0; i<N; i++){
        to[i]=-INF;
        from[i]=-INF;
    }

    for(int i=0; i<M; i++){
        int s, e, c; cin>>s>>e>>c;
        edge_to[s-1].push_back(make_pair(-c, e-1));
        edge_from[e-1].push_back(make_pair(-c, s-1));
    }
    to[X]=0; from[X]=0;

    //calculate to
    priority_queue<pair<int, int>> pq_to;
    pq_to.push(make_pair(0, X));
    while(!pq_to.empty()){
        int dis=pq_to.top().first;
        int cur=pq_to.top().second;
        pq_to.pop();
        if(dis<to[cur]) continue;
        for(int i=0; i<edge_to[cur].size(); i++){
            int next_dis = dis+edge_to[cur][i].first;
            int next_ind = edge_to[cur][i].second;
            if(to[next_ind]<next_dis){
                to[next_ind]=next_dis;
                pq_to.push(make_pair(next_dis, next_ind));
            }
        }
    }

    //calculate from
    priority_queue<pair<int, int>> pq_from;
    pq_from.push(make_pair(0, X));
    while(!pq_from.empty()){
        int dis=pq_from.top().first;
        int cur=pq_from.top().second;
        pq_from.pop();
        if(dis<from[cur]) continue;
        
        for(int i=0; i<edge_from[cur].size(); i++){
            int next_dis = dis+edge_from[cur][i].first;
            int next_ind = edge_from[cur][i].second;
            if(from[next_ind]<next_dis){
                from[next_ind]=next_dis;
                pq_from.push(make_pair(next_dis, next_ind));
            }
        }
    }

    int ans=0;
    for(int i=0; i<N; i++){
        int sum=to[i]+from[i];
        if(sum<ans) ans=sum;
    }
    cout<<-ans;

    return 0;
}
