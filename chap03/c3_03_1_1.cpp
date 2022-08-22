#include <iostream>

using std::cout;
using std::endl;

struct Point
{
    int xpos;
    int ypos;

    //점의 좌표이동
    void MovePos(int x, int y)
    {
        xpos += x;
        ypos += y;
    }

    //점의 좌표증가
    void AddPoint(const Point &pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    //현재 x,y의 좌표정보 출력
    void ShowPosition()
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

int main(void)
{
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();

    return 0;
}