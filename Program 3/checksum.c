#include <stdio.h>

unsigned words[10];
unsigned short checksum() 
{
    int i, sum = 0;

    printf("\nEnter IP header information in 16 bit words \n");

    for (i = 0; i < 9; i++)
    {
        printf("Word %d : ", i + 1);
        scanf("%x", &words[i]);

        sum = sum + (unsigned short)words[i];
        while (sum >> 16)
        {
            sum = (sum & 0XFFFF) + (sum >> 16);
        }
    } 
    sum = ~sum;
    return (unsigned short)sum;
}

int main()
{
    unsigned short result1, result2;
    result1 =  checksum();
    printf( "\ncheck sum at sender is %x\n", result1);
    result2 = checksum();
    printf( "\ncheck sum at receiver is %x\n", result2);
    if( result2 == result1)
        printf("Correct \n");
    else
    {
        printf("Error");
    }
    return 0;

}
