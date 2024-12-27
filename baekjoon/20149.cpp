#include <iostream>

int sign(int n){
  return n>0?1:(n==0?0:-1);
}

using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(17);

  long long int x1,y1,x2,y2,x3,y3,x4,y4;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

  long long int x12=x1-x2, y12=y1-y2, x34=x3-x4, y34=y3-y4, x42=x4-x2, y42=y4-y2, x13=x1-x3, x24=x2-x4, y13=y1-y3, y24=y2-y4, x14=x1-x4, y14=y1-y4, x23=x2-x3, y23=y2-y3;

  long long int a=x42*y34-y42*x34;
  long long int D=x12*y34-y12*x34;
  long long int c=x12*y42-y12*x42;
  long long int z=0;

  if(D!=0){ // 기울기가 다른 경우
    if(min(z,D)<=a && a<=max(D,z) && min(z,-D)<=c && c<=max(-D,z)){
      long double xx=(long double)(x12*a+x2*D)/(long double)D;
      long double yy=(long double)(y12*a+y2*D)/(long double)D;
      if(xx==-0) xx=0;
      if(yy==-0) yy=0;
      cout<<"1\n"<<xx<<" "<<yy;
    } else cout<<0;
  } else { // 기울기가 같은 경우
    if(a!=0) cout<<0; // 평행한 두 직선은 안 만남
    else {
      // 두 점이 같은 경우
      if(x1==x3 && x2==x4 && y1==y3 && y2==y4) cout<<1;
      else if(x1==x4 && x2==x3 && y1==y4 && y2==y3) cout<<1;
      
      // 한 점이 같은 경우
      else if(x1==x3 && y1==y3){ cout<<1; if((y12!=0 && sign(y12)==-sign(y34)) || (x12!=0 && sign(x12)==-sign(x34))) cout<<"\n"<<x1<<" "<<y1; }
      else if(x1==x4 && y1==y4){ cout<<1; if((y12!=0 && sign(y12)==sign(y34)) || (x12!=0 && sign(x12)==sign(x34))) cout<<"\n"<<x1<<" "<<y1; }
      else if(x2==x3 && y2==y3){ cout<<1; if((y12!=0 && sign(y12)==sign(y34)) || (x12!=0 && sign(x12)==sign(x34))) cout<<"\n"<<x2<<" "<<y2; }
      else if(x2==x4 && y2==y4){ cout<<1; if((y12!=0 && sign(y12)==-sign(y34)) || (x12!=0 && sign(x12)==-sign(x34))) cout<<"\n"<<x2<<" "<<y2; }

      // 네 점이 다른 경우
      else {
        long long int xx13=x13*x13, yy13=y13*y13, xx24=x24*x24, yy24=y24*y24, xx14=x14*x14, yy14=y14*y14, xx23=x23*x23, yy23=y23*y23;
        long long int dd12=((y12!=0 && sign(y12)==sign(y34)) || (x12!=0 && sign(x12)==sign(x34)))?(xx13+yy13):(xx14+yy14);
        long long int dd34=((y12!=0 && sign(y12)==sign(y34)) || (x12!=0 && sign(x12)==sign(x34)))?(xx24+yy24):(xx23+yy23);

        if (dd12+dd34>(x12*x12+y12*y12)+(x34*x34+y34*y34)) cout<<0;
        else cout<<1;
      }
    }
  }
  
  return 0;
}