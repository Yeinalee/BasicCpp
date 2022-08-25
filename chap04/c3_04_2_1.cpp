#include <iostream>

using std::cout;
using std::endl;

class Point
{
private:
    int xpos, ypos;

public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    Point center;
    int r;

public:
    void Init(int x, int y, int radius)
    {
        center.Init(x, y);
        r = radius;
    }
    void ShowCircleInfo() const
    {
        cout << "radius : " << r << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle inner, outter;

public:
    void Init(int x1, int y1, int r1, int x2, int y2, int r2)
    {
        inner.Init(x1, y1, r1);
        outter.Init(x2, y2, r2);
    }

    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        inner.ShowCircleInfo();
        cout << "Outter Circle Info..." << endl;
        outter.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return 0;
}