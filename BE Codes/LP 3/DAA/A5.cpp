#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int start = low;
    int end = high;

    while (start < end)
    {
        do
        {
            start++;
        } while (arr[start] <= pivot);

        do
        {
            end--;
        } while (arr[end] > pivot);

        if (start < end)
            swap(arr[start], arr[end]);
    }

    swap(arr[low], arr[end]);
    return end;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        QuickSort(arr, low, p);
        QuickSort(arr, p + 1, high);
    }
}

void QuickSortR(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int random = rand() % (high - low) + low;
        swap(arr[random], arr[low]);
        int p = partition(arr, low, high);
        QuickSortR(arr, low, p);
        QuickSortR(arr, p + 1, high);
    }
}

int main()
{
    srand(time(0)); // Seed the random number generator
    vector<int> x = {10, 12, 15, 20, 1, 4, 17, 16, 11};
    int low = 0;
    int high = x.size();
    cout << "Sorted array using Deterministic Quick sort:" << endl;
    QuickSort(x, low, high);
    for (auto i : x)
        cout << i << " ";
    cout << endl;

    // int random = rand() % (high - low) + low;
    // cout << random << endl;

    x = {10, 12, 15, 20, 1, 4, 17, 16, 11};

    cout << "\nSorted array using Randomized Quick sort:" << endl;
    QuickSortR(x, low, high);
    for (auto i : x)
        cout << i << " ";
    cout << endl;

    return 0;
}
