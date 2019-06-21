//Name: Nattapat Sriwichailumpun
//Lang: C++
#include <iostream>
using namespace std;
int arr[2000000];
char cut;
string str;
int countA,countB;
int main() {
    cin >> cut;
    cin >> str;
    arr[0] = 1;
    for(int i=0;i<str.size();i++) {
        if(str[i] == cut) {
            countA++;
            arr[i] = 0;
            arr[i+1] = 1;
        }
    }
    for(int i=1;i<str.size();i++)
        arr[i] += arr[i-1];
    cout << countA << "\n" << arr[str.size()-1];
    return 0;
}
