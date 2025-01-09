#include <iostream>
#include <cstring>

using namespace std;

int C, n;
int arr[100][100];
int cache[100][100];

int jump(int y, int x)
{
    if (y >= n || x >= n)
        return 0;
    if (y == n - 1 && x == n - 1)
        return 1;

    int& ret = cache[y][x];
    if (ret != -1)
        return ret;
    
    int jumpSize = arr[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

void solve()
{
    cin >> n;

    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            cin >> arr[y][x];

    memset(cache, -1, sizeof(cache));
    if (jump(0, 0) == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;

    while (C--)
        solve();

    return 0;
}