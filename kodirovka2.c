#include <stdio.h>

typedef struct{
    char name[20];
    int age;
} person;
int main(){
    person arr[]={{"Tomas", 25}, {"Eggman", 60}, {"Kennedy", 48}};
    FILE *f=fopen("data.bin", "w");
    if(!f) return 0;
    fwrite(arr, sizeof(person), 3,f);
    fclose(f);
f=fopen("data.bin", "r");
person arr2[3];
fread(arr2, sizeof(person), 3, f);
for(int i=0; i<3; i++)printf("%s%d\n", arr2[i].name, arr2[i].age);
fclose(f);
f=fopen("data.bin", "r");
int index;
scanf("%d", &index);
int pos=index*sizeof(person);
fseek(f, pos, SEEK_SET);
person man;
fread(&man, sizeof(person), 1, f);
for(int i=0; i<3; i++)printf("%s%d\n", man.name, man.age);
fclose(f);
}
