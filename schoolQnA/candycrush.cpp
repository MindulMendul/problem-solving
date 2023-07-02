#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

const int N = 7;
static int num = 0;

class Candy {
    private:
        vector<int> candy;
        int n;
    public:
        void init();
        int at(int x);
        void add(int x, int y);
        void sub(int x, int y);
        void repair(int indx, int x, int indy, int y);
        void print();
        bool isFinish();
        int result();
        int nn();

}; Candy c;

void Candy::init(){
    candy.clear(); vector<int>().swap(candy);
    for(int i=0; i<N; i++){candy.push_back(1);}
    n=N;
}

int Candy::at(int x){
    return candy[x];
}

int Candy::nn(){
    return n;
}

void Candy::add(int x, int y){
    candy[x]=candy[x]+candy[y];
    candy.erase(candy.begin()+y);
    sort(candy.begin(), candy.end(), greater<int>());
}

void Candy::sub(int x, int y){
    n-=candy[x]+candy[y];
    candy[x]=(candy[x]>candy[y])?candy[x]-candy[y]:candy[y]-candy[x];
    n+=candy[x];
    candy.erase(candy.begin()+y);
    sort(candy.begin(), candy.end(), greater<int>());
}

void Candy::repair(int indx, int x, int indy, int y){
    n-=candy[indx];
    n+=x+y;
    candy[indx]=x;
    candy.insert(candy.begin()+indy, y);
    sort(candy.begin(), candy.end(), greater<int>());
}

void Candy::print(){
    cout<<n<<": ";
    for(int i=0; i<candy.size(); i++){cout<<candy[i]<<" ";}
    cout<<endl;
}

int Candy::result(){
    return candy.size();
}

bool Candy::isFinish(){
    if(n==0) return true;
    for(int i=0; i<candy.size(); i++){
        if(candy[i]>n/2) return true;
    }
    return false;
}

int func(int len){
    if(c.isFinish()) return c.result();
    int a, b, res=-1;

    vector<pair<int, int>> memory;

    for(int x=0; x<=len-2; x++){
        for(int y=x+1; y<=len-1; y++){
            for(int i=0; i<memory.size(); i++){
                if((memory[i].first==x && memory[i].second==y)) continue;
            }
            memory.push_back(make_pair(x, y));
            a=c.at(x); b=c.at(y);

            c.add(x, y);
            int add=func(len-1);
            c.repair(x, a, y, b);

            c.sub(x, y);
            int sub=func(len-1);
            c.repair(x, a, y, b);

            int tmp=(add<sub)?add:sub;
            if(res<tmp) res=tmp;
        }
    }

    if()
    
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    c.init();
    cout<<func(N);
    
    return 0;
}
