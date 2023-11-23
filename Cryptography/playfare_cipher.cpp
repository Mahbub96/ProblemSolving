#include <iostream>
#include "Cryptography.h"

int main()
{
    std::string plain_text, key;

    std::cout << "Please Enter your plain Text : ";
    std::getline(std::cin, plain_text);

    std::cout << "Please Enter Your key : ";
    std::getline(std::cin, key);

    std::string cipher_text = playfair(plain_text, key);
    std::cout << "Cipher Text : " << cipher_text << std::endl;

    std::cout << "Plain Text : " << playfair_to_plaintext(cipher_text, key) << std::endl;
    return 0;
}
