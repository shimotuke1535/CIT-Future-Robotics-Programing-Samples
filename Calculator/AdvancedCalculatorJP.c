//�֐��d��//
//�w�b�_�[�ǂݍ���//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<float.h>
//�~������`//
#define PI 3.1415
//�֐���`//
double input(char B[100]);
int sta(void);
//input�֐�//
double input(char B[100])
{
    //�ϐ���`//
    int i,c;
    double a,b,tmp;
    char dust,n[100];
    while (1)
    {
        //�T�v�\��//
        if(stricmp(B,"about")==0)
        {
            printf("--------------------------------------------\n�T�v\n�l�����Z�Ƃ悭�g�����낤�v�Z�A�e��֐��A\n����ɉ������v��������悤�ɂ����֐��d��\n����� shimotuke1535(simonomao1535@gmail.com)\n--------------------------------------------\n���l/�������=>");
            scanf("%s",B);
            scanf("%c",&dust);
        }
        //�w���v���b�Z�[�W�\��//
        else if(stricmp(B,"HELP")==0)
        {
            printf("------------------\n�֐����̓w���v\ns=>�����֐�(sin)\nc=>�]���֐�(cos)\nt=>���ڊ֐�(tan)\n$=>��捪(��)\nl=>�ΐ��֐�(log)    \np=>�~����\n!=>�K��\n^=>�ݏ�\nr=>����\n------------------\n���Z�q���̓w���v\n+=>���@\n-=>���@\n*=>��@\n/=>���@\n%%=>�]��v�Z\nf=>���v���[�h    \nc=>�N���A\nq=>�I��\n------------------\n���͕��@�w���v\n�������/����������͂̎d��\n(�֐��錾)(���l)�̏��œ��͂��Ă�������\n�ʏ펞   ���͂̎d��\n(���Z�q)(�֐��錾)(���l)�̏��œ��͂��Ă�������\n------------------\n���͗�:sin60+40?\n�����l�����=>s60\n�������=>    +^40\nInput index => 2\n------------------\n���l/�������=>");
            scanf("%s",B);
            scanf("%c",&dust);
        }
        else
        {
            break;
        }
    }
    //������̐擪��ǂݍ���//
    strncpy(n,B+1,99);
    //�����񁁁������f�[�^�ϊ�//
    a = atof(n);
    //�֐�����//
    switch(B[0])
    {
        //sin//
        case's':
        a = sin(a*(PI/180));
        break;

        //cos//
        case'c':
        a = cos(a*(PI/180));
        break;

        //tan//
        case't':
        //��O����//
        if(a==90)
        {
            printf("infERROR!\n");
            while(a==90)
            {
                printf("�ē���(t�͓��͂��Ȃ��Ă悢)\n");
                scanf("%.3lf",&a);
                printf("a=>%.3lf");
                if(a == 90)
                {
                    printf("infERROR!\n");
                }
            }
        }
        //���Z//
        a = tan(a*(PI/180));
        break;

        //��捪//
        case'$':
        a = sqrt(a);
        break;

        //�ΐ�//
        case'l':
        a = log(a);
        break;

        //�~����//
        case'p':
        a = PI;
        break;

        //�K��//
        case '!':
        tmp = 1;
 		for(i = 2;i <= a;i++)
 		{
			tmp *= i;
        }
        if(tmp >= DBL_MAX)
        {
            printf("DBL_MAX Hight!!!\n");
            printf("�G���[����̂���0�Ƃ��܂��B\n");
            tmp = 0;
        }
        a = tmp;
        break;

        //�ݏ�//
        case '^':
        printf("�w������͂��Ă�������=>");
        scanf("%s",B);
        scanf("%c",&dust);
        b = input(B);
        a = pow(a,b);
        break;

        //����//
        case 'r':
        printf("�������闐���̍ő�l�����=>");
        scanf("%d",&i);
        scanf("%c",&dust);
        a = ((double)rand() / ((double)RAND_MAX + 1)) * i;
        break;

        //�W��//
        default:
        a = atof(B);
        break;
    }

    return a;
}

