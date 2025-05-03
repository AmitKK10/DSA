//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

class Solution {
  public:
    Node *primeList(Node *head) {
        // Generate all prime numbers up to a certain limit
        vector<int> prime;
        findprimes(prime);
        
        Node *temp = head;
        
        // Traverse the linked list
        while (temp != nullptr) {
            if (temp->val <= 2) {
                temp->val = 2; // Handle values less than or equal to 2
            } else {
                // Replace value with the closest prime number
                int closest_prime = find_closest_prime(prime, temp->val);
                temp->val = closest_prime;
            }
            temp = temp->next;
        }
        
        return head;
    }

  private:
    // Sieve of Eratosthenes to find all primes < 11000
    void findprimes(vector<int> &prime) {
        vector<bool> is_prime(11000, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i < 11000; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j < 11000; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        // Store all prime numbers in the vector
        for (int i = 2; i < 11000; i++) {
            if (is_prime[i]) prime.push_back(i);
        }
    }

    // Find the closest prime to a given value using binary search
    int find_closest_prime(vector<int> &prime, int val) {
        if (val <= prime[0]) return prime[0];          // If value is below the first prime
        if (val >= prime.back()) return prime.back();  // If value exceeds max precomputed prime

        auto it = lower_bound(prime.begin(), prime.end(), val);

        if (*it == val) return val; // Exact match

        int next_larger = it - prime.begin();
        int next_smaller = next_larger - 1;

        // Return the prime with the minimum absolute difference
        return (prime[next_larger] - val >= val - prime[next_smaller])
            ? prime[next_smaller]
            : prime[next_larger];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends