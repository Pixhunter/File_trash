#include <stdio.h>

int main(int argc, char **argv) {
    int chars=0, strings=1;
    int c;
    FILE *fp;
    
    fp=(argc==1)?stdin:fopen(argv[1],"r");
    while ((c=fgetc(fp))!=EOF)
        (c=='\n')?strings++:chars++;
    (argc!=1)?fclose(fp):0;
    printf("%d strings\n%d chars\n", strings, chars);
    return 0;
}
