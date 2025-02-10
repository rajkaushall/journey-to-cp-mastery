#include <iostream>
using namespace std;

void peakEle(int arr[], int n)
{
    if (n == 1)
    {
        cout << arr[0] << " ";
        return;
    }
    if (arr[0] > arr[1])
    {
        cout << arr[0] << " ";
    }
    if (arr[n - 1] > arr[n - 2])
    {
        cout << arr[n - 1] << " ";
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Peak elements: ";
    peakEle(arr, n);

    return 0;
}
