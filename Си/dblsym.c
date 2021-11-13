#include <stdio.h>
#include <stdlib.h>
/* программа удваивает каждый символ в файле  argv[1] */

int main(int argc, char *argv[]){
    FILE *fp1;
    FILE *fp2;
    int n;
    int i;
    int c;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[1], "r+");
    
    fseek(fp2, 0, SEEK_END);
    n = ftell(fp2);
   
    fseek(fp2, 2*n-1, SEEK_SET);
   
   
    fseek(fp1,n-1,SEEK_SET);
   
    for(i = n-1; i>=0;i-- ){
        c = getc(fp1);
        putc(c,fp2);
        fseek (fp2, -2, SEEK_CUR);
        putc(c,fp2);
        fseek (fp2, -2, SEEK_CUR);
        fseek(fp1,-2,SEEK_CUR);
    
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}



