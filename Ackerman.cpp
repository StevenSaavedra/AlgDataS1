#include <iostream>
using namespace std;

unsigned long long Ackermann(unsigned int m, unsigned long long n) {
    if (m == 0) return n + 1;
    if (m == 1) return n + 2;
    if (m == 2) return 2 * n + 3;
    if (m == 3) return (1ULL << (n + 3)) - 3;
    return -1;
}

int alpha(unsigned long long n) {
    int m = 1;
    while (true) {
        unsigned long long val = Ackermann(m, m);
        if (val >= n) return m;
        m++;
        if (m > 4) return 4;
    }
}

int main() {
    unsigned long long testVals[] = {10, 100, 1000, 1000000ULL, 1000000000ULL};
    int size = sizeof(testVals) / sizeof(testVals[0]);

    for (int i = 0; i < size; i++) {
        cout << "α(" << testVals[i] << ") = " << alpha(testVals[i]) << endl;
    }
    return 0;
}
