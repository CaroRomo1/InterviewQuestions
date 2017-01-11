#include <iostream>
#include <algorithm>

using namespace std;

//Método verifica que la cantidad de caracteres induviduales sean iguales en los dos strings
bool checkPerm(string str1, string str2)
{
    if(str1.length() != str2.length())
    {
        return false;
    }

    int letras[128];
    int valASCII;

    for(int i=0; i < str1.length(); i++)
    {
        valASCII = str1[i];
        letras[valASCII]++;
    }

    for(int i=0; i < str2.length(); i++)
    {
        valASCII = str2[i];
        letras[valASCII]--;

        if(letras[valASCII] < 0)
        {
            return false;
        }
    }

    return true;
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
