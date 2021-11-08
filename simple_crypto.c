/**
 *This is the includes we need to run our library
 */

#include "simple_crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TABULA_SIZE = 26;
const int SIZE_OF_ALPHABET = 63;
const char upperAlphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char myAlphabet[63] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
						 											 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
/**
* This is the implementation of the OTP (One-Time-Pad) algorithm
* --------------------------------------------------------------------------------------------------
-	The One-Time-Pad (OTP) algorithm is a very simple but yet very strong algorithm in the sense
- that it can not be cracked even with post-quantum techniques. The algorithm pairs each
- plaintext with a random secret key (also referred to as a one-time pad). Specifically, each bit or
- byte/character of the plaintext is combined with the corresponding bit or byte/character from the
- random secret key. One-time pad requires that the secret key is of the same size or longer than
- the plaintext. 
----------------------------------------------------------------------------------------------------
*/

/** This is a function that takes the plaintext and encrypts it using the secret key by XOR-ing the characters
 */
char* OTP_encrypt_text(char* plain_text,char* key){

	int n = 0,length = strlen(plain_text);
	
	char* cipher_text = malloc(length);

	while(n<length){							// For all the plaintext
		cipher_text[n] = plain_text[n]^key[n];  // XOR every character of the plaintext with every character of the key
		n++;
	}
	cipher_text[n] = '\0'; // Add the end character
	
	return cipher_text;
}
/**
 * This is a function that takes the ciphertext and decrypts it using the secret key by XOR-ing the characters
 * Its basically the same with OTP_encrypt_text. 
 * But different to make clearer the steps we follow
 */
char* OTP_decrypt_text(char* cipher_text,char* key){
	
	int n = 0,length = strlen(cipher_text);

	char* decrypt_text = malloc(length);

	while(n<length){							// For all the ciphertext
		decrypt_text[n] = cipher_text[n]^key[n];// XOR every character of the ciphertext with every character of the key
		n++;
	}
	decrypt_text[n] = '\0'; // Add the end character
	
	return decrypt_text;
}

/** In here we generate random key using the dev/urandom
 * n : Number of bytes/characters found in the plaintext
 * returns: The key for the OTP encryption
 */
char* OTP_generate_key(int n){

	char *data = malloc(n+1);
	char buffer;

	FILE *fp;
	int count = 0;

	fp = fopen("/dev/urandom", "r"); // Set the file pointer to the /dev/urandom and read
	
	while(count<n){

		fread(&buffer, 1, 1, fp);	//Using fread we read 1 char from the file pointer to the buffer

		if((buffer>65) && (buffer<90) || (buffer>47 && buffer<58) || (buffer>96 && buffer<123)){ // In here we check if the char is A-Z or a-z or 0-9
			data[count] = buffer; 																 // If the char is what we want we store it in the key
			count++;
		}
	}
	data[count] ='\0';						// Add the end character
	fclose(fp);								// Close the file when we are done
	return data;
}

/**
 * This function prints the encrypted strings so that we can also print non-printable characters in hexadecimal representation.
 */
void print_string(char* text){
	int counter = 0;

	while(counter < strlen(text)){							// Print the string character by character
		if(text[counter]<31){								// If the character is non-printable print its hex value in brackets
			printf("(Hex:%x)", text[counter] & 0xff);
		}
		else	printf("%c",text[counter]); 				// If its printable just print it
		counter++;
	}
	printf("\n");
}
/**
 * Checks if there is a same character in the same position of the key and the plaintext.
 * Do this to avoid the character '\0' to be able to encrypt correctly the plaintext
 */

int check_key(char* plain_text,char* key,int len){
	int n=0;
	while(n<len){
		if(plain_text[n]==key[n]){
			return 1;
		}
		n++;
	}
	return 0;
}


/**
* This is the implementation of the the Caesar cipher
* --------------------------------------------------------------------------------------------------
-	This technique is one of the simplest and most widely known encryption techniques. It is a type
- of substitution cipher in which each byte/character of the plaintext is replaced by a
- byte/character found at some fixed number of positions down the alphabet/ASCII set. For
- example, given the ASCII character set, a shift of 3 will replace the letter “A” of the plaintext
- with the letter “D” at the ciphertext. Also, a shift of 4 will encrypt the plaintext “hello” as “lipps”.
- The function(s) encrypting and decrypting the messages should receive as arguments the plainor cipher-text 
- as well as the random secret key and should return the result of the operation.
----------------------------------------------------------------------------------------------------
*/

char* caesar_encrypt(char * plain_text,int shift){
	char* buffer = skip_non_alphabet(plain_text);		// Skip the characters that are not on the alphaber
	plain_text = buffer;
	int i =0;
	char* shifted_alphabet = malloc(SIZE_OF_ALPHABET);
	char* caesar_encrypted;
	strcpy(shifted_alphabet,myAlphabet);

	left_shift_alphabet(shifted_alphabet,shift);		// Shift the alphabet by the amount that was given to us

	while(i<strlen(plain_text)){						// For all the plain_text
		caesar_encrypted[i] = shifted_alphabet[findIndex(myAlphabet,SIZE_OF_ALPHABET,plain_text[i])]; // Find the index of the character in the alphabet and input it in the new alphabet to encrypt it
		i++;
	}
	caesar_encrypted[i]='\0';	
	return caesar_encrypted;
}

