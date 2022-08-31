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
    Person(char *myName, int myAge)
    {
        int len = strlen(myName) + 1;
        name = new char[len];
        strcpy(name, myName);
        age = myAge;
    }

    Person(const Person &copy)
        : age(copy.age)
    {
        name = new char[strlen(copy.name) + 1]; //깊은 복사
        strcpy(name, copy.name);
    }

    void ShowPersonInfo() const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }

    ~Person()
    {
        delete[] name;
        cout << "Called destructor" << endl;
    }
};

int main(void)
{
    Person man1("Lee", 23);
    Person man2 = man1; //디폴트 복사 생성자에 의한 멤버 대 멤버 복사 진행
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}