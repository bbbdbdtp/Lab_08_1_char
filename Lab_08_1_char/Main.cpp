#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str)
{
    if (strlen(str) < 5)
        return 0;

    int k = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == 'B' || str[i] == 'A' || str[i] == 'S' || str[i] == 'I' || str[i] == 'C')
            k++;
    return k;
}

char* Change(char* s) {
    char* t = new char[strlen(s) * 6 / 5 + 1];
    char* p;
    int pos1 = 0, pos2 = 0;
    *t = 0;
    while (p = strchr(s + pos1, 'B')) {
        if (*(p + 1) == 'A' && *(p + 2) == 'S' && *(p + 3) == 'I' && *(p + 4) == 'C') {
            pos2 = p - s + 5;
            strncat(t, s + pos1, pos2 - pos1 - 5);
            strcat(t, "Delphi");
            pos1 = pos2;
        }
        else {
            pos2 = p - s + 1;
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " characters included in the word \"BASIC\"" << endl;
    char* dest = new char[121];
    dest = Change(str);
    cout << "Modified string: " << dest << endl;
    return 0;
}
