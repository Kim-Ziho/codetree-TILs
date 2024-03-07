#include <iostream>
#include <algorithm>

#define MAX_N 500

using namespace std;

int k, n;
int prefix[MAX_N + 1][MAX_N + 1];
int arr[MAX_N + 1][MAX_N + 1];

int main() {
    cin >> n >> k;

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> arr[y][x];
        }
    }
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            prefix[y][x] = prefix[y - 1][x] + 
                           prefix[y][x - 1] - 
                           prefix[y - 1][x - 1] + 
                           arr[y][x];
        }
    }
    int max_sum = 0;
    int val_sum = 0;
    for (int y = k; y <= n; y++) {
        for (int x = k; x <= n; x++) {
            val_sum = prefix[y][x] +
                      prefix[y - k][x - k] -
                      prefix[y - k][x] -
                      prefix[y][x - k];
            max_sum = max(max_sum, val_sum);
        }
    }

    cout << max_sum << endl;

    return 0;
}