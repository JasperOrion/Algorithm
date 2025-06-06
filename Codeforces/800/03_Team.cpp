#include <iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        cin >> a >> b >> c;
        sum += (a + b + c);
        if (sum >= 2)
            count++;
    }
    cout << count << endl;
    return 0;
}