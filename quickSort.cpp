#include<iostream>
using namespace std;
int  partition(int arr[],int s,int e)
{
   
   int pivot=arr[s];
    int count=0;
   for(int i=s+1;i<=e;i++)
   {
    if(pivot>=arr[i])
    {
        count++;
    }
   }

   //place pivot item to right position
   int pivotIndex=s+count;

   swap(arr[pivotIndex], arr[s]);

   int leftIndex=s;
   int rightIndex=e;

   while(leftIndex<pivotIndex&&pivotIndex<rightIndex)
   {
    while(arr[leftIndex]<=arr[pivotIndex])
    {
        leftIndex++;
    }

     while(arr[rightIndex]>arr[pivotIndex])
    {
        rightIndex--;
    }

    if(leftIndex<pivotIndex&&pivotIndex<rightIndex)
    {
     swap(arr[leftIndex++],arr[rightIndex--]);   
    }
   }

   return pivotIndex;
}
void quickSort(int arr[],int s,int e)
{
    //base case
    if(s>=e){
       return; 
    }


    int pivot= partition(arr,s,e);

    //left side array 

    quickSort(arr,s,pivot-1);

    //right side array
    quickSort(arr,pivot+1,e);

}
int main()
{
    int arr[]={2,4,1,6,9 ,9,9,9,9,9};
    int size=sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,size-1);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    

  return 0;
}