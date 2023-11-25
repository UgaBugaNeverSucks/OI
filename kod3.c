#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int age;
}person;

void save(char*filename){
    int n;
    printf("n=");
    scanf("%d", &n);
    person*arr = (person*)calloc(n, sizeof(person));
    for(int i=0; i<n; i++){
        printf("name=");
        scanf("%s", arr[i].name);
        printf("age=");
        scanf("%d", &arr[i].age);
}
FILE *f=fopen(filename, "w");
if(!f){
    free(arr);
    return;
}

fwrite(arr, sizeof(person), n, f);
fclose(f); free(arr);
}

void load(char*filename){
    FILE *f=fopen(filename, "r");
    if (!f) return;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    int n=size/sizeof(person);
    printf("file size %ld\n", size);
    rewind(f);
    person *arr=(person*)malloc(size);
    fread(arr, sizeof(person),n,f);
    fclose(f);
    for(int i=0; i<n; i++)
        printf("%s %d\n", arr[i].name, arr[i].age);
    free(arr);
}

int main(){
    char filename[]="person.bin";
    int key;
    printf("1 - write, 2 - load \n");
    scanf("%d", &key);
    switch(key){

        case 1:
            save(filename);
            break;
        case 2:
            load (filename);
            break;
        default:
            break;
    }
    return 0;
}

