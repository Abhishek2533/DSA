int mod=1000000007;
long long solve(vector<long long>&sum,long long x,long long n){
        long long count=(x/n)%mod;
        long long res=(count*sum[(int)n])%mod;
        //remaining element
        res=(res+sum[(int)(x%n)])%mod;
        return res;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here
    vector<int>ans;
    
    vector<long long>sum(n+1);
    for(int i=1;i<=n;i++){
        sum[i]=(sum[i-1]+arr[i-1]) %mod;
    }

    for(int i=0;i<queries.size();i++){
        vector<long long>range=queries[i];
        long long l=range[0];
        long long r=range[1];
        long long  rsum=solve(sum,r,n);
        long long lsum=solve(sum,l-1,n);
        ans.push_back((int) ((rsum-lsum+mod)%mod));
    }
    return ans;
}