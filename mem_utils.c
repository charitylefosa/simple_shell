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
*_realloc- change memory size block pointed to by ptr to size bytes.
*@ptr: old pointer
*@size: new size
*Return: new pointer
*/
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}


/**
*_strdup- duplicates a string
*@s: string
*Return: duplicated string
*/
char *_strdup(char *s)
{
	size_t len = _strlen(s) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, s, len);
		return (new_str);
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
*_strchr- locate character in a string
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
