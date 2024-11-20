#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int>b) {
        if(a.second==b.second) return a.first>b.first;
        return a.second>b.second;
    }
};

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for(int i=0; i<N; i++){
        int s, e;
        cin>>s>>e;
        pq.push(make_pair(s, e));
    }

    int cur=0, ans=0;

    while(!pq.empty()){
        int s = pq.top().first;
        int e = pq.top().second;
        pq.pop();
        if(s<cur) continue; // 시작 시간이 적어도 현재 시간보다 느려야 함.
        
        ans++;
        cur=e;
    }

    cout<<ans;
    return 0;
}
