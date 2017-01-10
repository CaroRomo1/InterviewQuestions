#include <iostream>
#include <algorithm>

using namespace std;

//Metodo que devuelve el string ordenado
string sortStr(string str)
{
    sort(str.begin(), str.end());
    return str;
}

//Método compara los strings ordenados y define si es o no permutacion.
bool checkPerm(string str1, string str2)
{
    if(str1.length() != str2.length())
    {
        return false;
    }

    if(sortStr(str1) == sortStr(str2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str1, str2;
    bool perm = false;

    cout << "String 1: " << endl;
    getline(cin, str1);

    cout << "String 2: " << endl;
    getline(cin, str2);

    perm = checkPerm(str1, str2);

    if(perm)
    {
        cout << "Si es permutacion" << endl;
    }
    else
    {
        cout << "No es permutacion" << endl;
    }
}
