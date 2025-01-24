vector<int>lp(N,0),hp(N,0);
vector<bool> sieve(int N) {
    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; ++i)    // i<N
        if (isPrime[i])
            lp[i]=hp[i]= i;
            for (int j = i * i; j < N; j += i) // j = 2*i
                isPrime[j] = false;
                hp[j]=i;
                if(lp[j]==0)
                    lp[j]=i;
    return isPrime;
}
// Time complexity is N*loglogn
int main(){
int N = 1e6; // Change N as per the problem's limit
    vector<bool> isPrime = sieve(N);
 int q;
    cin>>q; 
    while(q--){
        int n;
        cin>>n;
        if(isPrime[n]){
            cout<<"prime\n";
        }
        else{
            cout<<"notPrime\n";
        }
    }
}
