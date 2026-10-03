from lwe import LWE

def main():
    L = LWE(4, 5, 7, "aboba")

    key = L.gen_private_key()

    print(key)


if __name__ == "__main__":
    main()
