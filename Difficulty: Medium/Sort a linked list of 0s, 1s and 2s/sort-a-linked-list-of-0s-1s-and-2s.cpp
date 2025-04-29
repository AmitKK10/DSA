//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

class Maintainer{
    public:
    Node * head, * tail;
    Maintainer(){
        head = tail = NULL;
    }
    void addNode(Node * node)
    {
        if(!head)
        head = tail = node;
        else
        {
            tail->next = node;
            tail = tail->next;
        }
    }
};

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        Maintainer * z = new Maintainer();
        Maintainer * o = new Maintainer();
        Maintainer * t = new Maintainer();
        Node * cur = head;
        while(cur)
        {
            if(cur->data==0)
            z->addNode(cur);
            else if(cur->data==1)
            o->addNode(cur);
            else t->addNode(cur);
            
            cur = cur->next;
        }
        
        Node * resH,*resT;
        resH = resT = NULL;
        
        if(z->head)
        {
            resH = z->head;
            resT = z->tail;
        }
        if(o->head)
        {
            if(resH)
            resT->next = o->head;
            else
            resH = o->head;
            
            resT = o->tail;
        }
        if(t->head)
        {
            if(resH)
            resT->next = t->head;
            else
            resH = t->head;
            
            resT = t->tail;
        }
        
        resT->next = NULL;
        
        return resH;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends