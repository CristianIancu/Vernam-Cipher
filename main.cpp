#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to perform Vernam Cipher encryption
string vernamCipherEncrypt(const string& plaintext, const string& key) {
    string ciphertext;
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
string vernamCipherDecrypt(const string& ciphertext, const string& key) {
    string plaintext;
    int len = ciphertext.length();

    for (int i = 0; i < len; i++) {
        // XOR the ciphertext character with the key character
        char c = ciphertext[i] ^ key[i];

        // Append the decrypted character to the plaintext string
        plaintext += c;
    }

    return plaintext;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Usage: vernamCipher <encrypt/decrypt> <input_file> <output_file>" << endl;
        return 1;
    }

    string mode = argv[1];
    string input_file = argv[2];
    string output_file = argv[3];
    string key_file = "key.txt";

    vector<char> buffer;
    string input_text, output_text, key;

    // Read the input file
    ifstream input_stream(input_file);
    if (input_stream) {
        input_stream.seekg(0, ios::end);
        int length = input_stream.tellg();
        input_stream.seekg(0, ios::beg);

        buffer.resize(length);
        input_stream.read(&buffer[0], length);

        input_text = string(buffer.begin(), buffer.end());
    } else {
        cout << "Error: input file not found." << endl;
        return 1;
    }

    // Read the key file
    ifstream key_stream(key_file);
    if (key_stream) {
        key_stream.seekg(0, ios::end);
        int length = key_stream.tellg();
        key_stream.seekg(0, ios::beg);

        buffer.resize(length);
        key_stream.read(&buffer[0], length);

        key = string(buffer.begin(), buffer.end());
    } else {
        cout << "Error: key file not found." << endl;
        return 1;
    }

    // Perform encryption or decryption, depending on mode
    if (mode == "encrypt") {
        output_text = vernamCipherEncrypt(input_text, key);
    } else if (mode == "decrypt") {
        output_text = vernamCipherDecrypt(input_text, key);
    } else {
        cout << "Invalid mode specified. Mode must be either \"encrypt\" or \"decrypt\"." << endl;
        return 1;
    }

    // Write output to file
    ofstream output_stream(output_file);
    if (output_stream) {
        output_stream << output_text;
        cout << "Output written to " << output_file << endl;
    } else {
        cout << "Error: could not write output to file." << endl;
        return 1;
    }

    return 0;
}
