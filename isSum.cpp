#include <iostream>
using namespace std;

bool isSum(int arr[], int n, int x)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter value of x: ";
    cin >> x;

    int ans = isSum(arr, n, x);
    if (ans == 1)
    {
        cout << "True";
    }
    else
        cout << "False";

    return 0;
}