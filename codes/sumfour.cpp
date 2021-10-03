#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> X;
vector<int> Y;

void generate_sum(vector<int> first, vector<int> second, int flag)
{
    for(int i = 0; i < first.size(); i++)
    {
        for(int j = 0; j < second.size(); j++)
        {
            int sum = first[i] + second[j];

            if(flag)
                X.push_back(sum);
            else
                Y.push_back(sum);
        }
    }
}

int get_solution(vector<int> A, vector<int> B, vector<int> C, vector<int> D)
{
    generate_sum(A, B, 1);
	generate_sum(C, D, 0);

    sort(Y.begin(), Y.end());

    int sol = 0;

    for(int i = 0; i < X.size(); i++)
    {
		int a = 0 - X[i];

        int x = lower_bound(Y.begin(), Y.end(), a) - Y.begin();
        int y = upper_bound(Y.begin(), Y.end(), a) - Y.begin();

        if(y >= x)
            sol += (y - x);
    }

	return sol;
}

int main()
{
    int N, a;
    cin >> N;

    vector<int> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> a;

            if(j == 0)
 	            A.push_back(a);
            else if(j == 1)
                B.push_back(a);
            else if(j == 2)
                C.push_back(a);
            else
                D.push_back(a);
        }
    }

	int sol = get_solution(A, B, C, D);

	cout << sol << endl;
}

