/**
- Perceptron Neural Network.
- Realization of 'AND' or 'OR' logical operator.
- Author: Priyanka Kasture
- Mail: pkasture2010@gmail.com
*/


#include<stdio.h>
#include<conio.h>

int main()
{
    int input[4][2], tar[4];
    float w[2], wc[2], out=0;
    int i, j, k=0, h=0;
    float s=0, b=0, bc=0;
    float alpha=0.0125; //Learning Rate
    float theta = 0.5; //Activation Threshold

    printf("\n ************** Perceptron Neural Network ************** \n");
    /*printf("\n Enter the values of theta and alpha: ");
    scanf("%f %f", &theta, &alpha);*/

    printf("\n Enter the input and target values: \n");
    for(i=0; i<4; i++)
    {
        printf(" Row %d: ",i+1);
        for(j=0; j<=1; j++)
        {
            scanf("%d", &input[i][j]);
        }
        scanf("%d", &tar[i]);
        w[i]=0;
        wc[i]=0;
    }

    printf("\n NN-Output \t Target \t Weight Changes \t New Weights \t Bias Changes \t Bias \n");
    printf("\n ---------------------------------------------------------------------- \n");

    mew:
        printf("\n Iteration: %d \n",h);
        for(i=0; i<4; i++)
        {
            for(j=0; j<2; j++)
            {
                s = s+(float)input[i][j]*w[j];
            }
            s = s+b;
            printf("\n %.2f \t",s);
            if(s>theta)
                out = 1;
            else if(s<-theta)
                out = -1;
            else
                out = 0;
            printf(" %d \t",tar[i]);
            s = 0;
            if(out == tar[i])
            {
                for(j=0; j<2; j++)
                {
                    wc[j]=0;
                    bc=0;
                    printf(" %.2f \t",wc[j]);
                }
                for(j=0; j<2; j++)
                    printf(" %.2f \t",w[j]);
                k = k+1;
                b = b+bc;
                printf(" %.2f \t",bc);
                printf(" %.2f \t",b);
            }
            else
            {
                for(j=0; j<2; j++)
                {
                    wc[j] = input[i][j]*tar[i]*alpha;
                    w[j] = w[j]+wc[j];
                    printf(" %.2f \t",wc[j]);
                    wc[j]=0;
                }
                for(j=0; j<2; j++)
                    printf(" %.2f \t",w[j]);
                    bc = tar[i]*alpha;
                    b = b+bc;
                    printf(" %.2f \t",bc);
                    printf(" %.2f \t",b);
            }
            printf("\n");
        }
        if(k==4)
        {
            printf("\n Final Weights: \n");
            for(j=0; j<2; j++)
            {
                printf("\n w[%d] = %.2f \t ",j,w[j]);
            }
            printf("\n Bias b = %.2f",b);
        }
        else
        {
            k = 0;
            h = h+1;
            goto mew;
        }
    return 0;
}
