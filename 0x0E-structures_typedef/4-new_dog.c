#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - creates new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: a dog object
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int i, a1, a2;
	dog_t *nedog;
	char *b, *c;

	a1 = 0;
	for (i = 0; name[i] != '\0'; i++)
		a1++;
	a2 = 0;
	for (i = 0; owner[i] != '\0'; i++)
		a2++;
	nedog = malloc(sizeof(dog_t));
	if (nedog == NULL)
		return (NULL);
	b = malloc((a1 + 1) * sizeof(char));
	if (b == NULL)
	{
		free(nedog);
		return (NULL);
	}
	for (i = 0; i < a1; i++)
		b[i] = name[i];
	b[i] = '\0';
	nedog->name = b;
	nedog->age = age;
	c = malloc((a2 + 1) * sizeof(char));
	if (c == NULL)
	{
		free(b);
		free(nedog);
		return (NULL);
	}
	for (i = 0; i < a2; i++)
		c[i] = owner[i];
	c[i] = '\0';
	nedog->owner = c;
	return (nedog);
}
