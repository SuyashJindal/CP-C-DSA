
#define min(a, b) (((a) < (b))? (a) : (b))

int RFib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return (RFib(n-1)%2025+RFib(n-2)%2025)%2025;
}

void multiply(long int mat1[2][2],long  int mat2[2][2]) {

    long int x = (mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0])%2025;
    long int y = (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1])%2025;
   long  int z = (mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0])%2025;
   long  int w = (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1])%2025;

    
    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}
void matrixPower(long int mat1[2][2], long int n) {
    if (n == 0 || n == 1) return;
   long int mat2[2][2] = {{1, 1}, {1, 0}};

    matrixPower(mat1, n / 2);

    multiply(mat1, mat1);

  
    if (n % 2 != 0) {
        multiply(mat1, mat2);
    }
}
int CleverFib(long int n){
if (n<=1 ) return n;
long int mat1[2][2] = {{1,1},{1,0}};
matrixPower(mat1,n-1);
return (mat1[0][0])%2025;
}
int TrivialGCD(int a, int b){
for (int i = min(a,b); i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
        return i;
    }
}
}
long int EuclidGCD(long int a, long int b){

    if (b == 0) return a;
    return EuclidGCD(b, a % b);

}
