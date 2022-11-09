//
// Created by Hleonor on 2022-11-09.
//
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<bool>prime(999999, false);

bool isPrime(int number)
{
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int countPrime(int n)
{
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == false) // 默认都不是合数
        {
            cnt++;
            for (int j = i + i; j < n; j += i) // 将非合数的数倍增，注意，j的初始值设置为i*i虽然可以减少循环次数，但是会导致j溢出
            {
                prime[j] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    int primeNumber;
    scanf("%d", &primeNumber);
    printf("%d" , countPrime(primeNumber));
    return 0;
}