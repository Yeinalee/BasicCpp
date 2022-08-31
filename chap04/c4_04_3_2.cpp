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
    NameCard(char *myName, char *myCompany, char *mytel, int myrank)
        : rank(myrank)
    {
        name = new char[strlen(myName) + 1];
        company = new char[strlen(myCompany) + 1];
        tel = new char[strlen(mytel) + 1];
        strcpy(name, myName);
        strcpy(company, myCompany);
        strcpy(tel, mytel);
    }

    void ShowNameCardInfo()
    {
        cout << "이름 : " << name << endl;
        cout << "회사 : " << company << endl;
        cout << "전화번호 : " << tel << endl;
        cout << "직급 : ";
        POSITION::ShowPosition(rank);
        cout << endl;
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
    NameCard manClerk((char *)"GANADA", (char *)"LAMABA", (char *)"010-2222-1111", POSITION::ASSIST);
    manClerk.ShowNameCardInfo();

    return 0;
}