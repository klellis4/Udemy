/*
 * A simple and very old method of sending secret messages is the substitution cipher.
 * Each letter of the alphabet gets replaced by another letter of the alphabet.
 * For example, every 'a' gets replaced with an 'X', etc.
 * 
 * Write a program that asks the user to enter a secret message.
 * 
 * Encrypt this message using the substitution cipher and display the encrypted message.
 * Then decrypt the encrypted message back to the original message.
 * 
 * You may use the 2 strings below for your substitution.
 * For example, to encrypt you can replace the character at position n in alphabet with the character
 * at position n in key.
 * 
 * To decrypt you can replace the character at position n in key with
 * the character at position n in alphabet.
 * 
 * Currently the cipher only substitutes letters - you could easily add digits, punctuation, whitespace
 * and so forth. Also, currently the cipher always substitutes a lowercase letter with an uppercase letter
 * and vice-versa. This could also be improved.
 */


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // given
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"}; // given
    
    string encrypted_message {};
    string decrypted_message {};
    
    string message {};
    
    cout << "Enter a secret message: ";
    getline(cin, message);
    
    cout << "\nEncrypting your message..." << endl;
    
    // Encrypt message
    for (size_t i {0}; i < message.length(); i++) {
        if (isalpha(message.at(i))) {
            size_t position = alphabet.find(message.at(i));
            char encrypted_char = key.at(position);
            encrypted_message += encrypted_char;
        }
        else {
            encrypted_message += message.at(i);
        }
    }
    
    cout << "\nYour encrypted message is: " << encrypted_message << endl;
    
    // Decrypt message
    cout << "\nDecrypting your message..." << endl;
    
    for (size_t i {0}; i < encrypted_message.length(); i++) {
        if (isalpha(encrypted_message.at(i))) {
            size_t position2 = key.find(encrypted_message.at(i));
            char decrypted_char = alphabet.at(position2);
            decrypted_message += decrypted_char;
        } else {
            decrypted_message += encrypted_message.at(i);
        }
    }
    
    cout << "\nYour decrypted message is: " << decrypted_message << endl;
    
    cout << endl;
    return 0;
}
