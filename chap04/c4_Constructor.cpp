#include <iostream>

using std::cout;
using std::endl;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass(int n1 = 0, int n2 = 0) //디폴트값 설정 가능
    {
        num1 = n1;
        num2 = n2;
    }

    void ShowData() const
    {
        cout << num1 << ' ' << num2 << endl;
    }
};

int main(void)
{
    SimpleClass sc1(void); //함수의 원형 선언
    SimpleClass mysc = sc1();

    mysc.ShowData();

    return 0;
}

SimpleClass sc1()
{
    SimpleClass sc(20, 30);
    return sc;
}
