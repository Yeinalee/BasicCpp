#include <iostream>

using std::cout;
using std::endl;

namespace CAR_CONST
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10,
    };
}

class Car // class 선언
{
private: //클래스 내에서만 접근 가능
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public: //어디서든 접근 가능
    void InitMembers(char *ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

//클래스 안에 선언된 변수의 초기화를 목적으로 정의된 함수
// public으로 선언되어 main함수에서 호출 가능 -> private로 선언된 변수에 접근
void Car::InitMembers(char *ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "소유자 ID : " << gamerID << endl;
    cout << "연료량 : " << fuelGauge << "%" << endl;
    cout << "현재 속도 : " << curSpeed << "km/s" << endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{

    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    return 0;
}