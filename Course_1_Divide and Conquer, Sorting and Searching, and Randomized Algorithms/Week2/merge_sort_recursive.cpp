/* @author:::DPS @dated::2.7.15*/
/*merge sort algorithm with recursive call only one temporary array  */

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int arr[MAX],temp[MAX];
int inversion=0;

void Merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void Copy(int arr[],int temp[],int low,int up);
void Merge_Sort(int arr[],int low , int up)
{
            int mid;
            int temp[MAX];
            if(low<up)
            {
                mid=(low+up)/2;
                Merge_Sort(arr,low,mid);
                Merge_Sort(arr,mid+1,up);

                //now merge the array
                Merge(arr,temp,low,mid,mid+1,up);

                Copy(arr,temp,low,up); //copy temp[low:up] to arr[low:up]


            }


}


void Merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
        int i=low1;
        int j=low2;
        int k=low1;
        while((i<=up1) && (j<=up2))
        {
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];

            }
            else{
                temp[k++]=arr[j++];
               // cout<<1<<endl;
               inversion++;

            }

        }
        while(i<=up1)
        {
            temp[k++]=arr[i++];
              //cout<<2<<endl;
        }
        while(j<=up2)
        {
            temp[k++]=arr[j++];
            //cout<<3<<endl;


        }



}
void Copy(int arr[],int temp[],int low,int up)
{
    for(int i=low;i<=up;i++)
        arr[i]=temp[i];

}

int main()
{
        int n,i;
        cin>>n;
        for(i=0;i<n;i++)
                cin>>arr[i];

        Merge_Sort(arr,0,n-1);

        //sorted element
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";

        cout<<"No of Inversion ="<<inversion<<endl;

    return 0;
}
