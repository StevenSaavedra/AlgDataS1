#include <iostream>
using namespace std;

const int N = 6;
int parent[N];
int rankArr[N];
void makeSet(int x) {
    parent[x] = x;
    rankArr[x] = 0;
}


int findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);

    if (rootX == rootY) return;

    if (rankArr[rootX] < rankArr[rootY]) {
        parent[rootX] = rootY;
    } else if (rankArr[rootX] > rankArr[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rankArr[rootX]++;
    }
}

void printParent() {
    cout << "Parent array: ";
    for (int i = 1; i <= 5; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 5; i++) makeSet(i);
    cout << "After MakeSet: ";
    printParent();

    unionSet(1, 2);
    cout << "After Union(1,2): ";
    printParent();

    unionSet(2, 3);
    cout << "After Union(2,3): ";
    printParent();

    unionSet(4, 5);
    cout << "After Union(4,5): ";
    printParent();

    unionSet(3, 5);
    cout << "After Union(3,5): ";
    printParent();

    cout << "Find(1) = " << findSet(1) << endl;
    cout << "Find(4) = " << findSet(4) << endl;
    cout << "Find(5) = " << findSet(5) << endl;

    cout << "After Finds with path compression: ";
    printParent();

    return 0;
}
