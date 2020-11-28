#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int kilkist(char* str)
{
    if (strlen(str) < 4)
        return 0;
    int k = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == 'c' &&
            str[i + 1] == 'c' &&
            str[i + 2] == 'c' &&
            str[i + 3] == 'c')
            k++;
    return k;
}
char* Change(char* str)
{
    if (strlen(str) < 4)
        return str;
    char* tmp = new char[101];
    char* t = tmp;

    tmp[0] = '\0';
    int i = 0;
    while (str[i+2] != 0)
    {
        if (str[i] == 'c' && str[i + 1] == 'c' && str[i + 2] == 'c' && str[i + 3] == 'c')
        {
            strcat(t, "**");
            t += 2;
            i += 4;
        }
        else
        {
            *t++ = str[i++];
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);

    return tmp;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << kilkist(str) << endl;
    char* dest = new char[75];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}