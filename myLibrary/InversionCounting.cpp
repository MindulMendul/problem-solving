#include<iostream>
 
static int data[100000];
static int sorted[100000];
 
using namespace std;
 
long long int merge(int left, int mid, int right){
    int a=left, b=mid+1, pivot=left;
    long long int cnt=0;
    while(a<=mid && b<=right){
        if(data[a]<=data[b]){sorted[pivot++]=data[a++];}
        else {sorted[pivot++]=data[b++]; cnt+=(long long)(mid-a+1);}
    }
    while(a<=mid) {sorted[pivot++]=data[a++];}
    while(b<=right) {sorted[pivot++]=data[b++];}
    for (int i=left; i<=right; i++) data[i]=sorted[i];
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
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N; cin>>N;
        for(int i=0; i<N; i++){ cin>>data[i]; }
        cout<<'#'<<test_case<<' '<<partition(0,N-1)<<endl;
    }
    return 0;
}