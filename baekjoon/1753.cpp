// make_pair로 priority_queue 할 때, struct cmp 만들어서 하는 것보다, first 크기 비교하게 하는 게 더 빠름!

#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000

using namespace std;

vector<pair<int, int>> edge[300001];
int dp[20001];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E; cin>>V>>E;
    int start; cin>>start; start--;

    for(int i=0; i<E; i++){
        int u,v,w; cin>>u>>v>>w;
        edge[u-1].push_back(make_pair(-w, v-1));
    }

    for(int i=0; i<V; i++){
        dp[i]=-INF;
    }

    priority_queue<pair<int, int>> pq;
    dp[start]=0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int dis=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(dis<dp[cur]) continue;
        for(int i=0; i<edge[cur].size(); i++){
            int nxt_dis=dis+edge[cur][i].first;
            int nxt_ind=edge[cur][i].second;
            if(dp[nxt_ind]<nxt_dis) {
                dp[nxt_ind]=nxt_dis;
                pq.push(make_pair(nxt_dis, nxt_ind));
            }
        }
    }

    for(int i=0; i<V; i++){
        if(dp[i]==-INF) cout<<"INF"<<'\n';
        else cout<<-dp[i]<<'\n';
    }

    return 0;
}
