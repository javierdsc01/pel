#include <iostream>
using namespace std;

/*
void function(int i){
    if (i == 1){
        return 1;
    } else {
        return i + function(i - 1);
    }
};
*/

int function0(int a)
{
    if (a < 10)
    {
        return a;
    }
    else
    {
        int b = function0(a / 10) + a % 10;
        cout << "Suma: " << b;
        return b;
    }
}

int function1()
{
    
}

int main(int, char **)
{
    // function(3);
    function(45);
}