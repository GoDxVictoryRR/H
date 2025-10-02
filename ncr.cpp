const int MOD = 1e9+7, MAXN = 1e6;
long long fact[MAXN], invfact[MAXN];

long long modpow(long long a,long long b){
    long long res=1;
    while(b){ if(b&1) res=res*a%MOD; a=a*a%MOD; b>>=1; }
    return res;
}

void precompute(){
    fact[0]=1;
    for(int i=1;i<MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXN-1]=modpow(fact[MAXN-1],MOD-2);
    for(int i=MAXN-2;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;
}

long long nCr(int n,int r){
    if(r<0||r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

long long nPr(int n,int r){
    if(r<0||r>n) return 0;
    return fact[n]*invfact[n-r]%MOD;
}
