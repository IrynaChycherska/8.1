#include <iostream>
#include <string>
using namespace std;
int kilkist(const string str)
{
	int k = 0;
	size_t pos = 0;
	while ((pos = str.find("cccc", pos, 4)) < str.size())
	{
		k++;
		pos += 5;
	}
	return k;
}
string Change(string& s)
{
	size_t pos = 0;
	while ((pos = s.find('c', pos)) != -1)
		if (s[pos + 1] == 'c', s[pos + 2] == 'c', s[pos + 3] == 'c')
			s.replace(pos, 4, "**");
	return s;
}
int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);
	cout << "String contained " << kilkist(str) << endl;
	string dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}