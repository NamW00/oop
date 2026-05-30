#include <iostream>
using namespace std;
void PrintMatrix(int n) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (num % 9) + 1 << " ";
            num++;
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    PrintMatrix(n);
    return 0;
}