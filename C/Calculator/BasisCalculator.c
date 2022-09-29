#include<stdio.h>
#include<math.h>
#define PI 3.1415
double fmode(double a);

double fmode(double a)
{
    double b,ans,tmp;
    char f,sw,dust;
    int c = 0;
    printf("fmode\n");
    while(1)
    {
        scanf("%c",&dust);
        printf("sw=>"); 
        scanf("%c",&sw);
        if(sw == 'f'||sw == 'c'||sw == '\n')
        {

        }
        else
        {
            printf("s=>sin\nc=>cos\nt=>tan\n=>");
            scanf("%c",&dust);
            scanf("%c",&f);
            printf("f=>%c\n",f);
            switch(f)
            {
                case 's':
                printf("b=>");
                scanf("%lf",&b);
                tmp = b;
                b = sin(b*(PI/180));
                printf("sin[%lf]=>%lf\n",tmp,b);
                break;

                case 'c':
                printf("b=>");
                scanf("%lf",&b);
                tmp = b;
                b = cos(b*(PI/180));
                printf("cos[%lf]=>%lf\n",tmp,b);
                break;

                case 't':
                while(1)
                {
                    printf("b=>");
                    scanf("%lf",&b);
                    tmp = b;
                    if(b >= 89.99 && b <= 90.99)
                    {
                        printf("infERROR!\n");
                    }
                    else
                    {
                        break;
                    }
                }
                b = tan(b*(PI/180));
                printf("tan[%lf]=>%lf\n",tmp,b);
                break;

                default:
                break;
            }
        }
        switch(sw)
        {
            case '+':
            ans = a+b;
            printf("(%lf)+(%lf)=(%lf)\n",a,b,ans);
            break;

            case '-':
            ans = a-b;
            printf("(%lf)-(%lf)=(%lf)\n",a,b,ans);
            break;

            case '*':
            ans = a*b;
            printf("(%lf)~(%lf)=(%lf)\n",a,b,ans);
            break;

            case '/':
            ans = a/b;
            printf("(%lf)€(%lf)=(%lf)\n",a,b,ans);
            break;

            case 'c':
            a = 0;
            b = 0;
            ans = 0;
            printf("s=>sin\nc=>cos\nt=>tan\n=>");
            scanf("%c",&dust);
            scanf("%c",&f);
            printf("f=>%c\n",f);
            switch(f)
            {
                case 's':
                printf("a=>");
                scanf("%lf",&a);
                tmp = a;
                a = sin(a*(PI/180));
                printf("sin[%lf]=>%lf\n",tmp,a);
                break;

                case 'c':
                printf("a=>");
                scanf("%lf",&a);
                tmp = a;
                a = sin(a*(PI/180));
                printf("cos[%lf]=>%lf\n",tmp,a);
                break;

                case 't':
                while(1)
                {
                    printf("a=>");
                    scanf("%lf",&a);
                    tmp = a;
                    if(a >= 89.99 && a <= 90.99)
                    {
                        printf("infERROR!\n");
                    }
                    else
                    {
                        break;
                    }
                }
                a = tan(a*(PI/180));
                printf("tan[%lf]=>%lf\n",tmp,a);
                break;

                default:
                break;
            }
            break;

            case '\n':
            break;

            case 'f':
            printf("end\n");
            c = 1;
            break;

            default:
            printf("ERROR\n");
            break;
        }
        a = ans;
        if(c == 1)
        {
            break;
        }
    }
    return a;
}
int main(void)
{
    double a,b,ans;
    char sw,dust;
    int c = 0;

    printf("a=>");
    scanf("%lf",&a);
    scanf("%c",&dust);
    while(1)
    {
        printf("sw=>");
        scanf("%c",&sw);
        switch(sw)
        {
            case '+':
            printf("b=>");
            scanf("%lf",&b);
            ans = a+b;
            printf("(%lf)+(%lf)=(%lf)\n",a,b,ans);
            a = ans;
            break;

            case '-':
            printf("b=>");
            scanf("%lf",&b);
            ans = a-b;
            printf("(%lf)-(%lf)=(%lf)\n",a,b,ans);
            a = ans;
            break;

            case '*':
            printf("b=>");
            scanf("%lf",&b);
            ans = a*b;
            printf("(%lf)~(%lf)=(%lf)\n",a,b,ans);
            a = ans;
            break;

            case '/':
            printf("b=>");
            scanf("%lf",&b);
            ans = a/b;
            printf("(%lf)€(%lf)=(%lf)\n",a,b,ans);
            a = ans;
            break;

            case 'c':
            a = 0;
            b = 0;
            ans = 0;
            printf("a=>");
            scanf("%lf",&a);
            break;

            case 'f':
            ans = fmode(a);
            a = ans;
            break;

            case 'q':
            c = 1;
            break;

            case '\n':
            break;

            default:
            printf("ERROR\n");
            break;
        }
        scanf("%c",&dust);
        if(c == 1)
        {
            break;
        }
    }
    printf("finish=>%lf",ans);
    return 0;
}