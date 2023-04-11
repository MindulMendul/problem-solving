#include<iostream>
#include<algorithm>
 
#define MAX 1000000
 
using namespace std;
 
static int a[MAX];
static int _max[MAX+1];
static int _min[MAX+1];
 
int initMax(int s, int e, int i){
    if(s==e){_max[i]=a[s]; return _max[i];}
    int mid, left, right;
    mid=(s+e)/2;
    left=initMax(s, mid, i*2);
    right=initMax(mid+1, e, i*2+1);
    _max[i]=max(left, right);
    return _max[i];
}
 
int getMax(int s, int e, int i, int l, int r){
    if(l>e || r<s) return 0;
    if(l<=s && r>=e) return _max[i];
    int mid, left, right;
    mid=(s+e)/2;
    left=getMax(s, mid, i*2, l, r);
    right=getMax(mid+1, e, i*2+1, l, r);
    return max(left, right);
}
 
void updateMax(int s, int e, int i, int target, int value){
    if(target>e || target<s) return;
    if(s==e){_max[i]=value; return;}
    int mid; mid=(s+e)/2;
    updateMax(s, mid, i*2, target, value);
    updateMax(mid+1, e, i*2+1, target, value);
    _max[i]=max(_max[i*2], _max[i*2+1]);
}
 
int initMin(int s, int e, int i){
    if(s==e){_min[i]=a[s]; return _min[i];}
    int mid, left, right;
    mid=(s+e)/2;
    left=initMin(s, mid, i*2);
    right=initMin(mid+1, e, i*2+1);
    _min[i]=min(left, right);
    return _min[i];
}
 
int getMin(int s, int e, int i, int l, int r){
    if(l>e || r<s) {return 1000000001;}
    if(l<=s && r>=e) return _min[i];
    int mid, left, right;
    mid=(s+e)/2;
    left=getMin(s, mid, i*2, l, r);
    right=getMin(mid+1, e, i*2+1, l, r);
    return min(left, right);
}
 
void updateMin(int s, int e, int i, int target, int value){
    if(target>e || target<s) return;
    if(s==e){_min[i]=value; return;}
    int mid; mid=(s+e)/2;
    updateMin(s, mid, i*2, target, value);
    updateMin(mid+1, e, i*2+1, target, value);
    _min[i]=min(_min[i*2], _min[i*2+1]);
}
 
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cout<<'#'<<test_case<<' ';
        int n, q, cmd, x, y, min, max;
        cin>>n>>q;
        for(int i=0; i<n; i++){cin>>a[i];}
        initMax(0, n-1, 1); initMin(0, n-1, 1);
        int result=0;
        for(int i=0; i<q; i++){
            cin>>cmd>>x>>y;
            if(cmd){
                cout<<getMax(0, n-1, 1, x, y-1)-getMin(0, n-1, 1, x, y-1)<<" ";
            } else {
                updateMax(0, n-1, 1, x, y);
                updateMin(0, n-1, 1, x, y);
            }
        }
        cout<<'\n';
    }
    return 0;
}