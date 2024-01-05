//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
int findNodeCount(Node* root) {
    int count = 0;
    Node*curr = root;
    
    while(curr) {
        if(curr->left == NULL) {
            count++;
            curr = curr->right;
        }
        
        else {
            Node* pred = curr->left;
            while(pred->right && pred->right != curr)  {
                pred = pred->right;
            }
            if(pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            
            else {
                pred->right = NULL;
                count ++;
                curr = curr->right;
            }
        }
    }
    return count;
    
}

float findActualMedian(Node* root, int& n) {
    int i = 0; 
    int odd1 = (n+1)/2;
    int oddVal = -1;
    int even1 = n/2;
    int even1Val = -1;
    int even2 = n/2 + 1;
    int even2Val = -1;
    
    Node* curr = root;
    
    while(curr) {
        if(curr->left == NULL) {
            i++;
            
            if(i == odd1) {
                oddVal = curr->data;
            }
            
            if(i == even1) {
                even1Val = curr->data;
            }
            
            if(i == even2) {
                even2Val = curr->data;
            }
            curr = curr->right;
        }
        
        else {
            Node* pred = curr->left;
            while(pred->right && pred->right != curr)  {
                pred = pred->right;
            }
            if(pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            
            else {
                pred->right = NULL;
                i++;
                if(i == odd1) {
                    oddVal = curr->data;
                }
            
                if(i == even1) {
                    even1Val = curr->data;
                }
                
                if(i == even2) {
                    even2Val = curr->data;
                }
                
                curr = curr->right;
            }
        }
    }
    float median = 0;
    if((n&1) == 0) {
        median = (even1Val + even2Val)/2.0;
    }
    
    else{
        median = oddVal;
    }
    
    return median;
    
}
float findMedian(struct Node *root)
{
    // morris traversal
    
    int n = findNodeCount(root);
    return findActualMedian(root,n);
    
}

