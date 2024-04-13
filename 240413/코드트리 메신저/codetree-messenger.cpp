#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[100001];
int a[100001];
int val[100001];
bool is_off[100001];
vector<vector<int>> num(100001, vector<int>(21));
int n;
int q;

void print_all() {
    cout << "p : ";
    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';
    cout << endl;
    cout << "a : ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    cout << "o : ";
    for (int i = 1; i <= n; i++)
        cout << is_off[i] << ' ';
    cout << endl;
    cout << "n : ";
    for (int i = 1; i <= n; i++) {
        cout << val[i] << ' ';
    }
    cout << endl;
}

void print_num() {
    for (int i = 1; i <= 10; i++) {
        cout << i << " : ";
        for (int j = 0; j <= 5; j++) {
            cout << num[i][j] << ' ';
        }
        cout << endl;
    }
}

void spread(int now, int power) {
    if (power < 0 || now < 0) return;

    num[now][power]++;
    val[now]++;
    spread(p[now], --power);
}

void ready () {
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] > 20) a[i] = 20;
        
        num[i][a[i]]++;
        spread(p[i], a[i] - 1);
    }

}

void turn_on (int tar) {
    int parent = p[tar];
    int idx = 1;
    while (parent) {
        for (int power = idx; power < 21; power++) {
            num[parent][power - idx] += num[tar][power];
            val[parent] += num[tar][power];
        }
        if (is_off[parent]) break;
        idx++;
        parent = p[parent];
    }
}

void turn_off (int tar) {
    int parent = p[tar];
    int idx = 1;
    while (parent) {
        for (int power = idx; power < 21; power++) {
            num[parent][power - idx] -= num[tar][power];
            val[parent] -= num[tar][power];
        }
        if (is_off[parent]) break;
        idx++;
        parent = p[parent];
    }
}

void toggle (int tar) {
    is_off[tar] = is_off[tar] == false ? true : false;

    if (is_off[tar]) turn_off(tar);
    else turn_on(tar);
}

void change_power (int tar, int power) {
    int bef_power = a[tar];
    int parent = tar;
    while (parent) {
        num[parent][bef_power--]--;
        val[parent]--;

        if (bef_power < 0 || is_off[parent]) break;
        parent = p[parent];
    }
    a[tar] = power;
    parent = tar;
    while (parent) {
        num[parent][power--]++;
        val[parent]++;

        if (power < 0 || is_off[parent]) break;
        parent = p[parent];
    }
}

void exchange_parent (int c1, int c2) {
    if (!is_off[c1]) turn_off(c1);
    if (!is_off[c2]) turn_off(c2);

    swap(p[c1], p[c2]);

    if (!is_off[c1]) turn_on(c1);
    if (!is_off[c2]) turn_on(c2);
}

void search (int tar) {
    cout << val[tar] << endl;
}

int main() {
    cin >> n >> q;
    
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;


        int tar, power, c1, c2;

        if (query == 100) ready();
        else if (query == 200) {
            cin >> tar;
            toggle(tar);
        }
        else if (query == 300) {
            cin >> tar >> power;
            change_power(tar, power);
        }
        else if (query == 400) {
            cin >> c1 >> c2;
            exchange_parent(c1, c2);
        }
        else if (query == 500) {
            cin >> tar;
            search(tar);
        }
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}