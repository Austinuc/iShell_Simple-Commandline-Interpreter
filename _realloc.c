#include "main.h"

/**
  * _realloc - Reallocates a memory block using malloc and free
  * @ptr: pointer to memory previously allocated
  * @old_size: size in bytes of allocated space for ptr
  * @new_size: new size in bytes of the new memory block
  *
  * Return: pointer to the new reallocated array
  */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = (char *)ptr, *new_ptr;
	unsigned int i = 0;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
		{
			free(ptr);
			return (NULL);
		}
		return (ptr);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(ptr), free(new_ptr);
		return (NULL);
	}
	if (p)
	{
		while (i < old_size)
		{
			*(new_ptr + i) = p[i];
			i++;
		}
	}
	free(ptr);
	return (new_ptr);
}
