#include <stdio.h>
#include <stdlib.h>

int main(){
//Initially defining the size of our dynamic array=1
int *arr = malloc(1 * sizeof(int));
int counter=2;

while(1){
    printf("Enter element %d: ", counter);
    //reallocating array size after user enters a value
    arr = realloc(arr, counter * sizeof(int)); 
    counter++;

    scanf("%d", &arr[counter]);

    if(getchar()=='q')

     break;
}


printf("Array: [");

for(int a=0;a<counter-1;a++){
    printf("%d, ", arr[a]);
}   printf("%d]", arr[counter]);

printf("\nArray length: %d\n", counter);

return 0;
}