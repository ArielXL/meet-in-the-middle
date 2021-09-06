#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

// function to find minimum number of swaps to make another permutation
int shortest_path(string start, string finish, int n)
{
    queue<string> _queue;
    map<string, bool> visited;
    map<string, int> d;
    map<string, string> src;

    visited[start] = visited[finish] = true;
    d[start] = d[finish] = 0;
    src[start] = start;
    src[finish] = finish;
    _queue.push(start);
    _queue.push(finish);

    while (!_queue.empty())
    {
        // take top vertex of the queue
        string element = _queue.front();
        _queue.pop();

        // generate n - 1 of it's permutations
        for (int i = 1; i < n; i++)
        {
            // generate next permutation
            string temp = element;
            swap(temp[i], temp[i - 1]);

            // ff temp is not visited
            if (!visited[temp])
            {
                // set it visited
                visited[temp] = true;
                // make root of u and root of v equal
                src[temp] = src[element];
                // increment it's distance by 1
                d[temp] = d[element] + 1;
                // push this vertex into queue
                _queue.push(temp);
            }
            // if it is already visited and roots are different then answer is found
            else if (src[element] != src[temp])
                return d[element] + d[temp] + 1;
        }
    }
}

int main()
{
    string A, B;
    cin >> A >> B;

    int N = A.length();

    cout << shortest_path(A, B, N) << endl;
}
