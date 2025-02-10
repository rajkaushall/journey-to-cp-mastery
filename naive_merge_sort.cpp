#include <bits/stdc++.h>
using namespace std;

void mergeArr(int arr1[], int arr2[], int m, int n)
{
    int newArr[m + n];


    for(int i = 0; i < m; i++)
    {
        newArr[i] = arr1[i];
    }

    for(int i = 0; i < n; i++)
    {
        newArr[m + i] = arr2[i];
    }

    sort(newArr, newArr + m + n);

    for(int i = 0; i < m + n; i++)
    {
        cout<<newArr[i]<<" ";
    }

}

int main() {
    int arr1[5] = {3,5,1,6,2};
    int arr2[5] = {0,9,7,8,4};

    mergeArr(arr1,arr2,5,5);
    
    return 0;
}