/**
 *This is the include we need to run our library
 */

#include "simple_crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * This is a function that takes the plaintext and encrypts it using the secret key by XOR-ing the characters
 */
char* OTP_encrypt_text(char* plain_text,char* key){

	int n = 0,length = strlen(plain_text);
	
	char* cipher_text = malloc(length);

	while(n<length){
		cipher_text[n] = plain_text[n]^key[n];
		n++;
	}
	cipher_text[n] = '\0';
	
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

	while(n<length){
		decrypt_text[n] = cipher_text[n]^key[n];
		n++;
	}
	decrypt_text[n] = '\0';
	
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
	fclose(fp);								// Close the file when we are done
	return data;
}

/**
 * This function prints the encrypted strings so that we can also print non-printable characters in hexadecimal representation.
 */
void print_string(char* text){
	int counter = 0;
	printf("[OTP] encrypted:");
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
