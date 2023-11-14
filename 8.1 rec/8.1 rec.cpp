// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ... 
// 1. Визначити число входжень в послідовність групи букв “abc”.
// 2. Замінити кожну групу букв “abc” парою зірочок “ * *”

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* s, const char* cs)
{
    int k = 0,
        pos = 0;
    char* t;
    while (t = strstr(s + pos, cs))
    {
        pos = t - s + 1;
        k++;
    }
    return k;
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i + 2] != 0)
    {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
        {
            strcat(t, "***");
            return Change(dest, str, t + 3, i + 3);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
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
    char s[101];
    cout << "Enter string:" << endl;
    cin.getline(s, 100);
    cout << "String contained " << Count(s, "abc") << " groups of 'abc'" << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, s, dest1, 0);
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    delete[] dest1; 
    return 0;
}
