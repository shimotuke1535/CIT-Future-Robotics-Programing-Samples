//関数電卓//
//ヘッダー読み込み//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<float.h>
//円周率定義//
#define PI 3.1415
//関数定義//
double input(char B[100]);
int sta(void);
//input関数//
double input(char B[100])
{
    //変数定義//
    int i,c;
    double a,b,tmp;
    char dust,n[100];
    while (1)
    {
        //概要表示//
        if(stricmp(B,"about")==0)
        {
            printf("--------------------------------------------\n概要\n四則演算とよく使うだろう計算、各種関数、\nそれに加え統計を扱えるようにした関数電卓\n制作者 shimotuke1535(simonomao1535@gmail.com)\n--------------------------------------------\n数値/式を入力=>");
            scanf("%s",B);
            scanf("%c",&dust);
        }
        //ヘルプメッセージ表示//
        else if(stricmp(B,"HELP")==0)
        {
            printf("------------------\n関数入力ヘルプ\ns=>正弦関数(sin)\nc=>余弦関数(cos)\nt=>正接関数(tan)\n$=>二乗根(√)\nl=>対数関数(log)    \np=>円周率\n!=>階乗\n^=>累乗\nr=>乱数\n------------------\n演算子入力ヘルプ\n+=>加法\n-=>減法\n*=>乗法\n/=>除法\n%%=>余剰計算\nf=>統計モード    \nc=>クリア\nq=>終了\n------------------\n入力方法ヘルプ\n初回入力/初期化後入力の仕方\n(関数宣言)(数値)の順で入力してください\n通常時   入力の仕方\n(演算子)(関数宣言)(数値)の順で入力してください\n------------------\n入力例:sin60+40?\n初期値を入力=>s60\n式を入力=>    +^40\nInput index => 2\n------------------\n数値/式を入力=>");
            scanf("%s",B);
            scanf("%c",&dust);
        }
        else
        {
            break;
        }
    }
    //文字列の先頭を読み込む//
    strncpy(n,B+1,99);
    //文字列＝＞数字データ変換//
    a = atof(n);
    //関数判定//
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
        //例外処理//
        if(a==90)
        {
            printf("infERROR!\n");
            while(a==90)
            {
                printf("再入力(tは入力しなくてよい)\n");
                scanf("%.3lf",&a);
                printf("a=>%.3lf");
                if(a == 90)
                {
                    printf("infERROR!\n");
                }
            }
        }
        //演算//
        a = tan(a*(PI/180));
        break;

        //二乗根//
        case'$':
        a = sqrt(a);
        break;

        //対数//
        case'l':
        a = log(a);
        break;

        //円周率//
        case'p':
        a = PI;
        break;

        //階乗//
        case '!':
        tmp = 1;
 		for(i = 2;i <= a;i++)
 		{
			tmp *= i;
        }
        if(tmp >= DBL_MAX)
        {
            printf("DBL_MAX Hight!!!\n");
            printf("エラー回避のため0とします。\n");
            tmp = 0;
        }
        a = tmp;
        break;

        //累乗//
        case '^':
        printf("指数を入力してください=>");
        scanf("%s",B);
        scanf("%c",&dust);
        b = input(B);
        a = pow(a,b);
        break;

        //乱数//
        case 'r':
        printf("生成する乱数の最大値を入力=>");
        scanf("%d",&i);
        scanf("%c",&dust);
        a = ((double)rand() / ((double)RAND_MAX + 1)) * i;
        break;

        //標準//
        default:
        a = atof(B);
        break;
    }

    return a;
}

