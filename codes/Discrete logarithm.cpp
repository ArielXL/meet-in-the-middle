#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int pow(int a, int n, int m)
{
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
    {
        int pot = pow(a, n / 2, m);
        return (pot % m * pot % m) % m;
    }
    else
    {
        int pot = pow(a, n - 1, m);
        return (pot % m * a % m) % m;
    }
}

int discrete_logarithm(int a, int b, int m)
{
    int n = sqrt(m) + 1;

    // calculate (a ^ n)  % m
    int an = pow(a, n, m);

    map<int, int> value;

    for(int i = 1, current = an; i <= n; i++)
    {
        if(!value[current])
            value[current] = i;
        current = (current * an) % m;
    }

    for(int i = 0, current = b; i <= n; i++)
    {
        // calculate (a ^ j) * b and check for collision
        if (value[current])
        {
            int ans = value[current] * n - i;
            if (ans < m)
                return ans;
        }
        current = (current * a) % m;
    }

    return -1;
}

int main()
{
    int A, B, M;
    cin >> A >> B >> M;

    cout << discrete_logarithm(A, B, M) << endl;
}
