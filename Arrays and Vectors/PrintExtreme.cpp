#include <iostream>
using namespace std;

void printExtreme(int n, int arr[])
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        if (arr[start] == arr[end])
        {
            cout << arr[start] << endl;
        }
        else
        {
            cout << arr[start] << endl;
            cout << arr[end] << endl;
        }
        start++;
        end--;
    }
}
int main()
{

    int arr[5] = {10, 20, 30, 40, 50};
    printExtreme(5, arr);
    return 0;
}