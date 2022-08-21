#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool IsPositive(int num) // bool도 자료형 -> 함수의 변환형으로도 선언 가능
{
    if (num <= 0)
        return false;
    else
        return true;
}

int main(void)
{
    bool isPos;
    int num;

    cout << "Input Number : ";
    cin >> num;

    isPos = IsPositive(num);
    if (isPos)
        cout << "Positive Number" << endl;
    else
        cout << "Negative Number" << endl;

    return 0;
}