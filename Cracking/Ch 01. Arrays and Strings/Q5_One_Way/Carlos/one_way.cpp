#include <iostream>

using namespace std;

bool oneInsert(string str1, string str2)
{
    bool dif = false;

    int index1=0;
    int index2=0;

    while(index1 < str1.length() && index2 < str2.length())
    {
        if(str1[index1] != str2[index2])
        {
            if(dif)
            {
                return false;
            }
            dif = true;

            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneReplace(string str1, string str2)
{
    bool dif = false;

    for(int i=0; i < str1.length(); i++)
    {
        if(str1[i] != str2[i])
        {
            if(dif)
            {
                return false;
            }
            dif = true;
        }
    }
    return true;
}

bool checkOneWay(string str1, string str2)
{
    if(str1.length() == str2.length())
    {
        return oneReplace(str1, str2);
    }
    else if(str1.length()+1 == str2.length())
    {
        return oneInsert(str1, str2);
    }
    else if(str1.length()-1 == str2.length())
    {
        return oneInsert(str2, str1);
    }

    return false;
}

int main()
{
    string str1, str2;

    cout << "String 1:" << endl;
    cin >> str1;

    cout << "String 2:" << endl;
    cin >> str2;

    if(checkOneWay(str1, str2))
    {
        cout << "One Way = true" << endl;
    }
    else
    {
        cout << "One Way = false" << endl;
    }

}
