#include "string.h"
#include <iostream>

using namespace std;

bool isUnique(string str)
{
    for(int i=0; i < str.length(); i++)
    {
        for(int j=0; j < str.length(); j++)
        {
            if((str[i] == str[j]) && (i != j))
            {
                return false;
            }
        }
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


