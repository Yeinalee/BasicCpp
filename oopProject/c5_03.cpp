#include <iostream>
#include <cstring>
#define MAX 100

using std::cin;
using std::cout;
using std::endl;
const int NAME_LEN = 20;

void ShowMenu(void);       //메뉴 츌력
void MakeAccount(void);    //계좌개설을 위한 함수
void DepositMoney(void);   //입금
void WithdrawMoney(void);  //출금
void ShowAllAccInfo(void); //잔액조회

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

class Account
{
private:
    int accID;     // 계좌번호
    int balance;   // 잔액
    char *cusName; // 고객 이름

public:
    Account(int ID, int money, char *name) : accID(ID), balance(money)
    {
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }

    Account(const Account &ref)
        : accID(ref.accID), balance(ref.balance)
    {
        cusName = new char[strlen(ref.cusName) + 1];
        strcpy(cusName, ref.cusName);
    }

    int GetAccID() { return accID; }

    void Deposit(int money)
    {
        balance += money;
    }

    int Withdraw(int money)
    {
        if (balance < money)
            return 0;
        balance -= money;
        return money;
    }

    void ShowAccInfo()
    {
        cout << "계좌 ID : " << accID << endl;
        cout << "이름 : " << cusName << endl;
        cout << "잔액 : " << balance << endl;
    }

    ~Account()
    {
        delete[] cusName;
    }
};

Account *accArr[100];
int accNum = 0;

int main(void)
{
    int op = 0;

    do
    {
        ShowMenu();
        cin >> op;

        switch (op)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
        default:
            break;
        }
    } while (op != 5);

    cout << "\n프로그램을 종료합니다" << endl;
    return 0;
}

void ShowMenu(void)
{
    cout << "-----Menu-----\n1. 계좌개설\n2. 입금\n3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력\n5. 프로그램 종료\n선택 : ";
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "\n[계좌개설]\n계좌ID : ";
    cin >> id;

    cout << "이름 : ";
    cin >> name;

    cout << "입금액 : ";
    cin >> balance;

    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
    int id, money;
    cout << "\n[입  금]\n계좌 ID : ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            cout << "출금액 : ";
            cin >> money;
            accArr[i]->Deposit(money);
            cout << "입금 완료" << endl
                 << endl;

            return;
        }
    }
    cout << "유효하지 않은 ID입니다.\n"
         << endl;
}

void WithdrawMoney(void)
{
    int id, money;
    cout << "\n[출  금]\n계좌 ID : ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            cout << "출금액 : ";
            cin >> money;
            if (accArr[i]->Withdraw(money) == 0)
            {
                cout << "잔액부족" << endl
                     << endl;
                return;
            }
            cout << "출금 완료" << endl
                 << endl;

            return;
        }
    }
    cout << "\n유효하지 않은 ID입니다.\n"
         << endl;
}

void ShowAllAccInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}