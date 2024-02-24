#include <stdio.h>

int main()
{
        int a,b,c,d,n;
    
    scanf("%d",&n);


    a = (n/1000)*1000;
    b = ((n/100)%10)*100;
    c = ((n/10)%10)*10;
    d = ((n/1)%10)*1;

    if (a == 1000) 
    {
        printf("M");
    }

    if (b == 100)
    {
        printf("C");
    } 
      
    else if (b == 200)
    {
        printf("CC");
    }
    else if (b == 300)
    {
        printf("CCC");
    }
    else if (b == 400)
    {
        printf("CD");
    }
    else if (b == 500)
    {
        printf("D");
    }
    else if (b == 600) 
    {
        printf("DC");
    }
    else if (b == 700)
    {
        printf("DCC");
    }
    else if (b == 800)
    {
        printf("DCCC");
    }
    else if (b == 900) 
    {
        printf("CM");
    }

    if (c == 10)
    {
        printf("X");
    }
    else if (c == 20)  
    {
        printf("XX");
    }
    else if (c == 30)  
    {
        printf("XXX");
    }
    else if (c == 40)  
    {
        printf("XL");
    }
    else if (c == 50)  
    {
        printf("L");
    }
    else if (c == 60)  
    {
        printf("LX");
    }
    else if (c == 70)  
    {
        printf("LXX");
    }
    else if (c == 80)
    {  
        printf("LXXX");
    }
    else if (c == 90)
    {  
        printf("XC");
    }

    if (d == 1) 
    {
        printf("I");
    }
    else if (d == 2) 
    {
        printf("II");
    }
    else if (d == 3) 
    {
        printf("III");
    }
    else if (d == 4) 
    {
        printf("IV");
    }
    else if (d == 5) 
    {
        printf("V");
    }
    else if (d == 6) 
    {
        printf("VI");
    }
    else if (d == 7) 
    {
        printf("VII");
    }
    else if (d == 8) 
    {
        printf("VIII");
    }
    else if (d == 9) 
    {
        printf("IX");
    }

    return 0;
}