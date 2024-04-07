#include <iostream>
using namespace std;

int arr1[201];
int arr2[201];
int arr3[201];
int n;
int t;

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> arr1[i];
    for (int i = 1; i <= n; i++)
        cin >> arr2[i];
    for (int i = 1; i <= n; i++)
        cin >> arr3[i];

    while(t--) {
        int tmp1 = arr1[n];
        int tmp2 = arr2[n];
        int tmp3 = arr3[n];

        for (int i = n; i > 1; i--)
            arr1[i] = arr1[i - 1];
        arr1[1] = tmp3;
        for (int i = n; i > 1; i--)
            arr2[i] = arr2[i - 1];
        arr2[1] = tmp1;
        for (int i = n; i > 1; i--)
            arr3[i] = arr3[i - 1];
        arr3[1] = tmp2;
    }
    for (int i = 1; i <= n; i++)
        cout << arr1[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << arr2[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << arr3[i] << ' ';
    cout << endl;

    // 여기에 코드를 작성해주세요.
    return 0;
}