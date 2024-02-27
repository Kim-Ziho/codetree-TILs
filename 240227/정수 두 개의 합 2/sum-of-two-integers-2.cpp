#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);

    int j = n - 1;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        while (j > i && arr[i] + arr[j] > k) {
            j--;
        }
        if (j == i) break;
        else {
            answer += j - i;
        }
    }

    cout << answer;

    return 0;
}