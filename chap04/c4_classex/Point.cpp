#include <iostream>
#include "Point.h"

using std::cout;
using std::endl;

bool Point::InitMembers(int xpos, int ypos)
{
    if (xpos < 0 || xpos > 100 || ypos < 0 || ypos > 100) //잘못된 값이 전달되면 값의 저장을 허용X
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    x = xpos;
    y = ypos;
    return true;
}

int Point::GetX() const // const 함수, access함수
{
    return x;
}

int Point::GetY() const
{
    return y;
}

bool Point::SetX(int xpos)
{
    if (0 < xpos || xpos > 100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if (0 < ypos || ypos > 100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    y = ypos;
    return true;
}
