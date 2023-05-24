#include "main.h"

/**
 * _strdup - Returns a pointer to a new allocated memory space.
 * @strng: string to copy
 *
 * Return: pointer to the duplicated string of _strdup.
 */
char *_strdup(char *strng)
{
	char *dup;
	int i, len;

	if (strng == NULL)
		return (NULL);

	len = 0;
	while (strng[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = strng[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * _strtok - splits a string into a series of tokens.
 * @str: string to tokenize
 * @delim: delimiter for function call _strtok
 *
 * Return: pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *sptr;
	char *token;
	int i, j, len;

	if (str == NULL)
		str = sptr;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	token = malloc(sizeof(char) * (len + 1));
	if (token == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				token[i] = '\0';
				sptr = &str[i + 1];
				return (token);
			}
		}
		token[i] = str[i];
	}
	token[i] = '\0';
	sptr = NULL;
	return (token);
}

/**
 * _getenvrmt - search the env't list to find the environment variable
 * @namev: name of the variable to find
 *
 * Return: pointer value of the env't variable/ NULL if not found
 */
char *_getenvrmt(const char *namev)
{
	extern char **environ;
	int i, j, len;

	if (namev == NULL)
		return (NULL);

	len = 0;
	while (namev[len])
		len++;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != namev[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}

	return (NULL);
}
