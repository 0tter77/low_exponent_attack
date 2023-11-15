#define INF32 2147483647
#define INF64 9223372036854775807
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

//拡張ユークリッド互除法
void xeuclid(ll a, ll b, ll gcd, ll& x, ll& y) {
    ll q, r , xx, yy, sign;
    ll xs[2], ys[2];

    xs[0] = 1;
    xs[1] = 0;
    ys[0] = 0;
    ys[1] = 1;
    sign = 1;

    while (b != 0){
        r = a%b;
        q = a/b;
        a = b;
        b = r;
        xx = xs[1];
        yy = ys[1];
        xs[1] = q*xs[1] + xs[0];
        ys[1] = q*ys[1] + ys[0];
        xs[0] = xx;
        ys[0] = yy;
        sign = -sign;
    }
    x = sign*xs[0];
    y = -sign*ys[0];

    gcd = a;

}

//前処理
void crtPrecomp(ll moduli[], ll numberOfModuli, ll& modulus, ll multipliers[]){
    ll m, M, inverse, gcd, y;
    modulus = 1;
    rep(i, numberOfModuli){
        modulus = modulus*moduli[i];
    }
    //cout << modulus << endl;
    rep(i, numberOfModuli){
        m = moduli[i];
        //cout << m << endl;
        if (m == 0) {
            cerr << "Error: Division by zero (m is zero)" << endl;
            exit(1);
        }
        M = modulus / m;
        xeuclid(M,m,gcd,inverse,y);
        //cout << inverse << M << modulus << endl;
        multipliers[i] = inverse*M%modulus;
        if(multipliers[i] < 0){
            multipliers[i] += modulus;
        }
        //cout << multipliers[i] << endl;
    }
}

//中国人剰余定理
void crt(ll moduli[], ll x[], ll numberOfModuli, ll& result){
    ll multipliers[numberOfModuli];
    result = 0;
    ll modulus;
    crtPrecomp(moduli, numberOfModuli, modulus, multipliers);
    rep(i, numberOfModuli){
        result = (result + multipliers[i]*x[i])%modulus;
    }
    //cout << result << endl;
}


int main() {
    cout << "e = ";
    ll e;
    cin >> e;
    cout << endl;
    ll c[e], moduli[e];
    rep(i, e){
        cout << "c_" << i+1 << "= ";
        cin >> c[i];
        cout << endl;
    }
    rep(i, e){
        cout << "n_" << i+1 << "= ";
        cin >> moduli[i];
        cout << endl;
    }
    //ll c[] = {60, 203, 711};
    //ll moduli[] = {143, 391, 899};
    ll result;
    
    //cを特定
    crt(moduli, c, e, result);

    cout << "c = " << result << endl;

    //c^(1/e)を計算
    double m = pow(double(result), double(1)/double(e));

    cout << "m = " << m << endl;
    return 0;


}