#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[1000001];

int main() {

    cin >> n >> k;
    
    if (k > 500000) k = 500000;

    for (int i = 0; i < n; i++) {
        int num, pos;
        cin >> num >> pos;
        arr[pos] += num;
    }

    int c = k;
    int sum = 0;
    int i = 0;
    int maxi = 0;

    for (int i = 0; i <= c + k; i++) {
        sum += arr[i];
    }
    maxi = sum;

    for (int j = c + k + 1; j <= 1000000; j++) {
        sum += arr[j] - arr[i];
        maxi = max(maxi, sum);
        i++;
    }

    cout << maxi;

    return 0;
}