#include <iostream>
using namespace std;

int main()
{
    int a = 50, b = 4;

    int c = ++b - --b - --a + a++;
    cout << c; // Should output 1


}