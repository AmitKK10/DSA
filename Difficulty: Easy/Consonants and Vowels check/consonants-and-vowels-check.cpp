void checkString(string s) {
    int v = 0;
    int c = 0;

    // Your code here
    for(char chi : s)
    {
        char ch = tolower(chi);
        if(ch == ' ') continue;
        if(ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u' )
        {
            v++;
        }
        else c++;
    }

    if (v > c)
        cout << "Yes";
    else if (c > v)
        cout << "No";
    else
        cout << "Same";

    cout << endl;
}