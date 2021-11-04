
#include "simple_crypto.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * The maximum accepted input text
 */
const int MAX_TEXT_SIZE = 256; 

int main()
{
	char plain_text[MAX_TEXT_SIZE], *cipher_text, *secret_key, *decrypt_text;
	
	/** This is the part for the One Time Pad Cipher
	*/
	printf("[OTP] input    :");
	fgets(plain_text,MAX_TEXT_SIZE,stdin); 		//Read string to be encrypted
	
	plain_text[strlen(plain_text)-1] = '\0';	//Remove the last character from fgets

	int length = (int)strlen(plain_text);		// The length of the plain text
	do
	{
		secret_key = OTP_generate_key(length);
	} while ((check_key(plain_text,secret_key,length)));	// Find a suitable key to encrypt the plain text

	cipher_text = OTP_encrypt_text(plain_text,secret_key);	// Encrypt the plain text using OTP.

	print_string(cipher_text);								// Print encrypted text

	decrypt_text = OTP_decrypt_text(cipher_text,secret_key);// Decrypt the plain text using OTP

	printf("[OTP] decrypted:%s\n",decrypt_text);			// Print the decrypted text

	/** This is the part for the Caesars cipher
	 */
	char caesar_plain_text[MAX_TEXT_SIZE], *caesar_cipher_text, *caesar_decrypt_text;
	int shift=0;
	printf("[Caesars] input    :");
	fgets(caesar_plain_text,MAX_TEXT_SIZE,stdin); 		// Read string to be encrypted

	caesar_plain_text[strlen(caesar_plain_text)-1] = '\0';	// Remove the last character from fgets

	/** This is for the malakaproofness of the code
	 */
	while(shift<=0){
		printf("[Caesars] key    :");				// Scan the shift number 
		scanf("%d",&shift);
	}
	shift = shift%63;								// Apply modulo 63 so even if they give us a number larger than 62 we can handle it

	caesar_cipher_text = caesar_encrypt(caesar_plain_text,shift);

	printf("[Caesars] encrypted:%s\n",caesar_cipher_text);

	caesar_decrypt_text = caesar_decrypt(caesar_cipher_text,shift);

	printf("[Caesars] decrypted:%s\n",caesar_decrypt_text);

	return 0;
}