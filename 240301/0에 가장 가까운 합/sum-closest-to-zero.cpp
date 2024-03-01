#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>

#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int j = n - 1;
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        while (j > 0 && abs(arr[i] + arr[j]) < ans) {
            ans = abs(arr[i] + arr[j]);
            j--;
        }
        if (i >= j) break;
    }

    cout << ans << endl;

    return 0;
}

// -6 -4 -1 0 5 8 10