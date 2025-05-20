//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

class Solution {
  public:
    // Helper to map parents and find target node
    void mapParents(Node* root, unordered_map<Node*, Node*>& parent, Node*& targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target) {
                targetNode = curr;
            }

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    // BFS to simulate burning
    int bfsToBurn(Node* targetNode, unordered_map<Node*, Node*>& parent) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; ++i) {
                Node* curr = q.front();
                q.pop();

                // Check left
                if (curr->left && !visited[curr->left]) {
                    flag = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                // Check right
                if (curr->right && !visited[curr->right]) {
                    flag = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                // Check parent
                if (parent[curr] && !visited[parent[curr]]) {
                    flag = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            if (flag) time++;
        }

        return time;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = nullptr;

        // Step 1: Map parents and find the target node
        mapParents(root, parent, targetNode, target);

        // Step 2: BFS to simulate fire and calculate time
        return bfsToBurn(targetNode, parent);
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends