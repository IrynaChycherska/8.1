#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int kilkist(char* str, int i)
{
    if (strlen(str) < 4)
        return 0;
    if (strlen(str) < 4)
        if ((str[i] == 'c' &&
            str[i + 1] == 'c' &&
            str[i + 2] == 'c' &&
            str[i + 3] == 'c'))
            return 1 + kilkist(str, i + 1);
        else
            return kilkist(str, i + 1);
    else
        return 0;
}
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i + 2] != 0)
    {
        if (str[i] == 'c' && str[i + 1] == 'c' && str[i + 2] == 'c' && str[i + 3] == 'c')
        {
            strcat(t, "**");
            return Change(dest, str, t + 2, i + 4);
        }
        else
        {
            *t++ = str[i++];

            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << kilkist(str, 1) << endl;
    char* dest1 = new char[75];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    return 0;

}
