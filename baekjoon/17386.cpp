#include <iostream>

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long int x1,y1,x2,y2,x3,y3,x4,y4;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

  long long int x12=x1-x2, y12=y1-y2, x34=x3-x4, y34=y3-y4, x42=x4-x2, y42=y4-y2;
  // (x1,y1)*t+(x2,y2)*(1-t)=(x3,y3)*s+(x4, y4)*(1-s)
  // (x1,y1)*t-(x2,y2)*t +(x2,y2) = (x3,y3)*s-(x4,y4)*s +(x4,y4)
  // {(x1,y1)-(x2,y2)}*t-{(x3,y3)-(x4,y4)}*s=(x4,y4)-(x2,y2);

  // (x1-x2)*t-(x3-x4)*s=x4-x2;
  // (y1-y2)*t-(y3-y4)*s=y4-y2;

  // x12*t=x34*s+x42;
  // y12*t=y34*s+y42;

  // x12*y12*t=y12*x34*s+y12*x42;
  // x12*y12*t=x12*y34*s+x12*y42;

  // y12*x34*s+y12*x42=x12*y34*s+x12*y42;
  // y12*x34*s-x12*y34*s=x12*y42-y12*x42;
  // (y12*x34-x12*y34)*s=x12*y42-y12*x42;


  // x12*y34*t=x34*y34*s+x42*y34;
  // y12*x34*t=x34*y34*s+y42*x34;

  // x12*y34*t-y12*x34*t=x42*y34-y42*x34;
  // (x12*y34-y12*x34)*t=x42*y34-y42*x34;

  // 0<=x42*y34-y42*x34/(x12*y34-y12*x34)<=1;

  long long int a=x42*y34-y42*x34;
  long long int b=x12*y34-y12*x34;
  long long int c=x12*y42-y12*x42;
  long long int d=y12*x34-x12*y34;
  long long int z=0;

  if(min(z,b)<=a && a<=max(b,z) && min(z,d)<=c && c<=max(d,z)){
    cout<<1;
  } else {
    cout<<0;
  }
  
  return 0;
}