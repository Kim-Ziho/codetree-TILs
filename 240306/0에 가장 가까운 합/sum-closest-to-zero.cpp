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
        if (i >= j) break;
        while (j > 1) {
            if (abs(arr[i] + arr[j]) < ans)
                ans = abs(arr[i] + arr[j]);
            else break;
            if (abs(arr[i] + arr[j - 1]) < ans)
                j--;
        }
    }

    cout << ans << endl;

    return 0;
}

// -6 -5 -1 0 5 8 10
// -123 1 1 2 2 124