#include <iostream>

using std::cout;
using std::endl;

class AAA
{
private:
    int num;

public:
    AAA() : num(0) {} // class 외부에서는 이 생성자를 기반으로 객체 생성

    AAA &CreateInitObj(int n) const
    {
        AAA *ptr = new AAA(n); // private 생성자를 이용해 AAA객체 생성, 반환
        return *ptr;
    }

    void ShowNum() const { cout << num << endl; }

private:
    AAA(int n) : num(n) {}
};

int main(void)
{
    AAA base;
    base.ShowNum();

    AAA &obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA &obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    delete &obj1;
    delete &obj2;

    return 0;
}