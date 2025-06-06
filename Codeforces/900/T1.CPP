#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, p, q;
        cin >> n >> m >> p >> q;
        if (n % p == 0)
        {
            long long k = n / p;
            if (m == k * q)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}