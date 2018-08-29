#include <stdio.h>
#include <memory.h>

int main() {
    // declare a 'string'
    char str[128];

    // get string from user
    gets(str);

    // length of user's string
    int x = (int) strlen(str);

    // string reverse algorithm (change chars from both ends till the middle)
    for (int i = x/2, start = 0, finish = x; i > 0; i--, start++, finish--)
    {
        char tmp = str[finish-1];
        str[finish-1] = str[start];
        str[start] = tmp;

        printf("%c -> %c\n", str[finish-1], str[start]);

    }

    // print result string
    printf("%s\n", str);

    return 0;
}