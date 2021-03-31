#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int temp;


void Cocktail(int a[], int n)
{
    int is_swapped = 1;
    int begin = 0,i;
    int end = n - 1;

    while (is_swapped) {
        is_swapped = 0;
     for (i = begin; i < end; ++i) {
            if (a[i] > a[i + 1]) {
            temp = a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
        is_swapped = 1;
            }
        }
 if (!is_swapped)
            break;
 is_swapped = 0;
 for (i = end - 1; i >= begin; --i) {
     if (a[i] > a[i + 1])
    {
          temp = a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
      is_swapped = 1;
         }
      }
        ++begin;
    }
}

int main()
{
     clock_t start, end;
     double cpu_time_used;


    printf("enter the size of array\n");
    int i,N;
    scanf("%d",&N);
    start = clock();
     int arr[N];

     int numberArray[N];

    FILE* myFile;
	myFile = fopen("data.txt", "r");


	if (myFile == NULL) {
		printf("Error Reading File\n");
		exit(0);
	}

	for (i = 0; i < N; i++) {
		fscanf(myFile, "%d,", &numberArray[i]);
	}

	for (i = 0; i < 16; i++) {
		//printf("Number is: %d\n\n", numberArray[i]);
	}

	fclose(myFile);

     printf(" elements generation completed!!! \n\n");
     for(i=0;i<N;i++)
     {

         //scanf("%d",&arr[i]);,
          arr[i]=numberArray[i];
     }

    int n = sizeof(arr) / sizeof(arr[0]);
    Cocktail(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time taken for sorting is %f ",cpu_time_used);
    printf("printing sorted array :\n");
    //for (i = 0; i < N; i++)
     //  printf(" %d ,", arr[i]);
    printf("\n");
    return 0;
}
