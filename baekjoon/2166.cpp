#include <iostream>

#define MAX 10001
using namespace std;

static long long int x[MAX];
static long long int y[MAX];
static int N;

double tri(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){
    long long int a=(x1*y2)+(x2*y3)+(x3*y1);
    long long int b=(x2*y1)+(x3*y2)+(x1*y3);
    return (a-b);
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    double answer=0;

    for(int i=0; i<N; i++) cin >> x[i] >> y[i];
    for(int i=1; i<N-1; i++) answer+=tri(x[0], y[0], x[i], y[i], x[i+1], y[i+1]);
    
    answer/=2;
    printf("%.1f\n", answer>0?answer:-answer);
    return 0;
}
