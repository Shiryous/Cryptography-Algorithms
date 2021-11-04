
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_crypto.h"


int main()
{
	char* plain_text = "secret";
	int length = (int)strlen(plain_text);
	char* cipher_text = (char*)malloc(length*sizeof(char));
	char* secret_key = (char*)malloc(length*sizeof(char));
	char* decrypt_text = (char*)malloc(length*sizeof(char));

	secret_key = OTP_generate_key(length);
	
	cipher_text = OTP_encrypt_text(plain_text,secret_key);

	printf("This is the plain_text:%s\n",plain_text);
	printf("This is the cipher_text:");


	print_string(cipher_text);

	decrypt_text = OTP_decrypt_text(cipher_text,secret_key);

	printf("This is the decrypt_text:%s\n",decrypt_text);

	return 0;
}
/**
 * This is a function that takes the plaintext and encrypts it using the secret key by XOR-ing the characters
 */
char* OTP_encrypt_text(char* plain_text,char* key){

	int n,length = strlen(plain_text);
	
	char* cipher_text = malloc(length);
	
	for(n = 0; n<length; n++){
		cipher_text[n] = plain_text[n]^key[n];
	}
	
	//strcat(cipher_text, "\0");
	free(cipher_text);
	printf("strlen cipher_text : %ld\n", strlen(cipher_text));
	
	return cipher_text;
}
/**
 * This is a function that takes the ciphertext and encrypts it using the secret key by XOR-ing the characters
 */
char* OTP_decrypt_text(char* cipher_text,char* key){
	int n,length = strlen(cipher_text);
	char* decrypt_text = malloc(length);

	for(n = 0; n<length;n++){
		decrypt_text[n] = cipher_text[n]^key[n];
	}
	//strcat(decrypt_text, "\0");
	printf("strlen decrypt_text : %ld\n", strlen(decrypt_text));
	
	free(decrypt_text);
	return decrypt_text;
}


/** In here we generate random key using the dev/urandom
 * n : Number of bytes/characters found in the plaintext
 */
char* OTP_generate_key(int n){

	char *data = malloc(n+1);
	char buffer;

	FILE *fp;
	int count = 0;

	fp = fopen("/dev/urandom", "r"); // Set the file pointer to the /dev/urandom and read
	
	while(count!=n){

		fread(&buffer, 1, 1, fp);	//Using fread we read 1 char from the file pointer to the buffer

		if((buffer>65) && (buffer<90) || (buffer>47 && buffer<58) || (buffer>96 && buffer<123)){ // In here we check if the char is A-Z or a-z or 0-9
			data[count] = buffer; 																 // If the char is what we want we store it in the key
			count++;
		}
	}
	fclose(fp);	//close the file when we are done

	return data;
}


void print_string(char* text){
	int counter = 0;
	while(counter < strlen(text)){
		if(text[counter]<31){ // if the character is not printable print its hex value in brackets
			printf("(Hex:%x)", text[counter] & 0xff);
		}
		else	printf("%c",text[counter]); // If its printable just print it
		counter++;
	}
	printf("\n");
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


/*char* caesar_encrypt(char* plain_text,int n){
	char* cipher_text;
	unsigned int count = 0;
	while(plain_text[count]!="\0"){
		cipher_text[count] = plain_text[count] + n;
		count++;
	}
	return cipher_text;
}
*/