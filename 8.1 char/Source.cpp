#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int kilkist(char* str)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(str + pos, 'cccc'))
	{
		pos = t - str + 4;
			k++;
	}
	return k;
}
char* Change(char* str)
{
	char* t = new char[strlen(str)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(str + pos1, 'c'))
	{
		if (str[p-str+1]=='c', str[p - str + 2] == 'c', str[p-str+3]=='c')
		{
			pos2 = p - str + 4;
			strncat(t, str + pos1, pos2 - pos1 - 4);
			strcat(t, "**");
			pos1 = pos2;
		}
	}
	strcat(t, str + pos1);
	strcpy(str, t);
	return t;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << kilkist(str) << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
