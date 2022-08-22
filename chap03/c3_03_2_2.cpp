#include <iostream>
#include <cstring>
#define MAX 100

using std::cout;
using std::endl;

class Printer
{
private:
    char Instring[MAX];

public:
    void SetString(char *sentence);
    void ShowString(void);
};

void Printer::SetString(char *sentence)
{
    strcpy(Instring, sentence);
}

void Printer::ShowString(void)
{
    cout << Instring << endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();

    return 0;
}