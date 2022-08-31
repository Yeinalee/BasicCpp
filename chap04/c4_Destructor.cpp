#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Person
{
private:
    char *name;
    int age;

public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    void ShowPersonInfo() const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }

    ~Person() //소멸자 -> 할당된 메모리 공간의 소멸에 대한 코드
    {
        delete[] name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("따다다따아아", 100);
    Person man2("뚜두두우두두뚜ㅜ", 200);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}