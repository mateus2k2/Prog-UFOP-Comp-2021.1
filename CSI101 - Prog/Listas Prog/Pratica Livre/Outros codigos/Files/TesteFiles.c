# include <stdio.h>
# include <string.h>

int main(){
    int year;
    char str1[10], str2[10], str3[10];

    FILE * filePointer; 

    filePointer = fopen("fileName.txt", "r");

    fscanf(filePointer, "%s %s %s %d", str1, str2, str3, &year);

    printf("%s %s %s %d", str1, str2, str3, year);

}