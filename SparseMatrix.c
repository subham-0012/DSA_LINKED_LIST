//operations on sparse matrix
#include <stdio.h>
int main()
{
    int matrix1[4][4] = {{1, 0, 0, 0},{0, 2, 0, 0},{0, 0, 3, 0},{0, 0, 0, 4}};
    int matrix2[4][4] = {{0, 0, 0, 1},{0, 0, 2, 0},{0, 3, 0, 0},{4, 0, 0, 0}};
    int sparsematrix1[50][3], sparsematrix2[50][3];
    int additionmatrix[50][3];
    int multiplicationMatrix[50][3];
    int i,j,k = 1,length=1,temp,key,k1=1,count=0,realcount=0,q=1,index,lastelement;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if(matrix1[i][j]!=0)
            {
                sparsematrix1[k][0]=i;
                sparsematrix1[k][1] = j;
                sparsematrix1[k][2] = matrix1[i][j];
                k++;
            }
        }
    }
    sparsematrix1[0][0]=4;
    sparsematrix1[0][1]=4;
    sparsematrix1[0][2]=k-1;
    k=1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (matrix2[i][j] != 0)
            {
                sparsematrix2[k][0] = i;
                sparsematrix2[k][1] = j;
                sparsematrix2[k][2] = matrix2[i][j];
                k++;
            }
        }
    }
    printf("\n");
    sparsematrix2[0][0] = 4;
    sparsematrix2[0][1] = 4;
    sparsematrix2[0][2] = k - 1;
    printf("The resultant sparse matrix 1 is \n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",sparsematrix1[i][j]);
        }
        printf("\n");
    }
    printf("The resultant sparse matrix 2 is \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sparsematrix2[i][j]);
        }
        printf("\n");
    }
    printf("the addition of both matrix is \n");
    for(i=1;i<k;i++)
    {
        if (sparsematrix1[i][0] == sparsematrix2[i][0])
        {
            if (sparsematrix1[i][1] == sparsematrix2[i][1])
            {
                additionmatrix[length][0] = sparsematrix1[i][0];
                additionmatrix[length][1] = sparsematrix1[i][1];
                additionmatrix[length][2] = sparsematrix1[i][2] + sparsematrix2[j][2];
            }
            else if (sparsematrix1[i][1] < sparsematrix2[i][1])
            {
                additionmatrix[length][0] = sparsematrix1[i][0];
                additionmatrix[length][1] = sparsematrix1[i][1];
                additionmatrix[length][2] = sparsematrix1[i][2];
                length++;
                additionmatrix[length][0] = sparsematrix2[i][0];
                additionmatrix[length][1] = sparsematrix2[i][1];
                additionmatrix[length][2] = sparsematrix2[i][2];
            }
            else if (sparsematrix1[i][1] > sparsematrix2[i][1])
            {
                additionmatrix[length][0] = sparsematrix2[i][0];
                additionmatrix[length][1] = sparsematrix2[i][1];
                additionmatrix[length][2] = sparsematrix2[i][2];
                length++;
                additionmatrix[length][0] = sparsematrix1[i][0];
                additionmatrix[length][1] = sparsematrix1[i][1];
                additionmatrix[length][2] = sparsematrix1[i][2];
            }
        }
        else if (sparsematrix1[i][0] < sparsematrix2[i][0])
        {
            additionmatrix[length][0] = sparsematrix1[i][0];
            additionmatrix[length][1] = sparsematrix1[i][1];
            additionmatrix[length][2] = sparsematrix1[i][2];
            length++;
            additionmatrix[length][0] = sparsematrix2[i][0];
            additionmatrix[length][1] = sparsematrix2[i][1];
            additionmatrix[length][2] = sparsematrix2[i][2];
        }
        else if (sparsematrix1[i][0] > sparsematrix2[i][0])
        {
            additionmatrix[length][0] = sparsematrix2[j][0];
            additionmatrix[length][1] = sparsematrix2[j][1];
            additionmatrix[length][2] = sparsematrix2[j][2];
            length++;
            additionmatrix[length][0] = sparsematrix1[i][0];
            additionmatrix[length][1] = sparsematrix1[i][1];
            additionmatrix[length][2] = sparsematrix1[i][2];
        }
        length++;
    }
    additionmatrix[0][0] = 4;
    additionmatrix[0][1] = 4;
    additionmatrix[0][2] = length-1;
    printf("\nthe resultant addition matrix is \n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", additionmatrix[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < k; i++)
    {
        temp=sparsematrix2[i][0];
        sparsematrix2[i][0]=sparsematrix2[i][1];
        sparsematrix2[i][1]=temp;
    }
    for (i = 0; i <=k; i++)
    {
        for(j=1;j<k-1-i;j++)
        {
            if(sparsematrix2[j][0]>sparsematrix2[j+1][0])
            {
                temp = sparsematrix2[j][0];
                sparsematrix2[j][0] = sparsematrix2[j+1][0];
                sparsematrix2[j+1][0]=temp;
                temp = sparsematrix2[j][1];
                sparsematrix2[j][1] = sparsematrix2[j + 1][1];
                sparsematrix2[j + 1][1] = temp;
                temp = sparsematrix2[j][2];
                sparsematrix2[j][2] = sparsematrix2[j + 1][2];
                sparsematrix2[j + 1][2] = temp;
            }
        }
    }
    printf("The resultant sorted transposed sparse matrix 2 is \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sparsematrix2[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<k;i++)
    {
        for(j=1;j<k;j++)
        {
            if(sparsematrix1[i][1]==sparsematrix2[j][1])
            {
                multiplicationMatrix[q][0]=i;
                multiplicationMatrix[q][1]=j;
                multiplicationMatrix[q][2]=sparsematrix1[i][2]*sparsematrix2[j][2];
                count++;
                q++;
            }
        }
    }
    multiplicationMatrix[0][0]=sparsematrix1[0][0];
    multiplicationMatrix[0][1]=sparsematrix2[0][1];
    multiplicationMatrix[0][2]=count;
    printf("\nthe resultant multiplication matrix is \n");
    for (i = 0; i < count+1; i++)
    {
        printf("%d %d %d\n", multiplicationMatrix[i][0], multiplicationMatrix[i][1], multiplicationMatrix[i][2]);
    }


    for(i=1;i<count;i++)
    {
        for(j=i+1;j<=count;j++)
        {
            if(multiplicationMatrix[i][0]==multiplicationMatrix[j][0]&&multiplicationMatrix[i][1]==multiplicationMatrix[j][1])
            {
                multiplicationMatrix[i][2] = multiplicationMatrix[i][2]+multiplicationMatrix[j][2];
                index=j,lastelement=count;
                while(lastelement>index)
                {
                    multiplicationMatrix[index][0] = multiplicationMatrix[index + 1][0];
                    multiplicationMatrix[index][1] = multiplicationMatrix[index + 1][1];
                    multiplicationMatrix[index][2] = multiplicationMatrix[index + 1][2];
                    index++;
                }
                count--;
            }
        }
    }
    printf("\nthe resultant multiplication matrix is \n");
    for(i=0;i<=count;i++)
    {
        printf("%d %d %d\n", multiplicationMatrix[i][0], multiplicationMatrix[i][1], multiplicationMatrix[i][2]);
    }
}