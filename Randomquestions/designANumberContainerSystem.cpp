class NumberContainers {
    public:
        unordered_map<int, int>indexToNum; // stores index->number
        unordered_map<int, set<int> >numToIndex; //stores uss index ke liye kitne elements hai
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            //1. if this number is already present, toh uss index se number delete karo
            //jab number delete kar diya toh ab numToIndex map se bhi uski entry erase karni hogi
            //kyuki wo nunber uss index se hatt gya hai
    
            if(indexToNum.count(index)) {
                int prevNum = indexToNum[index];
    
                //ab m iska index remove kar dunga set se
                numToIndex[prevNum].erase(index);
    
                if(numToIndex[prevNum].empty()) {
                    numToIndex.erase(prevNum);
                }
            }
    
            //create entry
            indexToNum[index] = number;
            numToIndex[number].insert(index);
        }
        
        int find(int number) {
            if(numToIndex.count(number)) {
                return *numToIndex[number].begin();
            }
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */