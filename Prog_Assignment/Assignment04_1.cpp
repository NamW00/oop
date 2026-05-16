#include <iostream>
using namespace std;

class OrderedVecInt {
private:
    int capacity = 0, size = 0;
    int* arr = nullptr;
public:
    int get_size() {}
    int get_capacity() {}
    void insert(int k) {
        if()
    }




};

int main() {
    int n, k, target, target_index;
    OrderedVecInt vec;
    cin >> n;

    // Test insert
    for (int i = 0; i < n; i++) {
        cin >> k;
        vec.insert(k);
        cout << vec.get_capacity() << ' ';
    }
    cout << endl;

    // Test length() and []
    for (int i = 0; i < vec.get_size(); i++)
        cout << vec[i] << " ";  // indexing연산자 []를 제공한다.
    cout << endl;

    // Test find_index()
    cin >> target;
    int idx = vec.find_index(target);
    cout << idx << endl;

    // Test remove_by_val()
    cin >> target;
    if (vec.remove_by_val(target))
        cout << "Remove done" << endl;
    else
        cout << "Remove failed" << endl;
    cout << vec.get_size() << endl;

    // Test remove_by_index()
    cin >> target_index;
    if (vec.remove_by_index(target_index)) // 매개변수로 주어진 인덱스 위치의 정수를 삭제한다
        cout << "RemoveIndex done" << endl;     // db효한 인덱스이면 true
    else // 아니면 false를 반환한다.
        cout << "RemoveIndex failed" << endl;
    cout << vec.get_size() << endl;

    for (int i = 0; i < vec.get_size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
