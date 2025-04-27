#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap (arr[i], arr[j]);
            i++;
        }
    }
    swap (arr[i], arr[high]);
    return i; 
}

void quickSort(int *arr, int low, int high)
{
    if (low < high) 
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Before sorted : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "After sorted : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " "; 
    cout << endl;

    return 0;
}
