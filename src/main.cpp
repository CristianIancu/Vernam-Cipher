#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hpp/Vernam.hpp"

using namespace std;

bool checkingInput(int argc){
    if (argc != 4) {
        cout << "Usage: vernam <encrypt/decrypt> <inputFile> <outputFile>" << endl;
        return false;
    }
    return true;
}
int main(int argc, char *argv[]) {

    if (!checkingInput(argc)) return 1;

    string mode = argv[1];
    string inputFile = argv[2];
    string outputFile = argv[3];
    string keyFile = "key";

    vector<char> buffer;
    string inputText, outputText, key;

    // Read the input file
    ifstream inputStream(inputFile);
    if (inputStream) {
        inputStream.seekg(0, ios::end);
        int length = inputStream.tellg();
        inputStream.seekg(0, ios::beg);

        buffer.resize(length);
        inputStream.read(&buffer[0], length);

        inputText = string(buffer.begin(), buffer.end());
    } else {
        cout << "Error: input file not found." << endl;
        return 1;
    }

    // Read the key file
    ifstream keyStream(keyFile);
    if (keyStream) {
        keyStream.seekg(0, ios::end);
        int length = keyStream.tellg();
        keyStream.seekg(0, ios::beg);

        buffer.resize(length);
        keyStream.read(&buffer[0], length);

        key = string(buffer.begin(), buffer.end());
    } else {
        cout << "Error: key file not found." << endl;
        return 1;
    }

    // Perform encryption or decryption, depending on mode
    if (mode == "encrypt") {
        outputText = Vernam::CipherEncrypt(inputText, key);
    } else if (mode == "decrypt") {
        outputText = Vernam::CipherDecrypt(inputText, key);
    } else {
        cout << "Invalid mode specified. Mode must be either \"encrypt\" or \"decrypt\"." << endl;
        return 1;
    }

    // Write output to file
    ofstream outputStream(outputFile);
    if (outputStream) {
        outputStream << outputText;
        cout << "Output written to " << outputFile << endl;
    } else {
        cout << "Error: could not write output to file." << endl;
        return 1;
    }

    return 0;
}