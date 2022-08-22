#include <iostream>

using std::cout;
using std::endl;

class Calculator
{
private:
    int num[4];

public:
    void Init(void);
    float Add(float a, float b);
    float Min(float a, float b);
    float Div(float a, float b);
    float Mul(float a, float b);
    void ShowCount(void);
};

void Calculator::Init(void)
{
    for (int i = 0; i < 4; i++)
    {
        num[i] = 0;
    }
}

float Calculator::Add(float a, float b)
{
    num[0]++;
    return a + b;
}

float Calculator::Min(float a, float b)
{
    num[1]++;
    return a - b;
}

float Calculator::Div(float a, float b)
{
    num[2]++;
    return a / b;
}

float Calculator::Mul(float a, float b)
{
    num[3]++;
    return a * b;
}

void Calculator::ShowCount(void)
{
    cout << "덧셈 : " << num[0];
    cout << " 뺄셈 : " << num[1];
    cout << " 곱셈 : " << num[2];
    cout << " 나눗셈 : " << num[3] << endl;
}

int main(void)
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 * 1.2 = " << cal.Mul(4.9, 1.2) << endl;
    cal.ShowCount();

    return 0;
}