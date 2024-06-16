#pragma once

#include<cstring>
using namespace std;

class cryptographiex {
public:
    char* decrypt(char* s, int key) {
        int len = strlen(s);
        char* decrypted_text = new char[len + 1]; // +1 for the null terminator
        for (int i = 0; i < len; i++) {
            decrypted_text[i] = s[i] - key;
        }
        decrypted_text[len] = '\0'; // Null-terminate the string
        return decrypted_text;
    }

    char* encrypt(char* s, int key) {
        int len = strlen(s);
        char* encrypted_text = new char[len + 1]; // +1 for the null terminator
        for (int i = 0; i < len; i++) {
            encrypted_text[i] = s[i] + key;
        }
        encrypted_text[len] = '\0'; // Null-terminate the string
        return encrypted_text;
    }
};