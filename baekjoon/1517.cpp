#include<iostream>
 
static int unsortedData[500000];
static int sortedData[500000];
 
using namespace std;
 
long long int merge(int left, int mid, int right){
    int a=left, b=mid+1, pivot=left;
    long long int cnt=0;
    while(a<=mid && b<=right){
        if(unsortedData[a]<=unsortedData[b]){sortedData[pivot++]=unsortedData[a++];}
        else {sortedData[pivot++]=unsortedData[b++]; cnt+=(long long)(mid-a+1);}
    }
    while(a<=mid) {sortedData[pivot++]=unsortedData[a++];}
    while(b<=right) {sortedData[pivot++]=unsortedData[b++];}
    for (int i=left; i<=right; i++) unsortedData[i]=sortedData[i];
    return cnt;
}
 
long long int partition(int left, int right){
    int mid=(left+right)/2;
    long long int cnt=0;
    if (left < right) {
        cnt+=partition(left, mid);
        cnt+=partition(mid+1, right);
        cnt+=merge(left, mid, right);
    }
    return cnt;
}
 
int main(int argc, char** argv)
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin>>N;    
    for(int i=0; i<N; i++){ cin>>unsortedData[i]; }
    cout<<partition(0,N-1)<<endl;
    return 0;
}