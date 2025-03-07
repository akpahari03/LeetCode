class Solution {
public:
    vector<bool> sieveMethod(int right) {
        vector<bool> isPrime(right+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2;i*i<=right;i++) {
            if(isPrime[i]) {
                for(int j=2;i*j<=right;j++) {
                    isPrime[i*j] = false;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveMethod(right);
        vector<int> primeNos;
        for(int i=left;i<=right;i++) {
            if(isPrime[i]) primeNos.push_back(i);
        }
        if (primeNos.size() < 2) return {-1, -1};
        int mini = INT_MAX;
        int num1 = -1;
        int num2 = -1;
        for(int i=0;i<primeNos.size()-1;i++) {
            int temp = primeNos[i+1]-primeNos[i];
            if(temp < mini) {
                mini = temp;
                num1 = primeNos[i];
                num2 = primeNos[i+1];
            }
        }
        return {num1,num2};
    }
    
};