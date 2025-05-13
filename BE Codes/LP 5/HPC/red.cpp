#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

double minval(int arr[], int n)
{
    int minvale = arr[0];
    #pragma omp parallel for reduction(min : minvale)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minvale)
            minvale = arr[i];
    }
    return minvale;
}

double maxval(int arr[], int n)
{
    int maxvale = arr[0];
    #pragma omp parallel for reduction(max : maxvale)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxvale)
            maxvale = arr[i];
    }
    return maxvale;
}

long long sum(int arr[], int n)
{
    long long asum = 0;  // Change sum to long long to prevent overflow
    #pragma omp parallel for reduction(+ : asum)
    for (int i = 0; i < n; i++)
    {
        asum += arr[i];
    }
    return asum;
}

double average(int arr[], int n)
{
    return (double)sum(arr, n) / n;  // Ensure the division results in a floating-point value
}

int main()
{
    int n = 1e5;
    int arr[n];
    double start_time, end_time;

    // Seed the random number generator with the current time
    srand(time(0));

    // Create an array with random numbers.
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    start_time = omp_get_wtime();
    cout << "The minimum value is: " << minval(arr, n) << '\n';
    end_time = omp_get_wtime();
    cout << "Time taken: " << end_time - start_time << " seconds\n";

    start_time = omp_get_wtime();
    cout << "The maximum value is: " << maxval(arr, n) << '\n';
    end_time = omp_get_wtime();
    cout << "Time taken: " << end_time - start_time << " seconds\n";

    start_time = omp_get_wtime();
    cout << "The summation is: " << sum(arr, n) << '\n';
    end_time = omp_get_wtime();
    cout << "Time taken: " << end_time - start_time << " seconds\n";

    start_time = omp_get_wtime();
    cout << "The average is: " << average(arr, n) << '\n';
    end_time = omp_get_wtime();
    cout << "Time taken: " << end_time - start_time << " seconds\n";

    return 0;
}
