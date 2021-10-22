#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>


std::string encrypt_data (std::string plain_text, std::string key )
{
    std::stringstream encrypted_stream;
    unsigned int text_len = plain_text.length();
    unsigned int key_len = key.length();
    unsigned int char_index = 0;
    unsigned int shift_LEN = 0;


    for (unsigned int i = 0; i < text_len; ++i )
    {
        // If current key char is uppercase, keyReferenceValue would be 'A', otherwise 'a'
        // We use keyReferenceValue to convert key char to ascii
        //
        char keyReferenceValue = (isupper(key[char_index % key_len])) ? 'A' : 'a';


        // Similarly, we use referenceValue to convert plain text to char ascii, it would
        //
        char referenceValue = (isupper(plain_text[i])) ? 'A' : 'a';
        shift_LEN = key[char_index % key_len] - keyReferenceValue;
        encrypted_stream << char(((plain_text[i] - referenceValue + shift_LEN) % 26) + referenceValue);
        ++char_index;
    }
    else
    {
        // for non alpha chars, we don't encrypt and keep them as it is.
        encrypted_stream << plain_text[i];
    }
    return encrypted_stream.str();    
}


std::string decrypt_data(std::string encrypt_text, std::string key)
{
    std::stringstream decrypted_stream;
    unsigned int text_len = encrypt_text.length();
    unsigned int key_len = key.length();
    unsigned int char_index = 0;
    unsigned int shift_len = 0;


    for (unsigned int i = 0; i < text_len; ++i)
    {
        if (isalpha(encrypt_text[i])) 
        {
            // If current key char is uppercase, keyReferenceValue would be 'A', otherwise 'a'
            // We use keyReferenceValue to convert key char to ascii
            //
            char keyReferenceValue = (isupper(key[char_index % key_len])) ? 'A' : 'a';


            // Similarly, we use referenceValue to convert plain text char to ascii, it would
            //
            char referenceValue = (isupper(encrypt_text[i])) ? 'A' : 'a';
            shift_len = key[char_index % key_len] - keyReferenceValue;
            decrypted_stream << char ((((encrypted_text[i] - referenceValue) + (26 - shift_len)) % 26) + referenceValue);
            ++char_index;
        }
        else
        {
            // We don't encrypt non-alpha chars, so keeping them as it is.
            decrypted_stream << encrypted_text[i];
        }
    }
    return decrypted_stream.str();
}



int main()
{
    std::string plain_text, encrypted_text;
    std::string key;
    std::cout << "Enter the key for encrypting: ";
    std::cin >> key;
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore();
    std::cout << "Enter the plain text you want to encrypt:";
    std::getline(std::cin, plain_text);
    encrypted_text = encrypt_data(plain_text, key);
    std::cout << "Encrypted text: " << encrypted_text << std::endl;
    plain_text.clear();
    plain_text << "Decrytpted text: " << plain_text << std::endl;
    return 0;
}