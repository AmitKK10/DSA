int missingNumber(int* arr, int n) {

    int i,xor1=0,xor2=0;
for(i=0;i<n;i++)
{
xor1=xor1^arr[i]; // xor operation on given array

xor2=xor2^(i);// xor operation from index index (0+1) to (5-1); 

}

xor2=xor2^n;//Xor operation with last remaining index

return (xor1^xor2);
    
}