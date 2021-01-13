#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compute(int a, int m, int n)
{
  int r;
  int y = 1;

  while (m > 0)
  {
    r = m % 2;
    if (r == 1)
      y = (y * a) % n;
    a = a * a % n;

    m = m / 2;
  }

  return y;
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
  a = rand_range(l, u); // or use rand()
  A = compute(g, a, p);

  srand(time(0));
  b = rand_range(l, u); // or use rand()
  B = compute(g, b, p);

  int keyA = compute(B, a, p);
  int keyB = compute(A, b, p);

  printf("\nAlice's private key is %d\nBob's Private key is %d\n\n", a, b);
  printf("\nAlice's Public Key is %d\nBob's Public Key is %d\n\n", A, B);
  printf("\nAlice's Secret Key is %d\nBob's Secret Key is %d\n\n", keyA, keyB);
  return 0;
}