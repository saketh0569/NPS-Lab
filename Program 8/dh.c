#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// have a public key, mix it with a secret key and exchange it publicly, and then mix it with the secret key they have. And here the final key for both is same.
// first both agree on 2 prime numbers p>g, and then private key is selected in random, and public key is found by using modulo function of private key and, secret key is found by modulo of public key.

int compute(int a, int n, int m)    // returns (a^m)modn
{
    int i;
    int temp = a;
    for (i = 1; i < m; i++)
        a = (temp * a) % n;
    return a;
}

int rand_range(int l, int u)
{
	return rand() % (u - l + 1) + l;
}

// C program to demonstrate Diffie-Hellman algorithm
int main()
{
	int p = 23;
	int g = 5;

	printf("Modulus: %d, Base: %d\n", p, g);
	int a, b;
	int A, B;

	int l = 1, u = 1000;
	printf("range: %d - %d\n", l, u);

	srand(time(0));
	a = rand_range(l, u); // or use rand() : private key
	A = compute(g, a, p); // it means A = g power a modulo p : public key

	srand(time(0));
	b = rand_range(l, u); // or use rand() : private key
	B = compute(g, b, p); // public key

	int keyA = compute(B, a, p);
	int keyB = compute(A, b, p);

	printf("\nAlice's private key is %d\nBob's Private key is %d\n\n", a, b);
	printf("\nAlice's Public Key is %d\nBob's Public Key is %d\n\n", A, B);
	printf("\nAlice's Secret Key is %d\nBob's Secret Key is %d\n\n", keyA, keyB);
	return 0;
}