#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[])
{
    /* variable initialization */
    EVP_MD_CTX *mdctx;
    char message[] = "a message to be encrypted";
    unsigned char encrypted_value[EVP_MAX_MD_SIZE];
    unsigned int encrypted_value_len;

    /* call functions */
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit(mdctx, EVP_sha1());
    EVP_DigestUpdate(mdctx, message, strlen(message));
    // EVP_DigestUpdate(mdctx, another_message, strlen(another_message));
    // EVP_DigestUpdate can be called multiple times to encrypt addtional data
    EVP_DigestFinal_(mdctx, encrypted_value, &encrypted_value_len);

    /* print out results */
    printf("Encrypted data value is: ");
    for (int i = 0; i < encrypted_value_len; i++) {
        printf("%02x", encrypted_value[i]);
    }

    return 0;
}