//統計モード関数//
int sta(void)
{
    int tmp,ave,min,max,med,x[1000];
    int i,e,b,k,check;
    char dust,sw;
    while (1)
    {
        //要素数の入力//
        while(1)
        {
            printf("要素数を入力=>");
            scanf("%d",&e);
            //例外処理//
            if(e<=0||e>=1000)
            {
                printf("ERROR!!\n再度入力してください\n");
            }
            else
            {
                break;
            }
        }
        
        printf("数値を入力(整数で入力してください)\n");
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
        printf("要素数=>%d\n最大値=>%d\n最低値=>%d\n平均値=>%d\n中央値=>%d\n",e,max,min,ave,med);
        check = 1;
        while(1)
        {
            printf("繰り返し使用しますか？Y/N=>");
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw != 'N' || sw != 'Y')
            {
                printf("不正な入力\n再入力してください\n");
            }
            if(sw == 'N'||sw == 'n')
            {
                printf("電卓モードに移行します\n");
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

//本文//
int main(void)
{
    //変数定義//
    char A[100],B[100],sw,dust;
    double a,b,ans;
    int i,c;
    //初期化//
    a = 0;
    b = 0;
    c = 0;
    i = 1;
    ans = 0;
    system("cls");
    //初期入力//
    printf("関数電卓\n");
    printf("概要ページ=>'ABOUT'を入力\n");
    printf("入力ヘルプ=>'HELP'を入力\n");
    printf("------------------\n入力例:sin60+40?\n初期値を入力=>s60\n式を入力=>+^40\nInput index => 2\n------------------\n");
    printf("初期値を入力(入力方法はHELP参照)=>");
    scanf("%s",A);
    scanf("%c",&dust);
    a = input(A);
    //ループ開始//
    while(1)
    {
        //ループ内入力//
        printf("式を入力=>");
        sw = getchar();
        //swの記号で分岐//
        switch(sw)
        {
            //和//
            case '+':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a+b;
            printf("%d=>",i);
            printf("(%.3lf)+(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;

            //差//
            case '-':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a-b;
            printf("%d=>",i);
            printf("(%.3lf)-(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //積//
            case '*':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans=a*b;
            printf("%d=>",i);
            printf("(%.3lf)×(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //商//
            case '/':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            if(b==0||strcmp(B,"s0")==1||strcmp(B,"c90")==1)
            {
                printf("infERROR!\n再度入力してください=>");
                scanf("%s",B);
                scanf("%c",&dust);
                b = input(B);
            }
            ans=a/b;
            printf("%d=>",i);
            printf("(%.3lf)÷(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;
            
            //余剰計算//
            case '%':
            scanf("%s",B);
            scanf("%c",&dust);
            b = input(B);
            ans = fmod(a,b);
            printf("%d=>",i);
            printf("(%.3lf)%%(%.3lf)=%.3lf\n",a,b,ans);
            a = ans;
            break;

            //統計モード//
            case 'f':
            printf("統計モードに移行します\n");
            sta();
            printf("電卓を終了しますか？Y/N=>");
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw == 'Y'||sw == 'y')
            {
                printf("お疲れ様でした\n");
                c = 2;
                break;
            }
            //初期化//
            ans = 0;
            a = 0;
            b = 0;
            //初期再入力//
            printf("数字を入力=>");
            scanf("%s",A);
            scanf("%c",&dust);
            a = input(A);
            break;
            
            //クリア処理//
            case 'c':
            //初期化//
            ans = 0;
            a = 0;
            b = 0;
            i = 0;
            system("cls");
            //初期再入力//
            printf("Clear!!\n");
            printf("数字を入力=>");
            scanf("%s",A);
            scanf("%c",&dust);
            a = input(A);
            break;

            //終了処理//
            case 'q':
            c = 1;
            break;

            //例外処理//
            default:
            printf("ERROR!!!\n");
            i--;
            break;
        }
        //終了処理//
        if(c == 1)
        {
            printf("電卓を終了しますか？Y/N=>");
            scanf("%c",&dust);
            scanf("%c" , &sw);
            scanf("%c",&dust);
            if(sw == 'Y'||sw == 'y')
            {
                printf("お疲れ様でした\n");
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
    //最終値の表示//
    if(c == 1)
    {
        printf("Finish=>%.3lf\n",ans);
    }
    return 0;
}