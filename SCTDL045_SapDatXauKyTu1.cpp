#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a[30] = {}, MAX = 0;
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a']++;
        for (int i = 0; i < 30; i++)
            MAX = max(MAX, a[i]);
        if (MAX * 2 > s.size() + 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
}