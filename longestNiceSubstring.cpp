class Solution {
public:
    bool isnice(string str){
        map<int,bool>map;
        for(int i=0;i<str.length();i++){ 
            int p = str[i];//its a method to get the ascii value of any charachter
            map[p]=true;
        }

        for(int i=0;i<str.length();i++){
            int q=str[i];//its a method to get the ascii value of any charachter 
            if(isupper(str[i])){
                //if letter is uppercase then we wil check for its lowercae letter from map ascii value of any lowercase letter is 32 more then ascii value of the uppercase letter
                int z = q+32;
                if(!(map[z])){
                    // if asci valueof uppercaseletter=32 is not persent in the map we return false
                    return false;
                }
            }
            else{
                int z = q-32;
                if(!(map[z])){
                    return false;
                }
            }       
        }
        //if we check all the string and false is not return we will return true
        return true;
    }

    string longestNiceSubstring(string s) {
    string ans="";
    for(int i=0;i<s.length();i++){
        for(int j=0;j<=s.length();j++){
            string str = s.substr(i,j);  
            //cout << "printing the str " << str << endl;
            if(isnice(str))  { 
                if(str.length() > ans.length()){
                    ans = str;
                }
            }
        }
    }   
    return ans;    
    }
};