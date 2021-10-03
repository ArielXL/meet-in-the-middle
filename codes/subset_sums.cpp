#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll X[300000];
ll Y[300000];

// metodo que calcula las sumas de todos los elementos de lista(vector)
// a partir de ind(int) y lo guarda en arr(long long[])
void calculate_subcjto(vector<int> lista, ll arr[], int len, int ind)
{
    for(int i = 0; i < (1 << len); i++)
    {
        ll sum = 0;
        for(int j = 0; j < len; j++)
        {
            if(i & (1 << j))
                sum += lista[j + ind];
        }
        arr[i] = sum;
    }
}

// metodo que devuelve cuantos subconjuntos hay en lista(vector) entre
// A(int) y B(int)
ll get_solution(vector<int> lista, int N, int A, int B)
{
    int len_X = N / 2;
    int len_Y = N - len_X;

    calculate_subcjto(lista, X, len_X, 0);
    calculate_subcjto(lista, Y, len_Y, N / 2);

    ll size_X = 1 << (len_X);
    ll size_Y = 1 << (len_Y);

    // ordenamos Y(long long[]) para realizar busqueda binaria
    sort(Y, Y + size_Y);

    // en sol(long long) guardamos la respuesta, es decir, cuantos subconjuntos
    // hay entre A(int) y B(int)
    ll sol = 0;

    // iteramos por X(long long[]) y buscamos binario en Y(long long[]) su complemento
    for(int i = 0 ; i < size_X; i++)
    {
        int a = A - X[i];
        int b = B - X[i];

        // devuelve la posicion del mayor elemento mayor o igual que A - X[i]
        int x = lower_bound(Y, Y + size_Y, a) - Y;
        // devuelve la posicion del mayor elemento mayor que B - X[i]
        int y = upper_bound(Y, Y + size_Y, b) - Y;

        if(y >= x)
            sol += (y - x);
    }

    return sol;
}

int main()
{
    int A, B, N, a;
    cin >> N >> A >> B;

    vector<int> lista;

    for(int i = 0; i < N; i++)
    {
        cin >> a;
        lista.push_back(a);
    }

    ll sol = get_solution(lista, N, A, B);

    cout << sol << endl;
}
