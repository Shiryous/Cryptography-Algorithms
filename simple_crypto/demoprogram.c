
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

	return 0;
}