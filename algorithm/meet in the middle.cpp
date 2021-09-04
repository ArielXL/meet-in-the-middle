#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int A[100];
int B[100];
int SA[300000];
int SB[300000];

// metodo que separa lista(vector) desde first_pos(int) hasta last_pos(int)
void separate_array(vector<int> lista, int arr[], int first_pos, int last_pos)
{
    int pos = 0;
    for(int i = first_pos; i < last_pos; i++)
    {
        arr[pos] = lista[i];
        pos++;
    }
}

// metodo que calcula las sumas de todos los elementos de arr(int[])
// y lo guarda en a(int[])
void calculate_subcjto(int arr[], int len, int a[])
{
    for(int i = 0; i < (1 << len); i++)
    {
        int sum = 0;
        for(int j = 0; j < len; j++)
        {
            if(i & (1 << j))
                sum += arr[j];
        }
        a[i] = sum;
    }
}

// metodo que devuelve cuantos subconjuntos hay en L(vector) tal que su
// suma es X(int)
int get_solution(vector<int> L, int N, int X)
{
    int len_A = N / 2;
    int len_B = N - len_A;

    separate_array(L, A, 0, len_A);
    separate_array(L, B, len_B - 1, N);

    calculate_subcjto(A, len_A, SA);
    calculate_subcjto(B, len_B, SB);

    int len_SA = 1 << len_A;
    int len_SB = 1 << len_B;

    // ordenamos SB(int[]) para realizar busqueda binaria
    sort(SB, SB + len_SB);

    // en sol(int) guardamos la respuesta, es decir, cuantos subconjuntos
    // hay tal que su suma es X(int)
    int sol = 0;

    // iteramos por SA(int[]) y buscamos binario en SB(int[]) su complemento
    for(int i = 0; i < len_SA; i++)
    {
        int a = X - SA[i];

	// devuelve la posicion del mayor elemento mayor o igual que X - SA[i]
        int x = lower_bound(SB, SB + len_SB, a) - SB;
	// devuelve la posicion del mayor elemento mayor que X - SA[i]
        int y = upper_bound(SB, SB + len_SB, a) - SB;

        if(y >= x)
            sol += (y - x);
    }

    return sol;
}

int main()
{
    int N, X, a;
    cin >> N >> X;

    vector<int> L;

    for(int i = 0; i < N; i++)
    {
        cin >> a;
        L.push_back(a);
    }

    int sol = get_solution(L, N, X);

    cout << sol << endl;
}

