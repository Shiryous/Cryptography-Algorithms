// This is the header file of the simple crypto program

/** Define the struct for th Tabula Recta
 */
typedef struct tabula
{
    char matrix[26][26];
}tabula;

/** This is a function that generates a secret key for One time Pad
 */
char* OTP_generate_key(int n);

/** This function encrypts the plaintext using the One Time Pad cipher
 * plain_text: The text we want to encrypt
 * key : The key we encrpyt the data with
 * returns: the cipher text 
 */

char* OTP_encrypt_text(char* plain_text,char* key);

/** This function decrypts the cipher_text the One Time Pad cipher
 * cipher_text: The text we want to decrypt
 * key : The key we decrypt the data with
 * returns: the decrypted text 
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

/** Shift left the alphabet that is given .
 * alphabet[]: The alphabet to shift
 * shift: Number of times to shift to the left.
 */
void left_shift_alphabet(char alphabet[],int shift);

/** Shift left the alphabet that is given once.
 * alphabet[]: The alphabet to shift
 */
void left_shift_alphabet_by_one(char alphabet[]);

/** Shift right the alphabet that is given .
 * alphabet[]: The alphabet to shift
 * shift: Number of times to shift to the right.
 */
void right_shift_alphabet(char alphabet[],int shift);

/** Shift right the alphabet that is given once.
 * alphabet[]: The alphabet to shift
 */

void right_shift_alphabet_by_one(char alphabet[]);

/** Find the index of the character in the alphabet.
 * a[]: The alphabet we are looking at
 * size: The size of the alphabet
 * value: The character
 */
int findIndex( const char a[], int size, char value );

/** This function skips the characters from the plain_text that are not part of the alphabet(Caesar cipher)
 * plain_text: The plain_text 
 * returns: The plain_text without the characters that are not part of the alphaber
 */

char* skip_non_alphabet(char* plain_text);

/** This function skips the characters from the plain_text that are not part of the alphabet(Vigenere cipher)
 * plain_text: The plain_text 
 * returns: The plain_text without the characters that are not part of the alphabet
 */

char* skip_non_upper_characters(char * plain_text);

/** Create the tabula recta (Vigenere Cipher)
 */

tabula create_tabula_recta();

/** Shift left the alphabet that is given by one.
 * alphabet[]: The alphabet to shift
 */

void left_shift_upper_alphabet_by_one(char alphabet[]);

/** This function encrypts the plain_text using the vigenere cipher
 * plain_text: The text we want to encrypt
 * key : The key to encrypt it with
 * returns the encrypted text 
 */

char* vigenere_encrypt(char* plain_text,char* key);

/** This function decrypts the cipher_text of the vigenere cipher
 * cipher_text: The text we want to decrypt
 * key : The key to decrypt it with
 * returns the decrypted text 
 */
char* vigenere_decrypt(char* cipher_text,char* keyword);

/** This function takes a character and returns the index it has on the english alphaber e.g. A=0, B=1, ...
 */

int create_char_index(char ch);
/**These functios were created to easily enable and disable different parts of the main for each cipher
 */
void OTP_cipher();
void Caesar_cipher();
void vigenere_cipher();
