#include <iostream>
#include <iomanip>
using namespace std;


int** solve(int* res, int size)
{
    int** arr = new int* [res[0]];
    for (int i = 0; i < res[0]; i++)
    {
        arr[i] = new int[res[1]];
    }

    size -= 2;
    int idx = 2;
    for (int i = 0; i < res[0]; i++)
    {
        for (int j = 0; j < res[1]; j++)
        {
            if (size == 0)
                arr[i][j] = 0;
            else
            {
                arr[i][j] = res[idx];
                idx++;
                size--;
            }
        }
    }
    return arr;
}

int main(int argv, char* argc[])
{
    int** arr;
    int res[] = { 3,4,5,6,7,8,9 ,10 };
    int size = sizeof(res) / sizeof(res[0]);
    arr = solve(res, size);

    for (int i = 0; i < res[0]; i++)
    {
        for (int j = 0; j < res[1]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    //Delete array
    for (int i = 0; i < res[0]; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
