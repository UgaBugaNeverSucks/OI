#include <stdio.h>

int main(){
    FILE *text=fopen("data.txt", "w");
    FILE *bin=fopen("data.bint", "w");
    if (!text||!bin)
        return 0;
    int num[]={1000,2000,3000};
    for (int i=0; i<3; i++) fprintf(text, "%d", num[i]);
    fwrite(num, sizeof(int), 3, bin);
    fclose(text);
    fclose(bin);
    text=fopen("data.txt", "r");
    if(!text)
        return 0;
    for(int i=0; i<12; i++){
        char c=fgetc(text);
        printf("%d\n", c);
    }
    fclose(text);
}

