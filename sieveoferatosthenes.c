
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
bool* initialize_prime_flags(int max);
void mark_multiples(bool* prime_flags, int max, int p);
int find_next_prime(bool* prime_flags, int max, int current);
void output_all(bool* prime_flags, int columncount, int max);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
void main(void)
{
    puts("-------------------------");
    puts("| codedrome.com         |");
    puts("| Sieve of Eratosthenes |");
    puts("-------------------------\n");

    const int max = 100;
    bool* prime_flags;
    int p = 2;

    prime_flags = initialize_prime_flags(max);

    puts("Initial state: all marked as prime");

    output_all(prime_flags, 10, max);

    puts("\nRunning Sieve of Eratosthenes...");

    while(p != -1)
    {
        mark_multiples(prime_flags, max, p);

        p = find_next_prime(prime_flags, max, p);
    }

    puts("\nComposite numbers now identified");

    output_all(prime_flags, 10, max);

    puts("");

    free(prime_flags);
}

//--------------------------------------------------------
// FUNCTION initialize_prime_flags
//--------------------------------------------------------
bool* initialize_prime_flags(int max)
{
    bool* prime_flags;

    prime_flags = malloc(sizeof(bool) * (max + 1));

    for(int i = 2; i <= max; i++)
    {
        prime_flags[i] = true;
    }

    return prime_flags;
}

//--------------------------------------------------------
// FUNCTION output_all
//--------------------------------------------------------
void output_all(bool* prime_flags, int columncount, int max)
{
    printf(GRN "PRIME " RESET);
    printf(RED "COMPOSITE\n" RESET);

    printf("    ");

    for(int i = 2; i <= max; i++)
    {
        if(prime_flags[i] == false)
        {
            printf(RED "%3d " RESET, i);
        }
        else
        {
            printf(GRN "%3d " RESET, i);
        }

        if(i % columncount == 0)
        {
            puts("");
        }
    }
}

//--------------------------------------------------------
// FUNCTION mark_multiples
//--------------------------------------------------------
void mark_multiples(bool* prime_flags, int max, int p)
{
    int i;
    int multiplier = 2;
    i = p * multiplier;

    if(i <= max)
    {
        while(i <= max)
        {
            prime_flags[i] = false;

            multiplier++;

            i = p * multiplier;
        }
    }
}

//--------------------------------------------------------
// FUNCTION find_next_prime
//--------------------------------------------------------
int find_next_prime(bool* prime_flags, int max, int current)
{
    for(int i = current + 1; i <= max; i++)
    {
        if(prime_flags[i] == true)
        {
            return i;
        }
    }

    return -1;
}
