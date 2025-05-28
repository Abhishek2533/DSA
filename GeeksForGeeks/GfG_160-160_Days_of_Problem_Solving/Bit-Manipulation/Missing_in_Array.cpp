/*

Company Tags:

        Flipkart
        Morgan Stanley
        Accolite
        Amazon
        Microsoft
        D-E-Shaw
        Ola Cabs
        Payu
        Visa
        Intuit
        Adobe
        Cisco
        Qualcomm
        TCS


*/


class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
         int xor1=0;
        int xor2=0;
        int n=arr.size()+1;
        
        for(int i=0;i<arr.size();i++){
            xor1=xor1^arr[i];
        }
        for(int i=0;i<=n;i++){
            xor2=xor2^i;
        }
        return xor1^xor2;
    }
};