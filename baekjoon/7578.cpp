#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long int lli;

unordered_map<int, int> um;

int N;
int arr[500'000];
int sorted_arr[500'000];

lli merge(int s, int e){
    int mid=(s+e)/2, a=s, b=mid+1, pivot=s;
    lli cnt=0;
    while(a<=mid && b<=e){
        if(arr[a]<arr[b]) sorted_arr[pivot++]=arr[a++];
        else { sorted_arr[pivot++]=arr[b++]; cnt+=(long long)(mid-a+1); }
    }
    while(a<=mid) sorted_arr[pivot++]=arr[a++];
    while(b<=e) sorted_arr[pivot++]=arr[b++];

    for(int i=s; i<=e; i++) arr[i]=sorted_arr[i];
    return cnt;
}

lli partition(int s, int e){
    if(s>=e) return 0;

    lli cnt=0;
    int mid=(s+e)/2;
    cnt+=partition(s, mid);
    cnt+=partition(mid+1, e);
    cnt+=merge(s, e);
    
    return cnt;
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin>>N; 
    for(int i=0; i<N; i++) cin>>arr[i];
    for(int i=0; i<N; i++){ int a; cin>>a; um[a]=i; }
    for(int i=0; i<N; i++) arr[i]=um[arr[i]];
    
    cout<<partition(0, N-1);

    return 0;
}