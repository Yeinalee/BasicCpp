#include <iostream>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::endl;

char *MakeStrAdr(int len)
{
    //문자열 저장을 위한 배열을 힙 영역에 할당
    // char *str = (char *)malloc(sizeof(char) * len);
    char *str = new char[len];
    return str;
}

int main(void)
{
    char *str = MakeStrAdr(20);
    strcpy(str, "I am so Happy");

    cout << str << endl;

    //힙에 할당된 메모리 공간 소멸
    // free(str);
    delete[] str;

    return 0;
}