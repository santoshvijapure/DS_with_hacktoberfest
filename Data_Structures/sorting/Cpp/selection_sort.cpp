#include <iostream>

using namespace std;

int main()
{
    int vector[5] = {3, 1, 4, 7, 5}, list[5];

    int minor, ind_minor;

    for (int i = 1; i <= 5; i++)
    {
        minor = 10000000;
        for (int j = 1; j <= 5; j++)
        {
            if (list[j] == 0 and vector[j] < minor)
            {
                minor = vector[j];
                ind_minor = j;
            }
        }
        cout << minor << " ";
        list[ind_minor] = 1;
        cout << list[ind_minor];
    }

    return 0;
}