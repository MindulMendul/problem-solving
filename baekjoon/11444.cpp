// https://namu.wiki/w/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98%20%EC%88%98%EC%97%B4#s-8.1

#include <iostream>

#define MOD 1000000007

using namespace std;

typedef long long int lli;

typedef struct {
  lli a1; lli a2;
  lli b1; lli b2;
} FiboMat;

FiboMat mul_FiboMat(FiboMat A, FiboMat B){
  FiboMat res;
  res.a1=(A.a1 * B.a1 + A.a2 * B.b1) % MOD;
  res.a2=(A.a1 * B.a2 + A.a2 * B.b2) % MOD;
  res.b1=(A.b1 * B.a1 + A.b2 * B.b1) % MOD;
  res.b2=(A.b1 * B.a2 + A.b2 * B.b2) % MOD;
  return res;
}

FiboMat bin[61]; // 18 * log_2(10) = 59.xxx
bool binarr[61]; // N-1 을 이진법 표기로 만드는 배열 

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //init
  lli N; cin>>N;
  int i;
  bin[0].a1=1; bin[0].a2=1;
  bin[0].b1=1; bin[0].b2=0;
  for(i=1; i<61; i++){
    bin[i]=mul_FiboMat(bin[i-1], bin[i-1]);
  }
  N-=1; i=0;
  while(N>1){binarr[i++]=(N%2==1); N/=2;}
  binarr[i++]=(N%2==1);
  FiboMat res;
  res.a1=1; res.a2=1;
  res.b1=1; res.b2=0;

  //calculate
  while(i-->0){
    if(binarr[i]){
      res = mul_FiboMat(res, bin[i]);
    }
  }cout<<res.b1;

  return 0;
}
