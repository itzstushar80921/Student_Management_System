 #include<stdio.h>
 int main()
 {
    double r,vol,h,ar;
     scanf("%d", &r);
     ar=3.14*r*r;
     printf("area of circle: %2f\n",ar);
      scanf("%d", &h);
      vol=3.14*r*h;
      printf("volume of cylinder: %2f\n",vol);
 }