//
// Created by yangzhengkun on 2018/8/9.
//
#include <iostream>
#include <vector>

using namespace std;


int findInParitialluSortedMatrix(const vector<vector<int>> &arr, int rows, int cols, int value)
{
    if (arr.empty())
        return 0;
    bool found = false;
    int i = 0, j = cols - 1;
    while (i < rows && j >= 0)
    {
        if (arr[i][j] == value)
        {
            found = true;
            break;
        }
        else if (arr[i][j] < value)
        {
            ++i;
        }
        else
        {
            // arr[i][j] > value
            --j;
        }
    }
    return found;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 8,  9},
                               {2, 4, 9,  12},
                               {4, 7, 10, 13},
                               {6, 8, 11, 15}};
    auto ret = findInParitialluSortedMatrix(arr, 4, 4, 5);
    cout << boolalpha << ret << endl;
    return 0;
}
