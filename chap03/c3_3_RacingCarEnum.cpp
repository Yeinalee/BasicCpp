#include <iostream>

using std::cout;
using std::endl;

namespace CAR_CONST //이름공간 안에 구조체 Car에서 사용하는 상수들을 모아 놓음
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2, // Accel하면 연료량 2 감소
        ACC_STEP = 10, // Accel하면 속도 10씩 증가
        BRK_STEP = 10, // Break하면 속도 10씩 감소
    };
}

//함수를 멤버로 지니는 구조체 정의
struct Car
{
    char gamerID[CAR_CONST::ID_LEN]; //소유자 ID
    int fuelGauge;                   //연료량
    int curSpeed;                    //현재속도

    //차의 정보를 출력하는 기능의 함수
    //단순히 출력 = 값 변화X -> const!
    void ShowCarState()
    {
        cout << "소유자 ID : " << gamerID << endl;
        cout << "연료량 : " << fuelGauge << "%" << endl;
        cout << "현재 속도 : " << curSpeed << "km/s" << endl;
    }

    //차의 가속을 위해 엑셀을 밟은 상황을 표현한 함수
    void Accel()
    {
        if (fuelGauge <= 0) // accel하면 연료 사용
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

    //차의 감속을 위해 브레이크를 밟은 상황을 표현한 함수
    void Break()
    {
        //연료 사용 고려X

        if (curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }
        curSpeed -= CAR_CONST::BRK_STEP;
    }
};

int main(void)
{
    Car run99 = {"run99", 100, 0}; //구조체 변수의 선언, 초기화
    run99.Accel();                 //구조체 변수를 대상으로 함수 호출
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    return 0;
}