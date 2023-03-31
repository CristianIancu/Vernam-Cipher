#pragma once

#include <string>

class Vernam{
public:
    // Function to perform Vernam Cipher encryption
    static std::string CipherEncrypt(const std::string& plaintext, const std::string& key);

    // Function to perform Vernam Cipher decryption
    static std::string CipherDecrypt(const std::string& ciphertext, const std::string& key);
};
