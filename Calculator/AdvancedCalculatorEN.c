//Scientific calculator //
//read headers//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <float.h>
// Pi definition //
#define PI 3.1415
//Function definition//
double input(char B[100]);
int sta(void);
//input function//
double input(char B[100])
{
    //Variable definition//
    int i,c;
    double a,b,tmp;
    char dust,n[100];
    while (1)
    {
        //Overview view//
        if(stricmp(B,"about")==0)
        {
            printf("------------------------------------------------\nOverview \n A scientific calculator that can handle the four arithmetic operations and frequently used calculations, various functions, and in addition to statistics\n Creator shimotuke1535(simonomao1535@gmail.com)\n---------- ----------------------------------\nEnter a number/expression=>");
            scanf("%s",B);
            scanf("%c",&dust);
        }
        // display help message //
        else if(stricmp(B,"HELP")==0)
        {
            printf("------------------\nfunction input help\ns=>sine function (sin)\nc=>cosine function (cos)\nt=>tangent function (tan)\n$=>square root (ã)\nl=>logarithmic function (log) \np=>pi\n!=>factorial\n^=>power\nr=>random number\n- -----------------\noperator input help\n+=>addition\n-=>subtraction\n*=>multiplication\n/=>division\n%% =>Remainder calculation\nf=>statistics mode\nc=>clear\nq=>end\n-------------------\ninput method help\nfirst time input/ How to input after initialization\nPlease input in order of (function declaration) (number)\nHow to input in normal mode\nPlease input in order of (operator) (function declaration) (number)\ n------------------\nInput example: sin60+40?\nInput initial value=>s60\nInput formula=> +^40\nInput index => 2\n------------------\nEnter a number/formula=>");
            scanf("%s",B);
            scanf("%c",&dust);
        }
        else
        {
            break;
        }
    }
    // read the beginning of the string //
    strncpy(n,B+1,99);
    // character string => numeric data conversion //
    a = atof(n);
    //function judgment//
    switch(B[0])
    {
        //sin//
        case's':
        a = sin(a*(PI/180));
        break;

        //cos//
        case 'c':
        a = cos(a*(PI/180));
        break;

        //tan//
        case't':
        //exception handling//
        if(a==90)
        {
            printf("infERROR!\n");
            while(a==90)
            {
                printf("Re-enter (you don't have to enter t)\n");
                scanf("%.3lf",&a);
                printf("a=>%.3lf");
                if(a == 90)
                {
                    printf("infERROR!\n");
                }
            }
        }
        //Calculation//
        a = tan(a*(PI/180));
        break;

        //square root//
        case '$':
        a = sqrt(a);
        break;

        //logarithm//
        case 'l':
        a = log(a);
        break;

        //Pi//
        case 'p':
        a = PI;
        break;

        //factorial//
        case '!':
        tmp = 1;
 for(i = 2;i <= a;i++)
 {
tmp *= i;
        }
        if(tmp >= DBL_MAX)
        {
            printf("DBL_MAX Hight!!!\n");
            printf("Set to 0 to avoid errors.\n");
            tmp = 0;
        }
        a = tmp;
        break;

        //exponentiation//
        case '^':
        printf("Please enter exponent =>");
        scanf("%s",B);
        scanf("%c",&dust);
        b = input(B);
        a = pow(a,b);
        break;

        //random number//
        case 'r':
        printf("Enter the maximum value of random numbers to generate =>");
        scanf("%d",&i);
        scanf("%c",&dust);
        a = ((double)rand() / ((double)RAND_MAX + 1)) * i;
        break;

        //standard//
        default:
        a = atof(B);
        break;
    }

    return a;
}
//statistics mode functions//
int sta(void)
{
    int tmp,ave,min,max,med,x[1000];
    int i,e,b,k,check;
    char dust, sw;
    while (1)
    {
        //input number of elements//
        while(1)
        {
            printf("Enter the number of elements =>");
            scanf("%d",&e);
            //exception handling//
            if(e<=0||e>=1000)
            {
                printf("ERROR!!\nPlease try again\n");
            }
            else
            {
                break;
            }
        }
        
        printf("Enter a number (enter an integer)\n");
        for(i=0;i<=e-1;i++)
        {
            printf("[%d]=>",i+1);
            scanf("%d",&x[i]);
            scanf("%c",&dust);
            ave += x[i];
        }
        i = 0;
        b = 0;
        k = 0;
        while(1)
        {
            if(x[i] > x[i + 1])
            {
                tmp = x[i];
                x[i] = x[i + 1];
                x[i + 1] = tmp;
                b += 1;
            }
            if(b==0)
            {
                k++;
                if(k>=e*2)
                {
                    break;
                }
            }
            i += 1;
            if(i >= e-1)
            {
                i = 0;
                b = 0;
            }
        }
        printf("sort!!\n");
        for(i=0;i<=e-1;i++)
        {
            printf("[%d]=>%d\n",i+1,x[i]);
        }
        max = x[e-1];
        min = x[0];
        ave /= e;
        if(e%2==0)
        {
            med = (x[(e-1)/2]+x[(e-1)/2+1])/2;
        }
        else
        {
            med = x[(e-1)/2];
        }
        printf("number of elements=>%d\nmax=>%d\nminimum=>%d\naverage=>%d\nmedian=>%d\n",e,max,min ,ave,med);
        check = 1;
        while(1)
        {
            printf("Use it repeatedly? Y/N=>");
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw != 'N' || sw != 'Y')
            {
                printf("Invalid input\nPlease retype\n");
            }
            if(sw == 'N'||sw == 'n')
            {
                printf("Switch to calculator mode\n");
                check = 0;
                break;
            }
        }
        if (check == 0)
        {
            break;
        }
    }
    return 0;
}

