#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//Array
void swap(int *a, int * b){
  int temp = *a;
  *a = * b;
  *b = temp;
}
void arr1(){
  int n; 
  scanf("%d",&n);
  int arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr[i]);
  
  for( int i = n-1 ; i >=0;i--)  printf("%d ",arr[i]);

}
void arr2(){
  int n; 
  scanf("%d",&n);
  int arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr[i]);
  int sum = 0;
  for( int i = 0 ; i < n;i++)  sum+=arr[i];

  printf("%d ",sum);

}
void arr3(){
  int n; 
  scanf("%d",&n);
  int arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr[i]);
  int sum = 0;
  for( int i = 1 ; i < n;i+=2)  sum+=arr[i];

  printf("%d ",sum);

}
void arr4(){
  int n; 
  scanf("%d",&n);
  float arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%f",&arr[i]);
  float sum = 0;
  for( int i = 0 ; i < n;i++)  sum+=arr[i];
  
  printf("%.2f ",sum/n);

}
void arr5(){
  int n; 
  scanf("%d",&n);
  int arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr[i]);
  int sum = 0;
  for( int i = 0 ; i < n;i+=2)  sum+=arr[i];
  
  printf("%d ",sum);

}
void arr6(){
  int n; 
  scanf("%d",&n);
  int arr[n],arr2[n],arr3[n];
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr[i]);
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr2[i]);
  for( int i = 0 ; i < n;i++)  arr3[i]= arr[i] + arr2[i];
 
  for( int i = 0 ; i < n;i++)  printf("%d ",arr3[i]);


}
void arr7(){
  int n; 
  scanf("%d",&n);
  int arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr[i]);
  int l = 0, r = n-1;
  while(l<r){
    swap(&arr[l], &arr[r]);
    l++;
    r--;
  }
  for( int i = 0 ; i < n;i++)  printf("%d ",arr[i]);


}
void arr8(){
  int n; 
  scanf("%d",&n);
  int arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%d",&arr[i]);
  int min = 1000000,minInd = -1, max = -1000000, maxind = -1;;
  for( int i = 0 ; i < n;i++)  {
   if(arr[i]<min){
    min= arr[i];
    minInd = i;
   };

   if(arr[i]> max) {
    max = arr[i];
    maxind = i;
  };
  }
  printf("Max: %d, Index: %d\nMin: %d, Index: %d",max,maxind,min,minInd);


}
void arr9(){
  int n; 
  scanf("%d",&n);
  char arr[n];
  for( int i = 0 ; i < n;i++)  scanf("%c",&arr[i]);
  int vowels = 0;

  for( int i = 0 ; i < n;i++){
    if(arr[i]=='A' ||arr[i]=='E' ||arr[i]=='I' ||arr[i]=='O' ||arr[i]=='U' ||arr[i]=='a' ||arr[i]=='e' ||arr[i]=='i' ||arr[i]=='o' ||arr[i]=='u'){
      vowels++;
    }
  }

  printf("Count: %d",vowels);
}
void arr10() {
  int n, target;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  scanf("%d", &target);
  
  int found = 0;  

  for (int i = 0; i < n; i++) {
      if (arr[i] == target) {
          if (!found) {
              printf("FOUND at index position: ");
              found = 1; 
          }
          printf("%d ", i);  
      }
  }

  if (!found)  printf("NOT FOUND");


}

