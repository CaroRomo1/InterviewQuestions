#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string str1, string str2)
{
	if (str1.find(str2) != string::npos)
	{
		return true;
	}
	return false;
}

bool isRotation(string s1, string s2)
{
	int len = s1.length();

	if (len == s2.length() && len > 0)
	{
		string s1s1 = s1 + s1;
		return isSubstring(s1s1, s2);
	}
	return false;
}

int main()
{
	string s1, s2;

	cout << "String 1: " << endl;
	getline(cin, s1);

	cout << "String 2: " << endl;
	getline(cin, s2);

	if (isRotation(s1, s2))
	{
		cout << "Rotation = true" << endl;
	}
	else
	{
		cout << "Rotation = false" << endl;
	}

	system("pause");
}