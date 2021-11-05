// This is the header file of the simplr crypto program

/**
 * this is a function that generates a secret key for One time Pad
 */
char* OTP_generate_key(int n);

/** This function encrypts the plaintext using the One Time Pad cipher
 * plain_text: The text we want to encrypt
 * key : The key we encrpyt the data with
 * returns the cipher text 
 */

char* OTP_encrypt_text(char* plain_text,char* key);

/** This function decrypts the cipher_text the One Time Pad cipher
 * cipher_text: The text we want to decrypt
 * key : The key we decrypt the data with
 * returns the cipher text 
 */

char* OTP_decrypt_text(char* cipher_text,char* key);

/** This function encrypts the plaintext using the caesar cipher
 * plain_text: The text we want to encrypt
 * shift : The number of shifts we want to do
 * returns the cipher text 
 */

char* caesar_encrypt(char* plain_text,int shift);

/** This function encrypts the plaintext using the caesar cipher
 * cipher_text: The text we want to decrypt
 * shift : The number of shifts we want to do
 * returns the decrypted text 
 */

char* caesar_decrypt(char * cipher_text,int shift);

/** This is a function to print encrypted string that may include non-printable characters
 * text: The text we want to prin 
 */

void print_string(char* text);

/** This is a function that checks if 2 characters in the same position of the key and the plain text in the OTP cipher
 * plain_text: The text we want to encrypt
 * key: The key to encrypt it with
 * length: The length of the plaintext
 */

int check_key(char* plain_text,char* key,int length);

void left_shift_alphabet(char alphabet[],int shift);

void left_shift_alphabet_by_one(char alphabet[]);

void right_shift_alphabet(char alphabet[],int shift);

void right_shift_alphabet_by_one(char alphabet[]);

int findIndex( const char a[], int size, char value );

char* skip_non_alphabet(char* plain_text);

char* skip_non_upper_characters(char * plain_text);

void OTP_cipher();
void caesar_cipher();
void vigenere_cipher();
