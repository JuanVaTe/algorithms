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


//Preproceso del string (O(m))
v32 preprocess(string pattern){
    //Inicialización de variables (contadores)
    int i = 1; int j = 0;
    v32 v(sz(pattern), 0);

    //Revisión del patrón
    while(i < sz(pattern)){

        //No son iguales el prefijo y sufijo
        if(pattern[i] != pattern[j]){

            //Caso base
            if(j == 0){
                v[i] = 0;
                i++; 
            }

            //Volver contando los índices ya sacados
            else j = v[j-1];
        
        //Son iguales
        }else{
            v[i] = j + 1;
            i++;
            j++;
        }
    }
    
    //Regresa vector de valores
    return v;
}

//Algoritmo Knuth-Morris-Pratt (O(m + n) --> O(n))
v32 kmpAlgorithm(string texto, string pattern, v32 pre){
    //Inicialización de variables (contadores)
    int i = 0; int j = 0;
    v32 indexes;

    //Revisión del texto
    while(i < sz(texto)){

        //Patrón y texto son iguales
        if(texto[i] == pattern[j]){
            i++;
            j++;

            //Patrón completo encontrado
            if(j == sz(pattern)){
                indexes.pb(i - ((int) sz(pattern)) + 1);
            } 
        }
        //No son iguales caso base
        else if(j == 0) i++;

        //No son iguales regresa a valor ya sacado
        else{
            j = pre[j-1];
        }

    }

    //No se encontró patrón
    if(sz(indexes) == 0) indexes.pb(-1);

    //Regresa índices encontrados
    return indexes;
}

int main(){
    //Optimización de streams
    fast_cin();

    //Obtiene el nombre del file
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //DISCLAIMER IMPORTANTE: Usar ruta absoluta del archivo
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    string fileN;
    cin >> fileN;

    //Declaración de variables
    vector<string> pattern, text;
    string line;
    int cont = 0;
    int tot = 0;

    //Se abre el archivo
    ifstream myInput;
    myInput.open(fileN);

    //Se encuentra el archivo
    if (myInput.is_open()){

        //Durante todo el archivo
        while (getline(myInput,line)){

            //Obtiene la primera linea
            if(cont == 0){
                tot = stoi(line);
                cont++;
            }

            //Obtiene patrones
            else if((cont % 2) == 1){
                pattern.pb(line);
                cont++;
            }
            
            //Obtiene el texto
            else{
                text.pb(line);
                cont++;
            }
        }

        //Acaba y cierra el archivo
        myInput.close(); 
    }

    //No se encontró el archivo
    else cout << "No se encontró el archivo";

    //Declara vectores de preproceso e índices
    v32 pre, indexes;

    //Casos
    for(int i = 0; i < tot; i++){

        //Preproceso
        pre = preprocess(pattern[i]);

        //KMP para obtener los índices
        indexes = kmpAlgorithm(text[i], pattern[i], pre);

        //Imprime índices
        for(auto x : indexes) cout << x << " ";

        //Salto de página para siguiente caso
        cout << ln;
    }

    return 0;
}