#include <iostream>

using namespace std;

void merge(int  arr [], int l, int mid, int r,int arrIndex []){
    int n1= mid-l+1;
    int n2=r-mid;
    int a[n1];
    int a_index[n1];
    int b[n2];
    int b_index[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
        a_index[i]=arrIndex[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
        b_index[i]=arrIndex[mid+1+i];
    }

    //now merge process
    int i=0,j=0,k=l;

    while(i<n1&&j<n2){
        if(a[i]>=b[j]){
            arr[k]=a[i];
            arrIndex[k]=a_index[i];
            k++;
            i++;
        }else{
            arr[k]=b[j];
            arrIndex[k]=b_index[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        arrIndex[k]=a_index[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=b[j];
        arrIndex[k]=b_index[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[],int l,int r,int arrIndex[]){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid,arrIndex);
        mergeSort(arr,mid+1,r,arrIndex);
        merge(arr,l,mid,r,arrIndex);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
        int arrOfIndex[n];
        
        for(int i=0;i<n;i++){
            arrOfIndex[i]=i;
            int temp,r;
            cin>>temp;

            if(temp>=k){
                
                r=temp%k;
                if(r==0){
                    cout<<i+1<< " ";
                }
            arr[i]=r;
            }else{
            arr[i]=temp;
            }
        }
        mergeSort(arr,0,n-1,arrOfIndex);
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                break;
            }
            cout<< arrOfIndex[i]+1<<" ";
        }
        cout<<endl;
    }
}