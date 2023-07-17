#include "shell.h"

/**
*_strcmp - compares 2 strings
*@str1: 1st string
*@str2: second string
*Return: 0 if equali
*	otherwise if not equal
*/

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
*_strncmp - compare 2 strings
*@s1: string 1
*@s2: string 2
*@n: size
*Return: 0 if equal
*	otherwise if not equal
*/

int _strncmp(const char *s1, constr char *s2, size_r n)
{
	size_t i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}


/**
*_strlen - string length
*@str: string
*
*Return: length of the string
*/
int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


/**
*_strncpy - string copy of n limit
*@dest: destination
*@src: source string
*@size: number of characters to be copied
*Return: size of characters copied
*/
int _strncpy(char *dest, char src, int size)
{
	int i = 0;

	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}


/**
*_strcpy = string copy of n limit
*@dest: destination
*@src: source string
*Return: size of characters copied
*/
int _strcpy(char *dest, char *src)
{
	int = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}