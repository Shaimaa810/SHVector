#include <bits/stdc++.h>
using namespace std;
#include "SHVector.h"

template<class t>
ostream& operator<<(ostream& out, SHVector<t> vec){
    for (int i = 0; i < vec.Size; ++i) {
        out << vec.data[i] << " ";
    }
    return out;
}

int main() {
    int arr[25];
    for (int i = 1; i <= 25; ++i) {
        arr[i - 1] = i;
    }
    SHVector<int>v(arr, 20);
    cout << "Initial vector:\n";
    cout << v << '\n';
    // size, capacity
    cout << "size =  " << v.size() << '\n';
    cout << "Capacity =  " << v.capacity() << '\n';
    // push_back()
    v.push_back(30);
    v.push_back(40);
    cout << "Vector after adding elements 30, 40 at the end by push_back() function\n";
    cout << "Vector content:    " << v << '\n';
    cout << "Size =  " << v.size() << '\n';
    // erase
    SHVector<int>:: iterator it1 = v.begin(), it2 = v.begin();
    it2 += 3;
    v.erase(it1, it2);
    cout << "Vector after deleting first 3 elements:\n";
    cout << "Vector content:    " << v << '\n';
    cout << "Size =  " << v.size() << '\n';
    // pop_back
    cout << "Delete last 2 elements by pop_back() function\n";
    v.pop_back();
    v.pop_back();
    cout << "Vector content:    " << v << '\n';
    cout << "Size =  " << v.size() << '\n';
    return 0;

}
