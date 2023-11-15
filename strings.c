#include "main.h"

/**
 * _strcpy - Copies a string pointed to by `src` pointer including '\0'
 * to the buffer pointed to by `dest` pointer.
 *
 * @dest: Pointer that points to a Charcter value (string or array of chars.)
 * that the `src` pointers copies the orginal string to it.
 * @src: Pointer that points to a Character value  (string or array of chars.)
 * that it copies to `dest`.
 *
 * Return: Base address to the array of Characters `dest`.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - Returns a pointer to the newly allocated memory, where the
 * function copies the string given as a parameter to the newly allocated
 * memory.
 *
 * @str: Pointer to character value where the string wanted to be copied is
 * inserted as a parameter.
 *
 * Return: NULL if the `str` parameter is NULL
 *	   Base address of the duplicated string
 *	   or NULL if there is an insufficient memory for allocation.
 */

char *_strdup(char *str)
{
	/**
	 * Checking if the `str` pointer is given a NULL Pointer
	 * Before continuing the program
	 */

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		/**
		 * Moved the initializations here, so it won't access the
		 * `str` pointer when it is pointing to a NULL and cause
		 * Segmentation Fault.
		 */

		int str_size = _strlen(str) + 1;
		char *ptr = (char *)malloc(sizeof(char) * str_size);

		/**
		 * Checking if malloc function failed to allocate memory
		 * to `ptr` pointer.
		 */

		if (ptr == NULL)
		{
			return (NULL);
		}
		else
		{
			_strcpy(ptr, str);

			return (ptr);
		}
	}
}

/**
 * _strlen - Returns the length of a string.
 * @s: Pointer that points to a Character value.
 *
 * Return: String Length (Always +ve or Zero).
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer that points to a Character value, where the `src`
 * string should be concatenated to.
 * @src: Pointer that points to a Character value, where it contains
 * the string that should be concatenated to `dest`.
 *
 * Return: Base Address of `dest`.
 */

char *_strcat(char *dest, char *src)
{
	int len_src = _strlen(src);
	int i_dest = _strlen(dest);
	int len_t = len_src + i_dest;
	int i_src = 0;

	for (; i_dest <= (len_t - 1); i_dest++)
	{
		dest[i_dest] = src[i_src];
		i_src++;
	}

	dest[i_dest] = '\0';

	return (dest);
}

/**
 * _strcmp - Compare two strings.
 *
 * @s1: Pointer to Character value, which is the first string to be compared.
 * @s2: Pointer to Character value, which is the second string to be compared.
 *
 * Return: -ve Integer value if s1 is less than s2
 *	   Zero if s1 is equal to s2
 *	   +ve Integer value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}
		else if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	/**
	 * The for loop was completed and final character needs to be checked
	 */
	return (s1[i] - s2[i]);
}
