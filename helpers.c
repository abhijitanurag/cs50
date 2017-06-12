/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n<=0){
        return false;
    }
   
   
   
     int start,end,mid;
    start=0;
    end=n-1;
    mid=(start+end)/2;
    
    while(start<=end){
        if(values[mid]==value){
        
            return true;
        }
        else if(values[mid]<value){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
        mid=(start+end)/2;
     
    }
    
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int count[65536];
    int max;
    max=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(values[i]>max){
            max=values[i];
        }
    }
    for(int i=0;i<=max;i++){
        count[i]=0;
        }
    for(int i=0;i<n;i++){
        count[values[i]]++;
    }
    for(int i=0;i<=max;i++){
        while(count[i]!=0){
            values[j]=i;
            count[i]--;
            j++;
        }
    }
    

  return;
}
