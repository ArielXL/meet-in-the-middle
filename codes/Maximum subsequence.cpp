#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> X, Y;

void generate_subcjto(vector<int> L, vector<int> &X, int len, int ind, int M)
{
    for(int i = 0; i < (1 << len); i++)
    {
        int sum = 0;
        for(int j = 0; j < len; j++)
        {
            if(i & (1 << j))
                sum = (sum + L[j + ind]) % M;
        }
        X.push_back(sum);
    }
}

int get_solution(vector<int> L, int N, int M)
{
    int len_X = N / 2;
    int len_Y = N - len_X;

    generate_subcjto(L, X, len_X, 0, M);
    generate_subcjto(L, Y, len_Y, N / 2, M);

    sort(Y.begin(), Y.end());

    int resp = 0;

    for(int i = 0; i < X.size(); i++)
    {
        int v = X[i];
        int pos = upper_bound(Y.begin(), Y.end(), M - 1 - v) - Y.begin() - 1;
        if(pos >= 0)
        	resp = max(resp, v + Y[pos]);
    }

    return resp;
}

int main()
{
    int N, M, a;
    cin >> N >> M;

    vector<int> L;

    for(int i = 0; i < N; i++)
    {
        cin >> a;
        L.push_back(a);
    }

    int resp = get_solution(L, N, M);

    cout << resp << endl;
}