//
//  main.cpp
//  CaesarCipher
//
//  Created by Carolina Romo on 7/25/17.
//  Copyright © 2017 CaroRomo. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Caesar Cipher function
// Param    : string str
// Returns  : string text
string caesarCipher(string str){
    
    // Variables
    long shiftNumber = 0;
    string text = "";
    bool found = false;         // Boolean to mark if : was found
    
    for (long i = 0; i < str.length(); i++){ // O(n) Time Complexity
        // Validate if char is a valid number (positive or negative) or :
        if ((isnumber(str[i]) || str[i] == ':' || str[i] == '-' ) && !found) {
            // Validate if char is : and not on the first position
            if (str[i] == ':' && i != 0){
                shiftNumber = stoi(str.substr(0,i)); // Get number with atoi function
                text = str.substr(i+1,str.length() - i);
                found = true;
                
                // Number range validation
                if ((shiftNumber < -1000000000) || (shiftNumber > 1000000000)){
                    return "Input Error";
                }
                
                // Empty text validation
                if (text == "") {
                    return "Input Error";
                }
                
                // String wrong length validation
                if (text.length() > 200) {
                    return "Input Error";
                }
                
                // Check for 0 shifts
                if (shiftNumber == 0) {
                    return text;
                }
            }
        }
    }
    
    // If : wasn't found
    if (!found) {
        return "Input Error";
    }
    
    for (long i = 0; i < text.length(); i++){
        
        // Check if char is number
        if (isnumber(text[i])){
            // Depending on the shift number
            // If the char arrives to the end
            // We change it to the beginning
            if (text[i] == '9' && shiftNumber > 0){
                text[i] = text[i] - 10;
            }
            
            if (text[i] == '0' && shiftNumber < 0){
                text[i] = text[i] + 10;
            }
            
            text[i] = text[i] + (shiftNumber % 10);
        }
        
        // Check if char is letter
        else if (isalpha(text[i])) {
            bool isLower = false;
            
            if (islower(text[i])) {
                isLower = true;
            }
            
            if ((text[i] == 'z' || text[i] == 'Z') && shiftNumber > 0){
                text[i] = text[i] - 26;
            }
            
            if ((text[i] == 'a' || text[i] == 'A') && shiftNumber < 0){
                text[i] = text[i] + 26;
            }
            
            text[i] = text[i] + (shiftNumber % 26);
            
            // If the new char is bigger than Z or z
            // We add or substract update the value of the char
            if (text[i] > 'z' && isLower && shiftNumber > 0){
                text[i] = text[i] - 26;
            }
            
            if (text[i] > 'Z' && !isLower && shiftNumber > 0){
                text[i] = text[i] - 26;
            }

            if (text[i] < 'a' && isLower && shiftNumber < 0){
                text[i] = text[i] + 26;
            }
            
            if (text[i] < 'A' && !isLower && shiftNumber < 0){
                text[i] = text[i] + 26;
            }
            
        }
        // Any other char stays the same
        else {
            text[i] = text[i];
        }
    }
    
    return text;
}

int main(){
    cout << "TEST CASES" << endl;
    
    cout << "1) No number found" << endl;
    cout << caesarCipher(":23A") << ", " << caesarCipher(":Sfds!") << endl;
    
    cout << "2) Empty string " << endl;
    cout << caesarCipher("9:") << ", " << caesarCipher("1748343:") << endl;
    
    cout << "3) 0 shifts	" << endl;
    cout << caesarCipher("0:fh34e") << ", " << caesarCipher("0:dhefAd") << endl;
    
    cout << "4) No found :" << endl;
    cout << caesarCipher("r743fdhu3") << ", " << caesarCipher("4ehui!43") << endl;
    
    cout << "5) Wrong number" << endl;
    cout << caesarCipher("7.232:dfdf,") << ", " << caesarCipher("1111111111:f") << endl;
    
    cout << "6) Negative shift (left)" << endl;
    cout << caesarCipher("-92323:a!36 Abc") << ", " << caesarCipher("-89212121:ySaewS aw121") << endl;
    
    cout << "6) Positive shift (right)" << endl;
    cout << caesarCipher("232:ABCAbcZaz") << ", " << caesarCipher("123232322:dEH43@") << endl;

    return 0;
}



