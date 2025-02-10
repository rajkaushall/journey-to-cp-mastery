#include <bits/stdc++.h>
using namespace std;

void mergeArr(int arr1[], int arr2[], int m, int n)
{
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }

        else
        {
            cout << arr2[j] << " ";
            j++;
        }
    }

    while (i < m)
    {
        cout << arr1[i] << " ";
        i++;
    }

    while (j < n)
    {
        cout << arr2[j] << " ";
        j++;
    }
}

int main()
{
    int arr1[5] = {3, 5, 1, 6, 2};
    int arr2[5] = {0, 9, 7, 8, 4};

    mergeArr(arr1, arr2, 5, 5);

    return 0;
}