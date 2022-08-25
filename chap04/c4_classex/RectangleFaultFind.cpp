#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using std::cout;
using std::endl;

int main(void)
{
    Point pos1;
    pos1.InitMembers(2, 4); // true, false반환 -> 에러 조치 가능

    Point pos2;
    pos2.InitMembers(5, 9);

    Rectangle rec;
    rec.InitMembers(pos1, pos2);
    rec.ShowRecInfo();
    return 0;
}