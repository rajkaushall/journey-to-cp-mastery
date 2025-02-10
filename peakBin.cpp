#include <iostream>
using namespace std;

void getPeak(int arr[], int n)
{
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1]<= arr[mid]))
        {
            cout<<arr[mid];
        }

        if(mid>0 && arr[mid-1]>=arr[mid])
        {
            high = mid - 1;
        }
        else low = mid + 1;
    }
   
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter size of Array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];}

    cout<<"Peak elements: ";
    getPeak(arr, n);
    
    return 0;
}