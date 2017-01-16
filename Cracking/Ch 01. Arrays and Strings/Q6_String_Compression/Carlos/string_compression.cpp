#include <iostream>
#include <string>

using namespace std;

int countCompression(string str)
{
    char aux = ' ';
    int cont=0;

    for(int i=0; i < str.length(); i++)
    {
        if(aux!=str[i])
        {
            cont++;
            aux = str[i];
        }
    }
    return cont*2;
}

string stringCompress(string str)
{
    int compressLength = countCompression(str);
    if(str.length() < compressLength)
    {
        return str;
    }

    string compStr = "";
    int cont=0;
    for(int i=0; i < str.length(); i++)
    {
        cont++;

        if(i+1 >= str.length() || str[i] != str[i+1])
        {
            compStr += str[i];
            compStr += to_string(cont);
            cont = 0;
        }
    }
    return compStr;
}

int main()
{
    string str, comp;

    cout << "String:" << endl;
    cin >> str;

    comp = stringCompress(str);

    cout << endl <<"Compressed String:" << endl << comp << endl;

	system("pause");
}
