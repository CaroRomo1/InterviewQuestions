#include <iostream>
#include <string.h>

using namespace std;

void replaceSpace(char *str, int tl)
{
    int blank = 0;
    for(int i = 0; i < tl; i++)
    {
        if(str[i] == ' ')
        {
            blank++;
        }
    }

    int index = tl + (blank*2);

    for(int i = tl-1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            str[index-1]='0';
            str[index-2]='2';
            str[index-3]='%';

            index = index - 3;
        }
        else
        {
            str[index-1]= str[i];
            index--;
        }
    }
}

int main()
{
    char str[] = "Mr John Smith    ";
    int tl = 13;

    replaceSpace(str, tl);

    cout << str << endl;
}
