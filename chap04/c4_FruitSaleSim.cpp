#include <iostream>

using std::cout;
using std::endl;

class FruitSeller
{
private:
    const int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    FruitSeller(int price, int num, int money)
        : APPLE_PRICE(price), numOfApples(num), myMoney(money)
    {
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    FruitBuyer(int money)
        : myMoney(money), numOfApples(0) {}
};