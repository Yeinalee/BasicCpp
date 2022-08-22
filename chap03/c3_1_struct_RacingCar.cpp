#include <iostream>

using std::cout;
using std::endl;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2 // Accel하면 연료량 2 감소
#define ACC_STEP 10 // Accel하면 속도 10씩 증가
#define BRK_STEP 10 // Break하면 속도 10씩 감소

//구조체 정의
struct Car
{
    char gamerID[ID_LEN]; //소유자 ID
    int fuelGauge;        //연료량
    int curSpeed;         //현재속도
};

//차의 정보를 출력하는 기능의 함수
//단순히 출력 = 값 변화X -> const!
void ShowCarState(const Car &car)
{
    cout << "소유자 ID : " << car.gamerID << endl;
    cout << "연료량 : " << car.fuelGauge << "%" << endl;
    cout << "현재 속도 : " << car.curSpeed << "km/s" << endl;
}

//차의 가속을 위해 엑셀을 밟은 상황을 표현한 함수
void Accel(Car &car)
{
    if (car.fuelGauge <= 0) // accel하면 연료 사용
        return;
    else
        car.fuelGauge -= FUEL_STEP;

    if (car.curSpeed + ACC_STEP >= MAX_SPD)
    {
        car.curSpeed = MAX_SPD;
        return;
    }
    car.curSpeed += ACC_STEP;
}

//차의 감속을 위해 브레이크를 밟은 상황을 표현한 함수
void Break(Car &car)
{
    //연료 사용 고려X

    if (car.curSpeed < BRK_STEP)
    {
        car.curSpeed = 0;
        return;
    }
    car.curSpeed -= BRK_STEP;
}

int main(void)
{
    Car run99 = {"run99", 100, 0}; //구조체 변수의 선언, 초기화
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);
    Break(run99);
    ShowCarState(run99);

    return 0;
}