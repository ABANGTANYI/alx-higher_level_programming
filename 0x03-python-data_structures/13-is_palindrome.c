#include "lists.h"
#include <stdlib.h>

void reverse_list(listint_t **head);
int compare_lists(listint_t *head1, listint_t *head2);

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to the head of listint_t
 * @n: integer to add in listint_t list
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * is_palindrome - identifies if a single linked list is palindrome
 * @head: double pointer to the head of listint_t
 * Return: 1 if it is a palindrome, else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow_ptr = *head, *fast_ptr = *head;
	listint_t *prev_slow_ptr = NULL;
	listint_t *second_half = NULL, *mid_node = NULL;
	int is_palindrome = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (is_palindrome);

	while (fast_ptr != NULL && fast_ptr->next != NULL)
	{
		fast_ptr = fast_ptr->next->next;
		prev_slow_ptr = slow_ptr;
		slow_ptr = slow_ptr->next;
	}

	if (fast_ptr != NULL)
	{
		mid_node = slow_ptr;
		slow_ptr = slow_ptr->next;
	}

	second_half = slow_ptr;
	prev_slow_ptr->next = NULL;
	reverse_list(&second_half);
	is_palindrome = compare_lists(*head, second_half);
	reverse_list(&second_half);

	if (mid_node != NULL)
	{
		prev_slow_ptr->next = mid_node;
		mid_node->next = second_half;
	}
	else
		prev_slow_ptr->next = second_half;

	return (is_palindrome);
}

/**
 * reverse_list - reverses a listint_t list
 * @head: double pointer to the head of listint_t
 */
void reverse_list(listint_t **head)
{
	listint_t *prev_node = NULL;
	listint_t *current_node = *head;
	listint_t *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
		current_node = next_node;
	}

	*head = prev_node;
}

/**
 * compare_lists - compares two listint_t lists
 * @head1: pointer to the head of the first list
 * @head2: pointer to the head of the second list
 * Return: 1 if the lists are identical, else 0
 */
int compare_lists(listint_t *head1, listint_t *head2)
{
	listint_t *temp1 = head1;
	listint_t *temp2 = head2;

	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return (0);
	}

	if (temp1 == NULL && temp2 == NULL)
		return (1);

	return (0);
}
