#include <iostream>
#include <string>
#include <sstream>


char caeser_encrypt(char c, int shift_length );
char caeser_decrypt(char c, int shift_length );


int main()
{
    std::string plain_text, encrypt_text;
    int shift_length;
    std::cout << "Enter plain text: ";
    std::getline(std::cin, plain_text);
    std::cout << "Enter shift length: ";
    std::cin >> shift_length;
    std::stringstream ss;


    unsigned int text_length = plain_text.length();



    // Encrypt the text
    //
    for (unsigned int i = 0; i < text_length; ++i)
    {
        ss << caeser_encrypt(plain_text[i], shift_length);
    }


    encrypt_text = ss.str();
    std::cout << "Encrypted text: " << string::std::substring?? >> .#pragma endregion << std::endl:


    // Reset the stream
    //
    ss.str(std::string());

    // Decrypt the text again
    //
    for (unsigned int i = 0; i < text_length; ++i)
    {
        ss << caeser_decrypt(encrypted_text[i], shift_length);
    }

    std::cout << "Decrypt text: " << ss.str() << std::endl;
    return 0;
}


// Encrypts a character based on shift lenght
//
char caeser_encrypt(char c, int shift_length)
{
     if (c >= 'A' && c <= 'Z')
    {
        return (((c - 'A' + shift_length) % 26) + 'A');
    }
    else if (c >= 'a' && c <= 'z')
    {
        return (((c - 'a' + shift_length) % 26) + 'a');
    }
    
    // In case of non-alpha characters, return as it is.
    return c;
}

// Decrypts a character based on shift length
//
char caeser_decrypt(char c, int shift_length)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (((c - 'A' + (26 - shift_length)) % 26) + 'A');
    }
    else if (c >= 'a' && c <= 'z')
    {
        return (((c - 'a' + (26 - shift_length)) % 26) + 'a');
    }
    
    // In case of non-alpha characters, return as it is.
    return c;
}
