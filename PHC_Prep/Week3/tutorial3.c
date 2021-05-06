#include <stdio.h>
#include <math.h>

int array_printf(int a[]);
int array_max(int a[], int size);
int array_min(int a[],int size);
int array_mean_std(int a[],int size);
int array_index_max(int a[],int size);
int array_index_min(int a[],int size);

int main(){
  int a[10] = {21,6,28,36,15,1,3,10,45,55};
  array_printf(a);
  array_max(a,10);
  array_min(a,10);
  array_mean_std(a,10);
  array_index_max(a,10);
  array_index_min(a,10);
  return 0;

}

int array_printf(int a[]){
  for(int i=0;i<10;i++){
    printf("%d \n",a[i]);
  }
  return 0;
}
int array_max(int a[],int size){
  int max = a[0];
  int i;
  for(i=0;i<size;i++){
    if(a[i]>max)
      max = a[i];
  }
    printf("The highest value in the array is %d\n",max);
   return 0;
}
int array_index_max(int a[],int size){
	int max=a[0];
	int i;
	for (i=1;i<size;i++){
		if (max < a[i])
			max = a[i];
	}
	for (int i = 0; i<10; i++){
    if (max == a[i]){
      printf("The index of the highest value in the array is %d\n",i);
    }
  }
return 0;
}
int array_index_min(int a[],int size){
	int min=a[0];
	int i;
	for (i=1;i<size;i++){
		if (min > a[i])
			min = a[i];
	}
	for (int i = 0; i<10; i++){
    if (min == a[i]){
      printf("The index of the lowest value in the array is %d\n",i);
    }
  }
return 0;
}
int array_min(int a[],int size){
  int min = a[0];
  int i;
  for(i=0;i<size;i++){
    if(a[i]<min)
      min = a[i];
  }
    printf("The lowest value in the array is %d\n",min);
   return 0;
}
int array_mean_std(int a[],int size){
  int i;
  float mean;
  int sum;
  for(i=0;i<size;i++){
    sum += a[i];
  }
  mean = sum/10;
  printf("The mean of the array is %0.1f\n",mean);

  float SD = 0;
  for(i=0;i<size;i++){
    SD += pow(a[i]-mean,2);
  }
  SD = sqrt(SD/size);
  printf("The standard deviation of the array is %0.01f\n",SD);
  return 0;
}