//Main//
int main(void)
{
    //Variable definition//
    char A[100],B[100],sw,dust;
    double a,b,ans;
    int i,c;
    //Initialization//
    a = 0;
    b = 0;
    c = 0;
    i = 1;
    ans = 0;
    system("cls");
    //initial input//
    printf("Scientific calculator\n");
    printf("About Page => Enter 'ABOUT'\n");
    printf("Input help => type 'HELP'\n");
    printf("------------------\nInput example: sin60+40?\nInput initial value=>s60\nInput formula=>+^40\ nInput index => 2\n------------------\n");
    printf("Enter the initial value (see HELP for how to enter) =>");
    scanf("%s",A);
    scanf("%c",&dust);
    a = input(A);
    //start loop//
    while(1)
    {
        //input in loop//
        printf("Enter expression =>");
        sw = getchar();
        //Branch with sw symbol//
        switch(sw)
        {
            //sum//
            case '+':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a+b;
            printf("%d=>",i);
            printf("(%.3lf)+(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;

            //difference//
            case '-':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a-b;
            printf("%d=>",i);
            printf("(%.3lf)-(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //product//
            case '*':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a*b;
            printf("%d=>",i);
            printf("(%.3lf)~(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //quotient//
            case '/':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            if(b==0||strcmp(B,"s0")==1||strcmp(B,"c90")==1)
            {
                printf("infERROR!\nPlease try again=>");
                scanf("%s",B);
                scanf("%c",&dust);
                b = input(B);
            }
            ans=a/b;
            printf("%d=>",i);
            printf("(%.3lf)€(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //remainder calculation//
            case '%':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans = fmod(a,b);
            printf("%d=>", i);
            printf("(%.3lf)%%(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;

            //statistics mode//
            case 'f':
            printf("Moving to statistics mode\n");
            sta();
            printf("Exit calculator? Y/N=>");
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw == 'Y'||sw == 'y')
            {
                printf("Thank you for your hard work\n");
                c = 2;
                break;
            }
            //Initialization//
            ans = 0;
            a = 0;
            b = 0;
            //initial re-entry//
            printf("Enter a number =>");
            scanf("%s",A);
            scanf("%c",&dust);
            a = input(A);
            break;
            //clear processing//
            case 'c':
            //Initialization//
            ans = 0;
            a = 0;
            b = 0;
            i = 0;
            system("cls");
            //initial re-entry//
            printf("Clear!!\n");
            printf("Enter a number =>");
            scanf("%s",A);
            scanf("%c",&dust);
            a = input(A);
            break;

            //End processing//
            case 'q':
            c = 1;
            break;

            //exception handling//
            default:
            printf("ERROR!!!\n");
            i--;
            break;
        }
        //End processing//
        if(c == 1)
        {
            printf("Exit calculator? Y/N=>");
            scanf("%c",&dust);
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw == 'Y'||sw == 'y')
            {
                printf("Thank you for your hard work\n");
                break;
            }
            else
            {
                c = 0;
            }
        }
        if(c == 2)
        {
            break;
        }
        i++;
    }
    //display final value//
    if(c == 1)
    {
        printf("Finish=>%.3lf\n",ans);
    }
    return 0;
}