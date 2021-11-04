// This is the header file of the simplr crypto program

/**
 * this is a function that generates a secret key for One time Pad
 */
char* OTP_generate_key(int n);

/**This function encrypts the plaintext using the One Time Pad cipher
 * plain_text: The text we want to encrypt
 * key : The key we encrpyt the data with
 * returns the cipher text 
 */

char* OTP_encrypt_text(char* plain_text,char* key);

/**This function decrypts the cipher_text the One Time Pad cipher
 * cipher_text: The text we want to decrypt
 * key : The key we decrypt the data with
 * returns the cipher text 
 */

char* OTP_decrypt_text(char* cipher_text,char* key);

/**This function encrypts the plaintext using the caesar cipher
 * plain_text: The text we want to encrypt
 * key : The number of shifts we want to do
 * returns the cipher text 
 */

char* caesar_encrypt(char* plain_text,int n);

void print_string(char* text);

int check_key(char* plain_text,char* key,int length);