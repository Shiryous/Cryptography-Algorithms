
#include "simple_crypto.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * The maximum accepted input text
 */
const int MAX_TEXT_SIZE = 1024; 
int main()
{
	OTP_cipher();
	Caesar_cipher();	
	vigenere_cipher();
	
	return 0;
}


/** This is the part for the One Time Pad Cipher
*/
void OTP_cipher(){

	char plain_text[MAX_TEXT_SIZE], *cipher_text, *secret_key, *decrypt_text;
	
	printf("[OTP] input:");
	
	fgets(plain_text,MAX_TEXT_SIZE,stdin); 		//Read string to be encrypted

	plain_text[strlen(plain_text)-1] = '\0';	//Remove the last character from fgets

	int length = (int)strlen(plain_text);		// The length of the plain text
	do
	{
		secret_key = OTP_generate_key(length);
	} while ((check_key(plain_text,secret_key,length)));	// Find a suitable key to encrypt the plain text

	cipher_text = OTP_encrypt_text(plain_text,secret_key);	// Encrypt the plain text using OTP.
	
	printf("[OTP] encrypted:");
	
	print_string(cipher_text);								// Print encrypted text

	decrypt_text = OTP_decrypt_text(cipher_text,secret_key);// Decrypt the plain text using OTP

	printf("[OTP] decrypted:%s\n",decrypt_text);			// Print the decrypted text

}
/** This is the part for the Caesars cipher
 */
void Caesar_cipher(){

	char plain_text[MAX_TEXT_SIZE], *cipher_text, *decrypt_text;
	int my_shift,shift = 0;

	printf("[Caesars] input    :");
	fgets(plain_text,MAX_TEXT_SIZE,stdin); 			// Read string to be encrypted

	plain_text[strlen(plain_text)-1] = '\0';	// Remove the last character from fgets

	/** This is for the malakaproofness of the code
	 */
	while(shift<=0){
		printf("[Caesars] key      :");						// Scan the shift number 
		scanf("%d",&shift);

	}
	int c;
	while ( (c = getchar()) != EOF && c != '\n') { }

	my_shift = shift%63;										// Apply modulo 63 so even if they give us a number larger than 62 we can handle it

	cipher_text = caesar_encrypt(plain_text,my_shift);

	printf("[Caesars] encrypted:%s\n",cipher_text);

	decrypt_text = caesar_decrypt(cipher_text,my_shift);

	printf("[Caesars] decrypted:%s\n",decrypt_text);

}

/** This is the part for the Vigeneres cipher
 */
void vigenere_cipher(){

	char plain_text[MAX_TEXT_SIZE], *cipher_text, *decrypt_text;

	printf("[Vigenere] input    :");
	
	fgets(plain_text,MAX_TEXT_SIZE,stdin); 			// Read string to be encrypted

	plain_text[strlen(plain_text)-1] = '\0';	// Remove the last character from fgets

	printf("[Vigenere] key      :");
	
	char* key = malloc(strlen(plain_text));

	fgets(key,MAX_TEXT_SIZE,stdin); 			// Read string to be encrypted

	key[strlen(key)-1] = '\0';	// Remove the last character from fgets

	cipher_text = vigenere_encrypt(plain_text,key);

	printf("[Vigenere] encrypted:%s\n",cipher_text);

	decrypt_text = vigenere_decrypt(cipher_text,key);

	printf("[Vigenere] decrypted:%s\n",decrypt_text);


}