/*****************************************************************//**
 * \file   main.cpp
 * \brief  My implementations of stdio library functions: puts, strlen, strchr, strcpy,
 *         strncpy, ~~~
 * 
 *********************************************************************/

#include <stdio.h>   
#include <string.h>
#include <assert.h>

/// For testing performance
#include <time.h>

/// Hides "str... function is unsafe" warning
#pragma warning(disable:4996)

/**
 * Prints string to stdout
 * 
 * \param const char* str String
 * \return 1, if printing succeeded; else EOF.
 */
int puts_ (const char *str)
{
    assert (str != NULL);

    while (*str != '\0')
        if (putc (*str++, stdout) == EOF)
            return EOF;
    putc ('\n', stdout);
    return 1;
}

/**
 * Counts amount of symbols is a string
 * 
 * \param const char* str String
 * \return unsigned long long Number of symbols 
 */
unsigned long long strlen_ (const char *str)
{
    assert (str != NULL);

    const char *ptr = str;
    while (*ptr++);
    return ptr - str - 1;        
}

/**
 * Finds the first letter in str that matches the chr
 * 
 * \param const char *str String
 * \param char chr Char to be found
 * \return A pointer to the char if found, NULL if not
 */
const char* strchr_ (const char *str, char chr)
{
    assert (str != NULL);
    
    while (*str != chr && *str) str++;
    return *str == '\0' ? NULL : str;
}

/**
 * Copies contents of one string into another
 * 
 * \param char* copy_to
 * \param const char* copy_from
 * \return char* Pointer to the copied string
 */
char *strcpy_ (char *copy_to, const char *copy_from)
{
    assert (copy_from != NULL);
    assert (copy_to != NULL);

    // ����� �� assert (to != from) ?

    char *copied = copy_to;
    while (*copy_to++ = *copy_from++);
    return copied;
}

/**
 * Copies first n symbols of one string into another
 * 
 * \param char* copy_to
 * \param const char* copy_from
 * \param n Amount of symbols to be copied
 * \return Pointer to the copied string
 */
char *strncpy_ (char *copy_to, const char *copy_from, int n)
{
    assert (copy_from != NULL);
    assert (copy_to != NULL);

    // Determines if we're copying chars from beyond copy_from string;
    char str_end = 0;
    int i = 0;

    while (i++ < n)
        if (!str_end)
        {
            if ((*copy_to++ = *copy_from++) == '\0')
                str_end = 1;
        }
        else
        {
            *copy_to++ = 0;   
        }    
        
    return copy_to - i + 1;
}

/**
 * Concatenates destination and source strings
 * 
 * \param  char* dest
 * \param  char* source 
 * \return Pointer to the result string 
 */
char *strcat_ (char *dest, const char *source)
{
    char *result = dest;
    
    dest += strlen (dest); // Now points on \0
    while (*dest++ = *source++);
    
    return result;
}

/**
 * Adds n symbols of source string to the end of the destination string
 * 
 * \param  char* dest
 * \param  char* source
 * \param  n Number of symbols to copy 
 * \return Pointer to the result string 
 */
char *strncat_ (char *dest, const char *source, int n)
{
    char *result = dest;
    
    dest += strlen (dest); // Now points on \0
    while ((*dest++ = *source++) && (dest - result < n));
    
    return result;
}


int main (int argc, char *argv[])
{
    const char a[3] = "ab";
    char b[20] = "reqwe ";

    printf ("%s", strncat_ (b, a, 1));
    
    return 0;

    // speed test
    unsigned long long num = 1000000000;
    double start = 0, end = 0;

    start = clock();
    for (int i = 0; i < num; i++)
        strchr_ (a, 'v');
    end = clock();
    
    printf ("%lf\n", end - start);
   
    start = 0, end = 0;

    start = clock();
    for (int i = 0; i < num; i++)
        strchr (a, 'v');
    end = clock();
    
    printf ("%lf\n", end - start);
    
    return 0;
}
