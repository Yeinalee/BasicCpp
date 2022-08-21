#include <iostream>

using std::cout;
using std::endl;

void increase1(int &ref)
{ //인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
    ref++;
}

void InvertSign(int &ref)
{ //인자로 전달된 int형 변수의 부호를 바꾸는 함수
    ref *= -1;
}

int main(void)
{
    int var = 10;
    increase1(var);
    cout << var << endl;

    InvertSign(var);
    cout << var << endl;

    return 0;
}