char* caesar_decrypt(char * cipher_text,int shift){
	int i=0;
	char shifted_alphabet[SIZE_OF_ALPHABET] ;
	char* caesar_decrypted ;

	strcpy(shifted_alphabet,myAlphabet);

	right_shift_alphabet(shifted_alphabet,shift);		// Shift the alphabet by the amount that was given to us

	while(i<strlen(cipher_text)){
		caesar_decrypted[i] = shifted_alphabet[findIndex(myAlphabet,SIZE_OF_ALPHABET,cipher_text[i])]; // Find the index of the character in the alphabet and input it in the new alphabet to encrypt it
		i++;
	}
	caesar_decrypted[i] = '\0';

	return caesar_decrypted;
}
void left_shift_alphabet(char alphabet[],int shift){
	int i;
	for(i = 0;i<shift; i++){    
	   left_shift_alphabet_by_one(alphabet);
	} 
}
void left_shift_alphabet_by_one(char alphabet[]){
	int i;

	char temporary = alphabet[0];

    for (i = 0; i < SIZE_OF_ALPHABET-1; i++)
        alphabet[i] = alphabet[i + 1];
    
    alphabet[SIZE_OF_ALPHABET-2] = temporary;


}

void right_shift_alphabet(char alphabet[],int shift){
	for(int i = 0;i<shift; i++){    
	   right_shift_alphabet_by_one(alphabet);
	} 
}

void right_shift_alphabet_by_one(char alphabet[]){
	int i;

	char temporary = alphabet[SIZE_OF_ALPHABET-1];

    for (i = SIZE_OF_ALPHABET-1; i > 0 ; i--){
        alphabet[i] = alphabet[i - 1];
    }
    alphabet[0] = temporary;

}
int findIndex( const char a[], int size, char value )
{
    int index = 0;

    while ( index < size && a[index] != value ) ++index; // While the value is different +1, until the size limit

    return ( index == size ? -1 : index );	// if we found it return size, else -1
}
char* skip_non_alphabet(char* plain_text){

	int i = 0,count = 0,length = strlen(plain_text);
	char* buffer = malloc(strlen(plain_text));

	while(i<length){
		if((plain_text[i]>64) && (plain_text[i]<90) || (plain_text[i]>47 && plain_text[i]<58) || (plain_text[i]>96 && plain_text[i]<123)){
			buffer[count] = plain_text[i]; 	
			count++;	
		}		
		i++;
	}
	buffer[count] = '\0';
	return buffer;
}



/**
* This is the implementation of the the Vigeneres cipher
* --------------------------------------------------------------------------------------------------------
- The Vigenère’s cipher encrypts an alphabetic plaintext using a series of interwoven Caesar’s
- ciphers. In order to encrypt a message, the algorithm uses a table of alphabets, namely tabula
- recta, which has the alphabet written out 26 times in different rows, each alphabet shifted
- cyclically to the left compared to the previous alphabet, corresponding to the 26 possible Caesar
- ciphers. At different points in the encryption process, the cipher uses a different alphabet from
- one of the rows.
----------------------------------------------------------------------------------------------------------
*/
char* skip_non_upper_characters(char * plain_text){
	int i = 0,count = 0,length = strlen(plain_text);
	char* buffer;

	while(i<length){
		if((plain_text[i]>64) && (plain_text[i]<91)){
			buffer[count] = plain_text[i]; 	
			count++;	
		}		
		i++;
	}
	buffer[count] = '\0';
	return buffer;
}
char* create_key_vigenere(char* plain_text,char* keyword){
	int length = strlen(keyword);
	int i = 0;
	char* key = malloc(strlen(plain_text));

	while(i<strlen(plain_text)){ // Match the keys length with the plaintexts 
		key[i] = keyword[i%length]; // If the key is smaller than the plaintext, repeat the keyword until it matches in length
		i++;
	}
	key[i] = '\0';
	return key;
}
tabula create_tabula_recta(){
	tabula my_tabula;
	char tmpAlphabet[SIZE_OF_ALPHABET];

	strcpy(tmpAlphabet,upperAlphabet);
	
	for (int i = 0; i < TABULA_SIZE; ++i)
	{
		for (int j = 0; j < TABULA_SIZE; ++j)
		{
			my_tabula.matrix[i][j] = tmpAlphabet[j];
		}
		left_shift_upper_alphabet_by_one(tmpAlphabet);
	}
	return my_tabula ;
}
void left_shift_upper_alphabet_by_one(char alphabet[]){
	int i;

	char temporary = alphabet[0];

    for (i = 0; i < TABULA_SIZE-1; i++){
        alphabet[i] = alphabet[i + 1];
    }
    alphabet[TABULA_SIZE-1] = temporary;

}
char* vigenere_encrypt(char* plain_text,char* keyword){
	tabula my_tabula = create_tabula_recta();					//Create the tabula recta
	char*	my_key = create_key_vigenere(plain_text,keyword);	//THIS is the key with the same size with the plaintext
	char* vigenere_encrypted ;
	int i=0;
	
	while(i<strlen(my_key)){
		vigenere_encrypted[i] = my_tabula.matrix[create_char_index(my_key[i])][create_char_index(plain_text[i])];
		i++;
	}
	vigenere_encrypted[i] = '\0';
	return vigenere_encrypted;
}
char* vigenere_decrypt(char* cipher_text,char* keyword){
	tabula my_tabula = create_tabula_recta();					//Create the tabula recta
	char* my_key = create_key_vigenere(cipher_text,keyword);	//THIS is the key with the same size with the ciphertext
	char* vigenere_decrypted ;
	
	for (int i = 0; i < strlen(my_key); ++i)
	{
		for (int j = 0; j < TABULA_SIZE-1; ++j)
		{

			if (my_tabula.matrix[create_char_index(my_key[i])][j] == cipher_text[i])
			{
				vigenere_decrypted[i] = my_tabula.matrix[0][j];
				break;
			}
		}
	}
	vigenere_decrypted[strlen(cipher_text)] = '\0';
	return vigenere_decrypted;
}
int create_char_index(char ch){
	int index;
	index = (int)ch-65;
	return index;
}
