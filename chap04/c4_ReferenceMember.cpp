#include <iostream>

using std::cout;
using std::endl;

class AAA
{
public:
    AAA()
    {
        cout << "생성자 호출 Empty Object" << endl;
    }
    void ShowYourName()
    {
        cout << "I'm class AAA" << endl;
    }
};

class BBB
{
private:
    AAA &ref;
    const int &num;

public:
    BBB(AAA &r, const int &n)
        : ref(r), num(n) {}
    void ShowYourName()
    {
        ref.ShowYourName();
        cout << "and" << endl;
        cout << "I ref Num " << num << endl;
    }
};

int main(void)
{
    AAA obj1; //생성자 호출
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    return 0;
}