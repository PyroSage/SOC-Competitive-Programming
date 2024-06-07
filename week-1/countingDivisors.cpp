#include <iostream>
using namespace std;

void calculateDivisors(long long numDivisors[])
{
    for (int i = 1; i < 1000005; i++) {
        for (int j = i; j < 1000005; j += i) {
            numDivisors[j]++;
        }
    }
}


int main()
{
    long long arr[1000005] = {};
    calculateDivisors(arr);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}