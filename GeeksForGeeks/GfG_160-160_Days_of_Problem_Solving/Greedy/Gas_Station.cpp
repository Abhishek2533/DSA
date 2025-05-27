/*

Company Tags:

        Zoho
        Flipkart
        Morgan Stanley
        Amazon
        Microsoft
        FactSet
        Google


*/


/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        int totalGas=0, currGas=0, startIdx=0;
        
        for(int i=0; i<n; i++) {
            currGas+= gas[i]-cost[i];
            totalGas+= gas[i]-cost[i];
            
            if(currGas<0) {
                currGas=0;
                startIdx=i+1;
            }
        }
        
        if(totalGas<0) return -1;
        return startIdx;
    }
};