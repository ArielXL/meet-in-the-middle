#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int X[300000];
int Y[300000];

void generate_sum_subcjto(vector<int> weigth, int arr[], int len, int ind)
{
    for(int i = 0; i < (1 << len); i++)
    {
        int sum = 0;
        for(int j = 0; j < len; j++)
        {
            if(i & (1 << j))
                sum += weigth[j + ind];
        }
        arr[i] = sum;
    }
}

int my_binary_search(int arr[], int len, int x, int weigth_knapsack)
{
    int ans = 0;
    int low = 0;
    int high = len - 1;

    while(low < high)
    {
        int m = (low + high + 1) / 2;

        if(arr[m] + x <= weigth_knapsack)
            low = m;
        else
            high = m - 1;
    }
    if(x <= weigth_knapsack)
        ans = low + 1;

    return ans;
}

int knapsack_problem(vector<int> weigth, int weigth_knapsack, int N)
{
    int len_X = N / 2;
    int len_Y = N - len_X;

    generate_sum_subcjto(weigth, X, len_X, 0);
    generate_sum_subcjto(weigth, Y, len_Y, N / 2);

    int size_X = 1 << (len_X);
    int size_Y = 1 << (len_Y);

    sort(Y, Y + size_Y);

    int sol = 0;

    for(int i = 0 ; i < size_X; i++)
    {
        sol += my_binary_search(Y, size_Y, X[i], weigth_knapsack);
    }

    cout << sol << endl;
    return sol;
}

int main()
{
    int weigth_knapsack, N, a;
    cin >> N >> weigth_knapsack;

    vector<int> weigth;

    for(int i = 0; i < N; i++)
    {
        cin >> a;
        weigth.push_back(a);
    }

    int sol = knapsack_problem(weigth, weigth_knapsack, N);

    cout << sol << endl;
}

