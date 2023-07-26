#include "shell.h"

/**
*_memcpy - copies memory from source to detination
*@dest: destination
*@src: source
*@n: size of memory to be copied
*Return: memory of destination
*/
void *_memcpy(void *dest, void *src, size_t n)
{
	char *cdest = (char *)(dest);
	const char *csrc = (const char *)(src);
	size_t i = 0;

	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

/**
*_realloc- change memory block pointed size to by ptr to size bytes.
*@ptr: old pointer
*@size: new size
*Return: new pointer
*/
void *_realloc(void *ptr, size_t size)
{
	void *n_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	n_ptr = malloc(size);
	if (n_ptr == NULL)
		return (NULL);
	_memcpy(n_ptr, ptr, size);
	free(ptr);
	return (n_ptr);
}


/**
*_strdup- duplicates a string
*@s: string
*Return: duplicated string
*/
char *_strdup(char *s)
{
	size_t len = _strlen(s) + 1;
	char *n_str = malloc(len);

	if (n_str == NULL)
		return (NULL);
	_memcpy(n_str, s, len);
		return (n_str);
}


/**
*_strcat- concatenate two strings
*@dest: string destination
*@src: string source
*Return: concatenated string
*/

char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		ptr[i] = src[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}


/**
*_strchr- locate character in string
*@str: string to be searched
*@character: character to search
*Return: pointer to the string
*/
char *_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
