#include <iostream>

using std::cout;
using std::endl;

//반환형이 참조형
int &RefRetFunc(int &ref) // int &ref = num1
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 1;
    int &num2 = RefRetFunc(num1); // int &num2 = ref;

    num1++;
    num2++;
    cout << "num1 : " << num1 << endl;
    cout << "num2 : " << num2 << endl;

    return 0;
}