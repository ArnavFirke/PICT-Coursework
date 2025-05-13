#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
        return -1;
    if (n == 1 or n == 2)
        return 1;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int fibonacci_rec(int n)
{
    if (n == 1 or n == 2)
        return 1;

    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}
int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    cout << "Fibonacci number(Non recursive) at " << n << " is: " << fibonacci(n) << endl;
    cout << "Fibonacci number(Recursive) at " << n << " is: " << fibonacci_rec(n) << endl;
    return 0;
}