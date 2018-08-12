//
// Created by yangzhengkun on 2018/8/9.
//

// 将字符串中的空格替换为"%20"

#include <iostream>

using namespace std;

/**
 * @param str 待替换字符串
 * @param length 数组最大长度，可容纳替换后的字符串
 */
void replaceStringSpaces(char str[], int length)
{
    if (str == nullptr || length <= 0)
        return;
    int originalLength = 0;
    int numOfSpaces = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        ++originalLength;
        if (str[i] == ' ')
            ++numOfSpaces;
        ++i;
    }

    int newLength = originalLength + 2 * numOfSpaces;
    if (newLength > length)
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew >= indexOfOriginal)
    {
        if (str[indexOfOriginal] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
            str[indexOfNew--] = str[indexOfOriginal];
        --indexOfOriginal;
    }
}

int main()
{
    char str[50] = "This is a test.";
    replaceStringSpaces(str, 50);
    cout << str << endl;
    return 0;
}