#include <iostream>

using namespace std;

#define MAX 1'000'001
typedef long long int lli;


int N;
int fenwick[MAX];

void update(int ind, int diff){
    while(ind<=MAX){
        fenwick[ind]+=diff;
        ind+=(ind&-ind);
    }
}

long long int sum(int ind){
    long long int res=0;
    while(ind>0){
        res+=fenwick[ind];
        ind-=(ind&-ind);
    }

    return res;
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin>>N;
    for(int i=1; i<MAX; i++) fenwick[i]=0;

    for(int i=0; i<N; i++){
        int a; cin>>a;
        if(a==1){
            int b; cin>>b;
            // 이분탐색
            int s=0, e=MAX, ans;
            while(s<e){
                int mid=(s+e)/2;
                int tmp_sum=sum(mid);
                if(tmp_sum>=b){
                    ans=mid;
                    e=mid;
                } else {
                    s=mid+1;
                }
            }
            cout<<ans<<"\n";
            update(ans, -1);
        } else {
            int b, c; cin>>b>>c;
            update(b, c);
        }
    }

    return 0;
}