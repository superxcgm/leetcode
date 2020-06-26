#include <iostream>
#include <cstdio>

using namespace std;

int bin[1002];

int m_find(int x) {
    int root = x;
    while (bin[root] != root) {
        root = bin[root];
    }
    return root;
}

void m_merge(int a, int b) {
    int ra, rb;
    ra = m_find(a);
    rb = m_find(b);
    if (ra != rb) {
        bin[ra] = rb;
    }
}

int main() {
    int n_city;
    int n_road;

    while (cin >> n_city && n_city) {
        cin >> n_road;
        if (n_road == 0) {
            cout << (n_city - 1) << endl;
            continue;
        }

        for (int i = 1; i <= n_city; ++i) {
            bin[i] = i;
        }

        for (int i = 0; i < n_road; ++i) {
            int a, b;
            cin >> a >> b;
            m_merge(a, b);
        }
        int count = -1;
        for (int i = 1; i <= n_city; ++i) {
            if (bin[i] == i) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}