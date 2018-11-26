

#include <stdio.h>
#include <stdlib.h>

struct times {
        int start;
        int end;
        int id;
    };

int indexes[100000];

struct times temp[100000];

void mergesort(struct times a[],int i,int j);
void merge(struct times a[],int min1,int max1,int min2,int max2);

void mergesort(struct times a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(struct times a[],int min1,int max1,int min2,int max2)
{
    int i,j,k;

    i=min1;    //beginning of the first list
    j=min2;    //beginning of the second list
    k=0;
    
    while(i<=max1 && j<=max2)    //while elements in both lists
    {
        if(a[i].end<a[j].end) {
            temp[k].start=a[i].start;
            temp[k++].end=a[i++].end;
        }
        else {
            temp[k].start=a[j].start;
            temp[k++].end=a[j++].end;
        }
    }
    
    while(i<=max1) {    //copy remaining elements of the first list
        temp[k].start=a[i].start;
        temp[k++].end=a[i++].end;
    }
        
    while(j<=max2) {   //copy remaining elements of the second list
        temp[k].start=a[j].start;
        temp[k++].end=a[j++].end;
    }
        
    //Transfer elements from temp[] back to a[]
    for(i=min1,j=0;i<=max2;i++,j++) {
        a[i].start=temp[j].start;
        a[i].end=temp[j].end;
    }
}


void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]);
} 

int getTheShit(struct times A[], int s[], int f[], int count){
    int counter = 1;
    int m;
    int k = 0;
    int n = count;
    int index = 0;
    while ( index < count && ( A[index].start != s[k] || A[index].end != f[k]) ) ++index;
    indexes[counter-1] = index + 1;
    for(m=1; m<n; m++){
        if(s[m]> f[k]){
            k=m;
            counter = counter + 1;
            int index = 0;

            while ( index < count && ( A[index].start != s[k] || A[index].end != f[k]) ) ++index;
            indexes[counter-1] = index + 1;
        }
        }
     
    return counter;
}


int main() {
    //+1 in indexeeeees
    
    int count;
    int i;
    
    /*FILE *myFile;
    myFile = fopen("C://cisla.in", "r");
    fscanf(myFile, "%d ", &count);
    
    struct times set;
    struct times data[count];
    struct times unsorted[count];
    for (i = 0; i<count; i ++){
        fscanf(myFile,"%d ", &set.start);
        fscanf(myFile,"%d ", &set.end);
        data[i] = set;
        unsorted[i] = set;
    }
    */
   scanf( "%d ", &count);
    
    
    struct times set;
    struct times data[count];
    struct times unsorted[count];
    for (i = 0; i<count; i ++){
        scanf("%d ", &set.start);
        scanf("%d ", &set.end);
        data[i] = set;
        unsorted[i] = set;
    }
    
    if(count < 1){
        printf("%d", 0);
    }
   
    
    else{
    mergesort(data, 0, count-1);
    
    
    int begin[count];
    int finish[count];
    for (i = 0; i<count; i ++){
        begin[i] = data[i].start;
        //printf("%d ", data[i].start);
        finish[i] = data[i].end;
        //printf("%d\n", data[i].end);
    }
    
    int result;
    result = getTheShit(unsorted, begin, finish, count);
    printf("%d\n", result);
    printArray(indexes, result);
    }  
}

