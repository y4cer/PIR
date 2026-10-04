# Make LWE implementation

- STATUS: OPEN
- PRIORITY: 100
- TAGS: lwe

Since ZipPIR in 20261004-081939 heavily relies on LWE, I need to implement the LWE first.

Needed functions:

LWE::Lwe(n, m, p)
LWE::PrivateKey LWE::KeyGen()
LWE::PublicKey LWE::PublicKey(PrivateKey& private_key)
string LWE::Encrypt(string plaintext, PublicKey& public_key)
string LWE::Decrypt(string ciphertext, PrivateKey& private_key)
