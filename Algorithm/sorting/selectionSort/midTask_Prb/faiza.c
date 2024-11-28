#include <stdio.h>
void swap (int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;

}
void selection_sort(int A1[], int n, int A2[], int m)
{

    int k=0;
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A1[j] == A2[i])
            {
                swap(&A1[j],&A1[k]);
                k++;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d ",A1[i]);


    int temp = k;

    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A1[j] != A2[i])
            {
                swap(&A1[j],&A1[k]);
                k++;
                /*A1[k] = A1[j];
                k++;*/
            }
        }
    }
    for (int i=temp;i<n-1;i++)
    {
        int idx;
        int min_idx = i;
        for (int j=i+1;j<n;j++)
        {
            if(A1[j]<A1[i])
            {
                min_idx = j;
            }
        }
        
        idx = A1[i];
        A1[i] = A1[min_idx];
        A1[min_idx] = temp;
    }

    for (int i=0; i<n;i++)
    {
        printf("%d ",A1[i]);
    }
}

int main(){
    int a1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int a2[] = {2, 1, 8, 3};
    int n1=sizeof(a1)/sizeof(a1[0]);
    int n2=sizeof(a2)/sizeof(a2[0]);
    selection_sort(a1, n1, a2, n2);

    for(int i=0;i<n1;i++) printf("%d ",a1[i]);
}