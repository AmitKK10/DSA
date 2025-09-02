
string to_upper(string str) {
    // code
    string result = "";
    for(char ch : str)
    {
       result += toupper(ch);
        
    }
    
    return result;
}