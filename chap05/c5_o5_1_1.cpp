#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

namespace POSITION
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };

    void ShowPosition(int pos)
    {
        switch (pos)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
            break;
        }
    }
}

class NameCard
{
private:
    char *name;
    char *company;
    char *tel;
    int rank;

public:
    NameCard(char *myName, char *myCompany, char *myTel, int myRank)
        : rank(myRank)
    {
        name = new char[strlen(myName) + 1];
        company = new char[strlen(myCompany) + 1];
        tel = new char[strlen(myTel) + 1];

        strcpy(name, myName);
        strcpy(company, myCompany);
        strcpy(tel, myTel);
    }

    NameCard(NameCard &copy)
        : rank(copy.rank)
    {
        name = new char[strlen(copy.name) + 1];
        company = new char[strlen(copy.company) + 1];
        tel = new char[strlen(copy.tel) + 1];

        strcpy(name, copy.name);
        strcpy(company, copy.company);
        strcpy(tel, copy.tel);
    }

    void ShowNameCardInfo()
    {
        cout << "이름 : " << name << endl;
        cout << "회사 : " << company << endl;
        cout << "전화번호 : " << tel << endl;
        cout << "직급 : ";
        POSITION::ShowPosition(rank);
    }

    ~NameCard()
    {
        delete[] name;
        delete[] company;
        delete[] tel;
    }
};
int main(void)
{
    NameCard manClerk((char *)"Lee", (char *)"ABC", (char *)"010-1111-2222", POSITION::CLERK);
    NameCard copy1 = manClerk;

    copy1.ShowNameCardInfo();

    return 0;
}