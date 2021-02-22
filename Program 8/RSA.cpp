#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long isprime(long a)
{
    int i;
    for (i = 2; i < a; i++)
    {
        if ((a % i) == 0)
            return 0;
    }
    return 1;
}

// for encryption, c=m^emodn
long int encrypt(char ch, long n, long e)
{
    int i;
    long temp = ch;
    for (i = 1; i < e; i++)
        temp = (temp * ch) % n;
    return temp;
}

// for decryption, m=c^dmodn
char decrypt(long ch, long n, long d)
{
    int i;
    long temp = ch;
    for (i = 1; i < d; i++)
        ch = (temp * ch) % n;
    return ch;
}

int main()
{
    srand(time(0));
    long i, len;
    long p, q, n, phi, e, d, cipher[50];
    char text[50];

    cout << "Enter the text to be encrypted: ";
    cin.getline(text, sizeof(text));
    len = strlen(text);
    do
    {
        p = rand() % 1000;
    } while (!isprime(p) && p > 100);
    // p is prime number > 100

    do
    {
        q = rand() % 1000;
    } while (!isprime(q) && q > 100);
    // q is prime number > 100

    n = p * q;
    phi = (p - 1) * (q - 1); // Eulers toitent function
    // and value of d, e should be between 1 and phi and e, phi should be co-primes
    // d equivalents e^-1 * mod(phi),  i.e., d*e equivalents 1mod(phi)  =>  (d*e)mod(phi) = 1

    do
    {
        e = rand() % phi;
    } while (gcd(phi, e) != 1);

    do
    {
        d = rand() % phi;
    } while (((d * e) % phi) != 1);

    cout << "Two numbers (p and q) are: " << p << " and " << q << endl;
    cout << "n = (p * q) = " << p << " * " << q << " = " << p * q << endl;
    cout << "(p - 1) * (q - 1) = " << phi << endl;

    cout << "Public key (n,  e): (" << n << ", " << e << ")\n";
    cout << "Private key (n, d): (" << n << ", " << d << ")\n";

    for (i = 0; i < len; i++)
        cipher[i] = encrypt(text[i], n, e);
    cout << "Encrypted message: ";
    for (i = 0; i < len; i++)
        cout << cipher[i];

    for (i = 0; i < len; i++)
        text[i] = decrypt(cipher[i], n, d);
    cout << endl;
    cout << "Decrypted message: ";
    for (i = 0; i < len; i++)
        cout << text[i];
        
    cout << endl;
    return 0;
}