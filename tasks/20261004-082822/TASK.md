# Make LWE implementation

- STATUS: CLOSED
- PRIORITY: 100
- TAGS: lwe

Since ZipPIR in 20261004-081939 heavily relies on LWE, I need to implement the LWE first.

done in: 20261110-194614

Needed functions:

LWE::Lwe(n, m, p)
LWE::PrivateKey LWE::KeyGen()
LWE::PublicKey LWE::PublicKey(PrivateKey& private_key)
string LWE::Encrypt(string plaintext, PublicKey& public_key)
string LWE::Decrypt(string ciphertext, PrivateKey& private_key)
