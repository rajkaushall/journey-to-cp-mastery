#include <iostream>
#include <algorithm> // For sort function
using namespace std;

bool isSum(int arr[], int n, int x)
{
    // First, ensure the array is sorted
    sort(arr, arr + n);

    int start = 0, end = n - 1;
    while (start < end)
    {
        int currentSum = arr[start] + arr[end];

        if (currentSum == x)
        {
            return true;
        }
        else if (currentSum < x)
        {
            start++; // Move the start pointer to the right
        }
        else
        {
            end--; // Move the end pointer to the left
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter Elements of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter sum: ";
    cin >> x;

    bool ans = isSum(arr, n, x);
    if (ans)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}
