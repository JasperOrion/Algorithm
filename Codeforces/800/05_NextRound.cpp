#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int count = k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    if (arr[k - 1] > 0)
    {
        for (int i = k; i < n; i++)
        {
            if (arr[i] < arr[k - 1])
                break;
            if (arr[i] == arr[k])
                count++;
        }
    }
    else
    {
        for (int i = k - 1; i >= 0; i--)
        {
            if (arr[i] <= 0)
                count--;
        }
    }

    cout << count;
    return 0;
}