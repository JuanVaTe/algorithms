//Juan Carlos Varela Téllez
//GitHub --> https://github.com/JuanVaTe

//Configuración del programa
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

//Librerías
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

//Definición de datatypes
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;

//Definición de constantes globales
ll MOD = 998244353;
double eps = 1e-12;

//Definición de macros
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

//Plantilla base para programación competitiva --> https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

v32 greedyCoinP(v32 v, int r){
    v32 vr;
    int t = 0; int ap = 0;
    sort(all(v));
    reverse(all(v));
    while(t < r){
        if(t + v[ap] > r){
            ap++;
            if(ap == sz(v)) break;
            continue;
        }
        vr.pb(v[ap]);
        t += v[ap];
    }
    return vr;
}

int main()
{
    fast_cin();
    int t, x, p, q, r;
    v32 v, vg, vdp;
    cin >> t;
    for(int it=1;it<=t;it++) {
        cin >> x;
        v.pb(x);
    }

    cin >> p;
    cin >> q;

    r = q - p;

    vg = greedyCoinP(v, r);
    for (auto x : vg){
        cout << x << ln;
    }

    return 0;
}