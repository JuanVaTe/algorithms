//Configuracion del programa
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

//Definición de constantes
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

v32 zAlgorithm(string S){
    //Instanciación de variables
    v32 Z(sz(S), 0);
    Z[0] = 0;
    int l = 0; int r = 0; int j = 0;

    //Recorrido del string
    forsn(i, 1, sz(S)){

        //Validación si esta dentro o fuera de la caja.
        //Fuera
        if(i > r){
            //Actualización de los lados de la caja.
            r = l = i;

            //Validación inbounds e igualdad de prefijo.
            while((r < sz(S)) && (S[r] == S[r-i])) r++;

            //Inserción del resultado.
            Z[i] = r - l;
            r--;
        }
        //Dentro
        else{
            //Apuntador hacia los elementos ya calculados
            j = i - l;

            //Valida si es necesario mover la caja
            if(i + Z[j] < r) Z[i] = Z[j];
            else{
                //Actualización del lado izquierdo de la caja
                l = i;

                //Validación inbounds e igualdad de prefijo.
                while((r < sz(S)) && (S[r] == S[r-i])) r++;

                //Inserción del resultado.
                Z[i] = r - l;
                r--;
            }
        }
    }
    //Regresa resultado
    return Z;
}

int main()
{
    //Streams rápidos
    fast_cin();

    //Obtiene S
    string S;
    cin >> S;

    //Llamado a la función
    v32 Z = zAlgorithm(S);

    //Impresión del resultado
    for(auto x : Z){
        cout << x << " ";
    }

    return 0;
}