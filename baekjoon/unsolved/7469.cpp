#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, s, e, k;
    cin>>n>>m;

    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++){
        cin>>s>>e>>k;
        vector<int> v;
        for(int j=s-1; j<e; j++) v.push_back(a[j]);
        sort(v.begin(), v.end());
        cout<<v[k-1]<<endl;
    }
    return 0;
}
