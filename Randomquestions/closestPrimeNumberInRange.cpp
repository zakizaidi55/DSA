class Solution {
public:
    vector<bool> sieveHelper(int right) {
        vector<bool> isPrime(right+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i*i <= right; i++) {
            if(isPrime[i] == true) {
                int j = i*i;
                while(j < right+1) {
                    isPrime[j] = false;
                    j += i;
                }
            }
        }

        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveHelper(right);

        vector<int> primes;
        for(int num = left; num <= right; num++) {
            if(isPrime[num] == true) {
                primes.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];

            if(diff < minDiff) {
                minDiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }

        return result;
    }
};

