#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    int arr[3] = {1, 3};
    int &ref1 = arr[0]; //배열 요소는 변수로 간주 -> 참조자 선언 가능
    int &ref2 = arr[1];
    int &ref3 = arr[2];

    cout << ref1 << endl;
    cout << ref2 << endl;

    int num = 12;
    int &ref = num;

    int *ptr = &num;
    int *(&pref) = ptr; //포인터 변수의 참조자 선언

    int **dptr = &ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;
    cout << *pref << endl; // num에 저장된 값 출력
    cout << **dpref << endl;

    return 0;
}