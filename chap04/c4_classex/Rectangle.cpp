#include <iostream>
#include "Rectangle.h"

using std::cout;
using std::endl;

bool Rectangle::InitMembers(const Point &ul, const Point &rl)
{
    if (ul.GetX() > rl.GetX() || ul.GetY() > rl.GetY())
    {
        cout << "잘못된 위치정보 전달" << endl;
        return false;
    }

    upLeft = ul;
    lowRight = rl;
    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "좌 상단 : "
         << "[" << upLeft.GetX() << ",";
    cout << upLeft.GetY() << "]" << endl;

    cout << "우 하단 : "
         << "[" << lowRight.GetX() << ",";
    cout << lowRight.GetY() << "]" << endl;
}