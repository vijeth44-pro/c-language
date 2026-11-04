// #include <stdio.h>

// int main()
// {
//     int a=10;
//     int b=30;
//     printf("Address:%u\n",&a);
//     printf("Address:%u",&b);
// }

#include<stdio.h>
void main()
{
  int a,*page;
  a=50;
  page=&a;
printf("address of a=%u\n",page);
printf("value of a=%d",*page);
}