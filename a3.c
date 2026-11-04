//inserting an element in the end of an array
#include <stdio.h>

int main(){
int arr[10] = {1,3,4,5,7};
int n=5;
arr[n]=6;
n++;
for(int i=0; i<n; i++){
    printf("%d\n", arr[i]);
}
return 0;
}
