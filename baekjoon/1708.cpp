#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> pii;

int N;
int s_p;
vector<pii> p(100'000);

void swap(int a, int b){
    lli tmp=p[a].first; p[a].first=p[b].first; p[b].first=tmp;
    tmp=p[a].second; p[a].second=p[b].second; p[b].second=tmp;
}

lli ccw(pii a, pii b, pii c){
    lli xx1=b.first-a.first, yy1=b.second-a.second;
    lli xx2=c.first-b.first, yy2=c.second-b.second;
    lli det=xx1*yy2-xx2*yy1;
    if(det>0) return 1;
    if(det<0) return -1;
    return 0;
}

lli dis(pii a, pii b, pii c){
    lli xx1=a.first-b.first, yy1=a.second-b.second;
    lli xx2=b.first-c.first, yy2=b.second-c.second;
    lli d1=xx1*xx1+yy1*yy1;
    lli d2=xx2*xx2+yy2*yy2;
    return d1<d2;
}

struct cmp {
    bool operator()(pii a, pii b){
        lli det=ccw(p[0], a, b);
        if(det>0) return 1;
        if(det<0) return 0;
        return dis(a, p[0], b);
    }
};

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin>>N; s_p=0;
    for(int i=0; i<N; i++) {
        cin>>p[i].first>>p[i].second; // first:x, second:y
        if(p[s_p].first>p[i].first) s_p=i;
        if(p[s_p].first==p[i].first && p[s_p].second>p[i].second) s_p=i;
    }

    swap(0, s_p);
    sort(p.begin()+1, p.begin()+N, cmp());

    vector<int> __stack;
    __stack.push_back(0);
    __stack.push_back(1);
    s_p=2;

    while(s_p<N){
        lli det=ccw(p[__stack[__stack.size()-2]], p[__stack[__stack.size()-1]], p[s_p]);

        if(det<=0) {
            __stack.pop_back();
        }

        if(det>=0) {
            __stack.push_back(s_p);
            s_p++;
        } 
    }
    
    cout<<__stack.size();
    return 0;
}