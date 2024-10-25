class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(folder.begin(), folder.end());

        vector<string>result;

        for(string&currFolder: folder) {
            string tempFolder = currFolder;
            bool isSubFolder = false;
            while(!currFolder.empty()) {
                auto lastSlashPosition = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0, lastSlashPosition);

                if(st.find(currFolder) != st.end()) {
                    // found
                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder) {
                result.push_back(tempFolder);
            }
        }

        return result;
    }
};