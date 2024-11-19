#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

vector<vector<lli>> mat[37];
vector<int> bin;
int N;
lli M;

// 가로 행 세로 열
//
// ---   |||
// ---   |||
// ---   |||

void printMatrix(vector<vector<lli>> m){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<m[i][j]<<' ';
        }cout<<'\n';
    }
}

vector<vector<lli>> mulMatrix(vector<vector<lli>> A, vector<vector<lli>> B){
    vector<vector<lli>> res;

    for(int i=0; i<N; i++){
        vector<lli> v;
        for(int j=0; j<N; j++){
            lli a=0;
            for(int k=0; k<N; k++){
                a+=A[i][k]*B[k][j];
                a%=1000;
            }
            v.push_back(a);
        }
        res.push_back(v);
    }

    return res;
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<lli>> res;
    cin>>N>>M;

    for(int i=0; i<N; i++){
        vector<lli> v, resv;
        for(int j=0; j<N; j++){
            int a; cin>>a;
            v.push_back(a);
            resv.push_back((i==j)?1:0);
        }
        mat[0].push_back(v);
        res.push_back(resv);
    }

    for(int i=0; i<36; i++){
        mat[i+1]=mulMatrix(mat[i], mat[i]);
    }

    // calculate
    int ii=0;
    while(M>0){
        if(M%2==1){
            res=mulMatrix(res, mat[ii]);
        }

        M/=2; ii++;
    }

    printMatrix(res);

    return 0;
}
