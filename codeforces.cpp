#include <iostream>
#include <cmath>
using namespace std;


string canAliceWin(int n, int a, int b) {
    int distance = abs(a - b);
    if (distance % 2 == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << canAliceWin(n, a, b) << endl;
    }

    return 0;
}
