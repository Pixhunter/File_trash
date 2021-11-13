#include <stdio.h>
#include <string.h>

int palindrom(char *s) {
    int res;
    unsigned long int l=(strlen(s));
    char c;
    if (l<2)
        return 1;
    if (s[0]!=s[l-1])
        return 0;
    c=s[l-1];
    s[l-1]='\0';
    res=palindrom(&s[1]);
    s[l-1]=c;
    return res;
}

main(int argc, char **argv) {
    printf ("%sалиндром\n",(palindrom(argv[1]))?"П":"Не п");
    return 0;
}
