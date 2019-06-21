//Name: Nattapat Sriwichailumpun
//Lang: C++
#include <iostream>
using namespace std;

int main() {
    int height;
    cin >> height;
    int discount = 3;
    if(height >= 0 && height <= 120) {
        cout << "Free";
    } else if(height < 150) {
        discount = 8;
        cout << (150-height) * 8;
    } else cout << (164-height)*3;
    return 0;
}
