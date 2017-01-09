#include "string.h"
#include <iostream>

//Respuesta correcta utilizando ASCII
using namespace std;

bool isUnique(string str)
{
    bool isThere[128] = {false};
    int pos;

    //if > 128
    if(str.length() > 128)
    {
        return false;
    }

    for(int i=0; i < str.length(); i++)
    {
        pos = str[i];
        if(isThere[pos])
        {
            return false;
        }
        isThere[pos] = true;
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    if(isUnique(str))
    {
        cout << "Es unico" << endl;
    }
    else
    {
        cout << "Se repite un caracter" << endl;
    }
}


