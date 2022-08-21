#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    int num1 = 1020;
    int &num2 = num1; // num2는 num1의 참조자 -> num1, num2는 동일한 메모리 공간 참조

    num2 = 3047;
    cout << "VAL : " << num1 << endl;
    cout << "REF : " << num2 << endl; //동일한 메모리 공간을 참조함

    cout << "VAL : " << &num1 << endl;
    cout << "REF : " << &num2 << endl;

    return 0;
}