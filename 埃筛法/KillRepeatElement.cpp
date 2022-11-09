//
// Created by Hleonor on 2022-11-09.
//
#include <iostream>
#Include <vector>
using namespace std;

void removeRepeat(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
}

int main()
{
    vector<int> v;
    int number = 0;
    scanf("%d", &number);
    while (number != -1)
    {
        v.push_back(number);
        scanf("%d", &number);
    }

    return 0;
}