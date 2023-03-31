#include "../hpp/Vernam.hpp"

// Function to perform Vernam Cipher encryption
std::string Vernam::CipherEncrypt(const std::string& plaintext, const std::string& key) {
    std::string ciphertext;
    int len = plaintext.length();

    for (int i = 0; i < len; i++) {
        // XOR the plaintext character with the key character
        char c = plaintext[i] ^ key[i];

        // Append the encrypted character to the ciphertext string
        ciphertext += c;
    }

    return ciphertext;
}

// Function to perform Vernam Cipher decryption
std::string Vernam::CipherDecrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    int len = ciphertext.length();

    for (int i = 0; i < len; i++) {
        // XOR the ciphertext character with the key character
        char c = ciphertext[i] ^ key[i];

        // Append the decrypted character to the plaintext string
        plaintext += c;
    }

    return plaintext;
}