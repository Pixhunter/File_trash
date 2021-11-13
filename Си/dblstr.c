#include <stdio.h>
#include <stdlib.h>
#define SIZE 16

int main(int argc, char *argv[]){  /* duplicate every string of a given file*/
    FILE *fp1;
    FILE *fp2;
    int n;
    int i;
    int temp;
    int c;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[1], "r+");
    
    if((c=getc(fp1))==EOF)  /* empty file */
        return 0;
    
    fseek(fp2, 0, SEEK_END);
    n = ftell(fp2);
    
    fseek(fp2, 2*n-1, SEEK_SET);

    fseek(fp1,n-1,SEEK_SET);
    i=n-1;
    c=getc(fp1);
    
    if (c=='\n') {
          putc(c,fp2);
          fseek (fp1, -2, SEEK_CUR);
          i--;
          fseek (fp2, -2, SEEK_CUR);
    }
    
    while( i>=0 ){
        temp = i; / * position of the last symbol in the current string */
        for(;(c =getc(fp1)) !='\n' && i>=0; i--){
            putc(c,fp2);               /* step forward */
            fseek (fp2, -2, SEEK_CUR); /* two steps back */
            
            fseek (fp1, -2, SEEK_CUR);
        }
        putc('\n',fp2);                /* string duplication */
        fseek (fp2, -2, SEEK_CUR);
        fseek (fp1, temp, SEEK_SET);
        i = temp;
        for(;(c = getc(fp1)) !='\n' && i>=0; i--){
            putc(c,fp2);
            fseek (fp2, -2, SEEK_CUR);
            fseek (fp1, -2, SEEK_CUR);
        }                              /* end of duplication */
        
        if (c =='\n'){                /* next string prepairing */
            putc(c, fp2);
            fseek (fp2, -2, SEEK_CUR);
            fseek(fp1, -2, SEEK_CUR);
            i--;
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}