//���v���[�h�֐�//
int sta(void)
{
    int tmp,ave,min,max,med,x[1000];
    int i,e,b,k,check;
    char dust,sw;
    while (1)
    {
        //�v�f���̓���//
        while(1)
        {
            printf("�v�f�������=>");
            scanf("%d",&e);
            //��O����//
            if(e<=0||e>=1000)
            {
                printf("ERROR!!\n�ēx���͂��Ă�������\n");
            }
            else
            {
                break;
            }
        }
        
        printf("���l�����(�����œ��͂��Ă�������)\n");
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
        printf("�v�f��=>%d\n�ő�l=>%d\n�Œ�l=>%d\n���ϒl=>%d\n�����l=>%d\n",e,max,min,ave,med);
        check = 1;
        while(1)
        {
            printf("�J��Ԃ��g�p���܂����HY/N=>");
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw != 'N' || sw != 'Y')
            {
                printf("�s���ȓ���\n�ē��͂��Ă�������\n");
            }
            if(sw == 'N'||sw == 'n')
            {
                printf("�d�샂�[�h�Ɉڍs���܂�\n");
                check = 0;
                break;
            }
        }
        if(check == 0)
        {
            break;
        }
    }
    return 0;
}

//�{��//
int main(void)
{
    //�ϐ���`//
    char A[100],B[100],sw,dust;
    double a,b,ans;
    int i,c;
    //������//
    a = 0;
    b = 0;
    c = 0;
    i = 1;
    ans = 0;
    system("cls");
    //��������//
    printf("�֐��d��\n");
    printf("�T�v�y�[�W=>'ABOUT'�����\n");
    printf("���̓w���v=>'HELP'�����\n");
    printf("------------------\n���͗�:sin60+40?\n�����l�����=>s60\n�������=>+^40\nInput index => 2\n------------------\n");
    printf("�����l�����(���͕��@��HELP�Q��)=>");
    scanf("%s",A);
    scanf("%c",&dust);
    a = input(A);
    //���[�v�J�n//
    while(1)
    {
        //���[�v������//
        printf("�������=>");
        sw = getchar();
        //sw�̋L���ŕ���//
        switch(sw)
        {
            //�a//
            case '+':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a+b;
            printf("%d=>",i);
            printf("(%.3lf)+(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;

            //��//
            case '-':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a-b;
            printf("%d=>",i);
            printf("(%.3lf)-(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //��//
            case '*':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a*b;
            printf("%d=>",i);
            printf("(%.3lf)�~(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //��//
            case '/':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            if(b==0||strcmp(B,"s0")==1||strcmp(B,"c90")==1)
            {
                printf("infERROR!\n�ēx���͂��Ă�������=>");
                scanf("%s",B);
                scanf("%c",&dust);
                b = input(B);
            }
            ans=a/b;
            printf("%d=>",i);
            printf("(%.3lf)��(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //�]��v�Z//
            case '%':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans = fmod(a,b);
            printf("%d=>",i);
            printf("(%.3lf)%%(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;

            //���v���[�h//
            case 'f':
            printf("���v���[�h�Ɉڍs���܂�\n");
            sta();
            printf("�d����I�����܂����HY/N=>");
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw == 'Y'||sw == 'y')
            {
                printf("�����l�ł���\n");
                c = 2;
                break;
            }
            //������//
            ans = 0;
            a = 0;
            b = 0;
            //�����ē���//
            printf("���������=>");
            scanf("%s",A);
            scanf("%c",&dust);
            a = input(A);
            break;
            
            //�N���A����//
            case 'c':
            //������//
            ans = 0;
            a = 0;
            b = 0;
            i = 0;
            system("cls");
            //�����ē���//
            printf("Clear!!\n");
            printf("���������=>");
            scanf("%s",A);
            scanf("%c",&dust);
            a = input(A);
            break;

            //�I������//
            case 'q':
            c = 1;
            break;

            //��O����//
            default:
            printf("ERROR!!!\n");
            i--;
            break;
        }
        //�I������//
        if(c == 1)
        {
            printf("�d����I�����܂����HY/N=>");
            scanf("%c",&dust);
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw == 'Y'||sw == 'y')
            {
                printf("�����l�ł���\n");
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
    //�ŏI�l�̕\��//
    if(c == 1)
    {
        printf("Finish=>%.3lf\n",ans);
    }
    return 0;
}