// Loop problem
void l1()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    printf("%d ", i);
}
void l2()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i += 2)
    printf("%d ", i);
}
void l3()
{
  int n;
  scanf("%d", &n);
  int x = 1;
  for (int i = 1; i <= n; i++)
  {
    int val = (i % 2 == 0) ? 0 : 1;
    printf("%d,", val);
  }
}
void l4()
{
  int n;
  scanf("%d", &n);
  float sum = 0;
  for (int i = 1; i <= n; i++)
  {
    float x;
    scanf("%f", &x);
    sum += x;
  }
  printf("AVG of %d inputs:  %f", n, sum / n);
}
void l5()
{
  int x, y;
  scanf("%d %d", &x, &y);

  while (x != y)
  {
    printf("%d, ", x * x);
    x += (x < y) ? 1 : -1;
  }

  if (x == y)
  {
    printf("Reached!\n");
  }
}
void l6()
{
  int n, has;
  scanf("%d %d", &n, &has);
  int flag = 1;
  while (has != 0)
  {

    int x;
    scanf("%d", &x);
    if (x == n && has != 0)
    {
      printf("Right, Player-2 wins!\n");
      flag = 0;
      break;
    }
    else
    {
      has--;
      printf("Wrong, %d Choice(s) Left!\n", has);
    }
  }
  if (flag == 1 && has == 0)
  {
    printf("Player-1 wins!\n");
  }
}
void l7() {
  char x;
  int n = 0;
  while (1) {
      scanf(" %c", &x);  // space before %c handles Enter/newline

      if (x == 'A') break;
      
      n++;
      printf("Input %d: %c\n", n, x);
  }
}
void l8(){
  int n;
  scanf("%d",&n);

  while(n!=0){
    printf("%d",n%10);
    n/=10;
  }
}
void l9(){

}
void l10(){
  int n;
  scanf("%d",&n);
  int sum = 0;
  for(int i = 1 ; i <=n;i++){
    if(i%2==0) sum += (i*-1);
    else sum+=i;
  }
  printf("Result: %d \n",sum);
}
void l11(){
  int n;
  scanf("%d",&n);
  int sum = 0;
  for(int i = 1 ; i <=n;i++){
    sum += (i*i) * ( i+1);
  }
  printf("Result: %d \n",sum);
}
void l12(){
  int n ;
  scanf("%d",&n);
  int prev1 = 1,prev2 = 1,cur = 0;
  printf("%d,%d,",prev1,prev2);

  for(int i = 2 ; i < n;i++){
   cur= prev1 + prev2;
   prev2 = prev1;
   prev1 = cur;
   printf("%d,",cur);

  }
}
void l13(){
  int n;
  scanf("%d",&n);
  int sum = 1;
  for(int i = 1 ; i <=n;i++){
    sum*=i;
  }
  printf("Result: %d \n",sum);
}

long long helperL14(int n){
  long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;

}
void l14(){
  int n ,r;
  scanf("%d %d",&n,&r);
  int uper = helperL14(n);
  int down = helperL14(r) * (helperL14(n-r));
  int nCr = uper/down;
  printf("%d",nCr);
}



//String



//Aysah Mam
// #include <stdio.h>
// #include <stdbool.h>  
// //1
// bool isPrime(int n) {

//     if (n <= 1) return false; 

//     for (int i = 2; i < n; i++) {
//         if (n % i == 0)  return false; 
//     }
    
//     return true; 
// }

// //2
// int binaryToDecimal(long long binary) {
//   int decimal = 0, i = 0;
//   while (binary != 0) {
//       int digit = binary % 10;
//       decimal += digit * pow(2, i);
//       binary /= 10;
//       i++;
//   }
//   return decimal;
// }
// //2
// int decimalToBinary(int decimal) {
//   int binary = 0;
//   int remainder, i = 1;

//   while (decimal != 0) {
//       remainder = decimal % 2;
//       decimal /= 2;
//       binary += remainder * i;
//       i *= 10;
//   }

//   return binary;
// }
// //3
// int findLargest(int arr[], int size) {
//   int max = arr[0];
//   for (int i = 1; i < size; i++) {
//       if (arr[i] > max)  max = arr[i];
//   }
//   return max;
// }
// //4
// void findMinMax(int arr[], int size, int result[]) {
//   int min = arr[0], max = arr[0];

//   for (int i = 1; i < size; i++) {
//       if (arr[i] < min) min = arr[i];
//       if (arr[i] > max) max = arr[i];
//   }

//   result[0] = min;
//   result[1] = max;
// }
int main()
{
  int num;
    
  scanf("%d", &num);
  if (isPrime(num))  printf("%d is a prime number.\n", num);
  else  printf("%d is not a prime number.\n", num);
  


  return 0;
}
