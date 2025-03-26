#include "push_swap.h"
#include <strings.h>

///tests
void	print_stacks(t_stacks stacks)
{
printf("stack_a :\n");
t_list *tmp = NULL;
	if (stacks.stack_a)
		tmp = stacks.stack_a;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("stack_b :\n");
	if (stacks.stack_b)
	tmp = stacks.stack_b;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("operations :\n");
	if (stacks.operations)
	tmp = stacks.operations;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}
///////

// void	print_list(t_list *stack)
// {
// 	t_list	*tmp;

// 	tmp = NULL;

// 	if (stack)
// 		tmp = stack;
// 	while (tmp)
// 	{
// 		// printf("hello %s", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// }

