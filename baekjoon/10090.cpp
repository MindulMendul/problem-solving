#include<iostream>

static int dataa[1000000];
static int sorted[1000000];

using namespace std;

long long int merge(int left, int mid, int right){
	int a=left, b=mid+1, pivot=left;
    long long int cnt=0;
    while(a<=mid && b<=right){
        if(dataa[a]<=dataa[b]){sorted[pivot++]=dataa[a++];}
        else {sorted[pivot++]=dataa[b++]; cnt+=(long long)(mid-a+1);}
    }
    while(a<=mid) {sorted[pivot++]=dataa[a++];}
    while(b<=right) {sorted[pivot++]=dataa[b++];}
    for (int i=left; i<=right; i++) dataa[i]=sorted[i];
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
    int N; cin>>N;
    for(int i=0; i<N; i++){ cin>>dataa[i]; }
    cout<<partition(0,N-1);
	return 0;
}