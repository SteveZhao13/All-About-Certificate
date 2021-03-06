# All-About-Certificate
Including all the information and explanation when learning certificates related knowledge

## Openssl

#### Using openssl library in Bash Shell

#### Using openssl library in C/C++ programming

---

How to add openssl library into CMake files so that the C/C++ programs can include \<openssl\>

```makefile
project(project_name)
find_package(OpenSSL REQUIRED)
target_link_libraries(project_name OpenSSL::SSL)
```

---

EVP_Digest related functions are used to encrypt data (usually a char[]) using a certain cryptographic function

* Definition/Syntax of common used functions
    
```cpp
/* initializes digest context "ctx" */
EVP_MD_CTX *EVP_MD_CTX_new(void);
/* Sets up digest context "ctx" to use a digest "type" */
/* "type" will typically be supplied by a function such as EVP_sha1() */
/* [IN]: "type"; [OUT]: "ctx" */
int EVP_DigestInit(EVP_MD_CTX *ctx, const EVP_MD *type);
/* Hashes "cnt" bytes of data of "d" (usually a char) into the digest context "ctx" */
/* Can be called several times on the same "ctx" to hash additional data */
/* [IN]: "d" and "cnt"; [OUT]: "ctx" */
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
/* Retrieves the digested value from "ctx", stores its content in "md" and stores its length in "s" */
/* [IN]: "ctx"; [OUT]: "md" and "s" */
int EVP_DigestFinal(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s);
```

* Example of how to encrypt data from raw data "message[]" to encrypted data "encrypted_value[]" and print out the encrypted data

```cpp
/* variable initialization */
EVP_MD_CTX *mdctx;
char message[] = "a message to be encrypted";
unsigned char encrypted_value[EVP_MAX_MD_SIZE];
unsigned int encrypted_value_len;
/* call functions */
mdctx = EVP_MD_CTX_new();
EVP_DigestInit(mdctx, EVP_sha1());
EVP_DigestUpdate(mdctx, message, strlen(message));
EVP_DigestFinal(mdctx, encrypted_value, &encrypted_value_len);
/* print out results */
printf("Encrypted data value is: ");
for (int i = 0; i < encrypted_value_len; i++) {
    printf("%02x", encrypted_value[i]);
}
```
---
What are the properties of EVP_Digest function:

* For any random message, generating a hash value is easy to implement
* For any hash value, in theory, it's not possible to retrieve the according message (the EVP_Digest functions are single direction)
* It's not possible to only change the message without changing its hash value
* It's not possible to find two messages with the same hash value

**Ref:** [The GmSSL Project](http://gmssl.org/docs/evp-api.html)