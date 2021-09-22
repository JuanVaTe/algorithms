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

//Algoritmo avaro (O(n) (Dependiendo de las monedas proporcionadas, no siempre da el resultado correcto))
v64 greedyCoinP(v64 v, int r){
    //Instanciación de variables
    //Vector donde se guardan las monedas
    v64 vr;

    //Total y apuntador de monedas
    int t = 0; int ap = 0;

    //Ordenamiento de mayor a menor para algoritmo avaro
    sort(all(v));
    reverse(all(v));

    //Mientras el total sea menor que el objetivo
    while(t < r){

        //Validación de la posibilidad de conseguir el objetivo
        if(t + v[ap] > r){

            //Cambia la moneda
            ap++;

            //Corta si ya no hay más monedas
            if(ap == sz(v)) break;
            continue;
        }

        //Inserción de monedas
        vr.pb(v[ap]);

        //Actualización del total
        t += v[ap];
    }

    //Regresa las monedas
    return vr;
}

//Algoritmo con programación dinámica (O(n*r) "r" siendo el objetivo y "n" el numero de monedas (Siempre da el resultado correcto))
v64 DPCoinP(v64 v, int r){

    //Instanciación de variables
    //Vector donde se guardan el menor número de monedas necesarias de cada valor
    v64 memo(r+1);

    //Vector donde se guarda la primera moneda utilizada en cada valor/Vector donde se guardan las moendas
    v64 mon(r+1), vr;

    //0 = 0 monedas
    memo[0] = 0;

    //Cálculo del mínimo de monedas de cada elemento hasta que llegue al objetivo
    forsn(i, 1, r+1){

        //Infinito para que la primera comparación siempre sea menor
        memo[i] = INF;

        //Elección de la primera moneda en cada valor
        forn(j, sz(v)){

            //Valida si se puede utilizar la moneda elegida y si es más optimo que la opción anterior
            if((i-v[j] >= 0) && (memo[i-v[j]] + 1 < memo[i])){

                //Actualización del valor óptimo
                memo[i] = memo[i-v[j]] + 1;

                //Actualización de la primera moneda utilizada
                mon[i] = v[j];
            }
        }
    }

    //Inserción de las monedas utilizadas
    while(r > 0){
        //Inserta la primera moneda utilizada en r
        vr.pb(mon[r]);

        //Resta el valor de la moneda a r
        r -= mon[r];
    }

    //Ordenamiento del vector
    sort(all(vr));
    reverse(all(vr));

    //Regresa el vector
    return vr;
}

//Función main
int main(){

    //Optimización de streams
    fast_cin();

    //Instanciación de variables
    //Total de monedas/Cin de monedas/Precio/Pago/Cambio
    int t, x, p, q, r;

    //Vector de monedas/Vector de monedas avaro/Vector de monedas DP
    v64 v, vg, vdp;

    //Obtiene el total de monedas
    cin >> t;

    //Inserción de monedas en vector
    for(int it=1;it<=t;it++) {
        cin >> x;
        v.pb(x);
    }

    //Obtiene precio y pago
    cin >> p;
    cin >> q;

    //Cálculo del cambio
    r = q - p;

    //Impresión del vector del algoritmo DP
    vdp = DPCoinP(v, r);
    for (auto x : vdp){
        cout << x << ln;
    }

    //Impresión del vector de algoritmo avaro
    vg = greedyCoinP(v, r);
    for (auto x : vg){
        cout << x << ln;
    }

    return 0;
}