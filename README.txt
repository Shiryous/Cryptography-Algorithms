Author:Monogyios Antonios 
Technical University of Crete
Security of Systems  
------------------------------------------------------------------------------------------------------------
This is a program called simple_crypto written in the language C creates and utilises 3 different ciphers.
The One Time Pad, the Caesar and the Vigenere's ciphers.
------------------------------------------------------------------------------------------------------------
ABSTRACT:

Firstly, the One Time Pad cipher takes the plain text we give and then generates a random key using the 
dev/urandom. We encrypt the plain text by XOR-ing every character of the plaintext and the key.After the 
encryption we display the printable characters, and for the non-printable display their
hexadecimal value inside a (Hex:xx) e.g. The character line feed(LF) is represented as (Hex:a). To decrypt 
the characters redo the same operation, xor the ciphertext and the key to decrypt.

Secondly, the Caesar cipher uses an alphabet that has the characters 0-9,A-Z,a-z in that particular order. If
there are characters in the plaintext that do not exist in the alphabet we just skip them.To encrypt the data 
we shift the alphabet by a number of characters that is specified by the user to the left. Then take the plain
text characters and match them to the new alphabet. For the decryption we revert the alphabet back by shifting
the alphabet to the right. And then match the positions to decrypt.

At last, the Vigenere creates the tabula recta then takes the keyword that was given by the user and matches the length of the plaintext. For the encryption use the index of the letters in the alphabet match a specific point in the tabula recta, that indicates the characters of the encrypted cipher. For the decryption using the key as a row indicator, find the column that coresponds to the letter of the ciphertext and take the character of the first row in the specific column to decrypt the text.
------------------------------------------------------------------------------------------------------------

The version of the gcc compiler that was used to compile the program:
gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

------------------------------------------------------------------------------------------------------------
Below are the helper functions and macrps that were necessary to implement the assignment:
------------------------------------------------------------------------------------------------------------
/** Define the struct for the Tabula Recta
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
