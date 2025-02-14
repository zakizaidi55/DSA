class ProductOfNumbers {
    public:
        vector<int>storeNumber;
        ProductOfNumbers() {
            storeNumber.push_back(1);
        }
        
        void add(int num) { 
            if(num == 0) { 
                //it means ki ab sab pichle 0 ho jayege yha se
                storeNumber.clear();
                storeNumber.push_back(1);
            }
    
            else {
                storeNumber.push_back(storeNumber.back()*num);
            }
        }
        
        int getProduct(int k) {
            int len = storeNumber.size();
            if(len <= k)
                return 0;
            return storeNumber[len-1]/storeNumber[len-k-1];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */