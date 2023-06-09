// power.c -- raises numbers to integer powers
#include <stdio.h>
double power(double n, int p); // ANSI prototype
int main(void){
    double x, xpow;
    int exp;
    printf("Enter a number and the integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2){
        xpow = power(x,exp);
        // function call
        if (x == 0 && exp == 0)
            printf("0 to the power of 0 is undefinded\n");
        else
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}

double power(double n, int p){
    double pow = 1;
    int i;
    // function definition
    if (p > 0){
        for (i = 1; i <= p; i++)
            pow *= n;
    }else if (p < 0){
        for (i = -1; i >= p; i--){
            if (n != 0)
                pow *= (1/n);
            else
                pow = 0;        
        }    
    }else{
        if (n == 0)
            pow = 1;
    }
    return pow;
    // return the value of pow
}