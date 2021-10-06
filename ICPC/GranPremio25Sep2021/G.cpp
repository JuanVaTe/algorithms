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
#define now memo[coor.fi][coor.se]

//Plantilla base para programación competitiva --> https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int check(vector<string> matriz, vv32 &memo, p64 coor, int r, char let, int ap){
    int rnow = 0;
    int apsig = ap + 1;
    char letsig = abc[apsig];
    r++;
    if(memo[coor.fi][coor.se] != 0){
        return (r + memo[coor.fi][coor.se]);
    }
    if(let == 'Z'){
        now = r;
        return r;
    }
    if(coor.fi == 0){
        if(coor.se == 0){
            //Checar esquina superior izquierda
            if(letsig == matriz[coor.fi + 1][coor.se]){
                rnow = r + check(matriz, memo, mp((coor.fi + 1), coor.se), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig == matriz[coor.fi + 1][coor.se + 1]){
                rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig == matriz[coor.fi][coor.se + 1]){
                rnow = r + check(matriz, memo, mp(coor.fi, (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            now = r;
            return r;
        }
        if(coor.se == sz(matriz[0])-1){
            //Checar esquina inferior izquierda
            if(letsig == memo[coor.fi][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi + 1][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi + 1][coor.se]){
                rnow = r + check(matriz, memo, mp((coor.fi + 1), coor.se), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            now = r;
            return r;
        }
        else{
            //Checar columna mas izquierda
            if(letsig==matriz[coor.fi][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi + 1][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi + 1][coor.se]){
                rnow = r + check(matriz, memo, mp((coor.fi + 1), coor.se), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi + 1][coor.se + 1]){
                rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi][coor.se + 1]){
                rnow = r + check(matriz, memo, mp(coor.fi, (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            now = r;
            return r;
        }
    }
    if(coor.first == sz(matriz)-1){
        if(coor.se == 0){
            //Checar esquina superior derecha
            if(letsig==matriz[coor.fi - 1][coor.se]){
                rnow = r + check(matriz, memo, mp((coor.fi - 1), coor.se), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi - 1][coor.se + 1]){
                rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi][coor.se + 1]){
                rnow = r + check(matriz, memo, mp(coor.fi, (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            now = r;
            return r;
        }
        if(coor.se == sz(matriz[0])-1){
            //Checar esquina inferior derecha
            if(matriz[coor.fi][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi - 1][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi - 1][coor.se]){
                rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            now = r;
            return r;
        }
        else{
            //Checar columna más derecha
            if(matriz[coor.fi][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi - 1][coor.se - 1]){
                rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se - 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi - 1][coor.se]){
                rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi - 1][coor.se + 1]){
                rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            if(letsig==matriz[coor.fi][coor.se + 1]){
                rnow = r + check(matriz, memo, mp(coor.fi, (coor.se + 1)), r, letsig, apsig);
                now = rnow;
                return rnow;
            }

            now = r;
            return r;
        }
    }
    if(coor.se == 0){
        //Checar fila superior
        if(letsig==matriz[coor.fi - 1][coor.se]){
            rnow = r + check(matriz, memo, mp((coor.fi - 1), coor.se), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi - 1][coor.se + 1]){
            rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se + 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi][coor.se + 1]){
            rnow = r + check(matriz, memo, mp(coor.fi, (coor.se + 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi + 1][coor.se]){
            rnow = r + check(matriz, memo, mp((coor.fi + 1), coor.se), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi + 1][coor.se + 1]){
            rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se + 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        now = r;
        return r;
    }
    if(coor.se == sz(matriz[0])-1){
        //Checar fila inferior
        if(letsig==matriz[coor.fi][coor.se - 1]){
            rnow = r + check(matriz, memo, mp((coor.fi), (coor.se - 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi - 1][coor.se - 1]){
            rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se - 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi - 1][coor.se]){
            rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi + 1][coor.se - 1]){
            rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se - 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi + 1][coor.se]){
            rnow = r + check(matriz, memo, mp((coor.fi + 1), coor.se), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        now = rnow;
        return r;
    }
    else{
        //Checar todo lo de en medio
        if(letsig==matriz[coor.fi][coor.se - 1]){
            rnow = r + check(matriz, memo, mp((coor.fi), (coor.se - 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }
        if(letsig==matriz[coor.fi - 1][coor.se - 1]){
            rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se - 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi - 1][coor.se]){
            rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi + 1][coor.se - 1]){
            rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se - 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi + 1][coor.se]){
            rnow = r + check(matriz, memo, mp((coor.fi + 1), coor.se), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi - 1][coor.se + 1]){
            rnow = r + check(matriz, memo, mp((coor.fi - 1), (coor.se + 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi][coor.se + 1]){
            rnow = r + check(matriz, memo, mp(coor.fi, (coor.se + 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        if(letsig==matriz[coor.fi + 1][coor.se + 1]){
            rnow = r + check(matriz, memo, mp((coor.fi + 1), (coor.se + 1)), r, letsig, apsig);
            now = rnow;
            return rnow;
        }

        now = r;
        return r;
    }
}

int main(){
    //Optimización de streams
    fast_cin();
    vector<string> matriz;
    vv32 memo;
    string s;
    char let;
    int best = 0; int ap;
    ll h, l;
    cin >> h >> l;

    v32 v(l, 0);

    for(int it=1;it<=h;it++) {
        cin >> s;
        matriz.pb(s);
        memo.pb(v);
    }

    for(auto x : matriz) cout << x << ln;

    for(ll i = 0; i < sz(matriz); i++){
        for(ll j = 0; j < sz(matriz[0]); j++){
            let = matriz[i][j];
            ap = abc.find(let);
            best = max(best, check(matriz, memo, mp(i, j), 0, let, ap));
        }
    }

    for(auto x : memo){
        for(auto y : x){
            cout << y << " ";
        }
    }

    cout << best;

    return 0;
}