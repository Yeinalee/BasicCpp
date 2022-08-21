#include <iostream>
#define MAX 100

using std::cin;
using std::cout;
using std::endl;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

typedef struct
{
    int accID;              // 계좌번호
    int balance;            // 잔액
    char cusName[NAME_LEN]; // 고객 이름
} Account;

Account accArr[MAX]; // Account 정보 저장 배열
int accNum = 0;      //저장된 Account 수

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
    cout << "\n[계좌개설]\n계좌ID : ";
    cin >> accArr[accNum].accID;

    cout << "이름 : ";
    cin >> accArr[accNum].cusName;

    cout << "입금액 : ";
    cin >> accArr[accNum].balance;

    cout << endl;

    accNum++;
}

void DepositMoney(void)
{
    int id, money;
    cout << "\n[입  금]\n계좌 ID : ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].accID == id)
        {
            cout << "입금액 : ";
            cin >> money;
            accArr[i].balance += money;
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
        if (accArr[i].accID == id)
        {
            cout << "출금액 : ";
            cin >> money;
            if (accArr[i].balance < money)
            {
                cout << "잔액부족" << endl
                     << endl;
                return;
            }
            accArr[i].balance -= money;
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
        cout << "\n계좌ID : " << accArr[i].accID << endl;
        cout << "이름 : " << accArr[i].cusName << endl;
        cout << "잔액 : " << accArr[i].balance << endl
             << endl;
    }
}