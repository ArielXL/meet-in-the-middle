#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int L[1000000], R[1000000], cntL[1000000], cntR[1000000];

void print(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int generate_left(int arr[], int N)
{
    int sizeL = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                L[sizeL] = (arr[i] * arr[j]) + arr[k];
                sizeL++;
            }
        }
    }
    return sizeL;
}

int generate_rigth(int arr[], int N)
{
    int sizeR = 0;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] == 0)
            continue;

        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                R[sizeR] = arr[i] * (arr[j] + arr[k]);
                sizeR++;
            }
        }
    }
    return sizeR;
}

int get_pos(int L[], int cntL[], int sizeL)
{
    int pos = 1;
    cntL[0] = 1;

    for(int i = 1; i < sizeL; i++)
    {
        if(L[i] != L[pos - 1])
        {
            L[pos] = L[i];
            cntL[pos] = 1;
            pos++;
        }
        else
            cntL[pos - 1]++;
    }

    return pos;
}

long long get_answer(int pos1, int pos2)
{
    long long ans = 0;
    for(int i = 0, j = 0; i < pos1 && j < pos2; )
    {
        if(R[j] == L[i])
            ans += (long long)cntL[i] * cntR[j];
        if(L[i] < R[j])
            i++;
        else if(L[i] > R[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    return ans;
}

long long get_solution(int arr[], int N)
{
    int sizeL = generate_left(arr, N);
    int sizeR = generate_rigth(arr, N);

    sort(L, L + sizeL);
    sort(R, R + sizeR);

    // cout << "arrays L y R" << endl;
    // print(L, sizeL);
    // print(R, sizeR);

    int pos1 = get_pos(L, cntL, sizeL);
    int pos2 = get_pos(R, cntR, sizeR);

    // cout << "arrays cntL y cntR" << endl;
    // print(cntL, sizeL);
    // print(cntR, sizeR);

    long long ans = get_answer(pos1, pos2);

    return ans;
}

int main()
{
    int N, x;
    cin >> N;

    int arr[N];

    for(int i = 0; i < N; i++)
    {
        cin >> x;
        arr[i] = x;
    }

    int ans = get_solution(arr, N);

    cout << ans << endl;
}
