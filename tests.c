#include "push_swap.h"

///tests
void	print_stack(t_stacks stacks)
{
printf("stack_a :\n");
t_list *tmp = NULL;
	if (stacks.stack_a)
		tmp = stacks.stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("stack_b :\n");
	if (stacks.stack_b)
	tmp = stacks.stack_b;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
///////

void	print_list(t_list *stack)
{
printf("stack_a :\n");
t_list *tmp = NULL;
	if (stack)
		tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
///


