
class disjoint {

    vector<int> parent;
public:
    disjoint(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    void Union(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a < b) {
            parent[b] = a;
        } else if (b < a) {
            parent[a] = b;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans="";
        disjoint d(26);
        for(int i=0;i<s1.length();i++){
            d.Union(s1[i]-'a',s2[i]-'a');
        }
        for(char &ch: baseStr){
          ans+= ('a' + d.findParent(ch-'a'));
        }
        return ans;
    }
};