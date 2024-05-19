#include "push_swap.h"

void	print_stack(t_ps *top)
{
	t_ps	*current = top;

	printf("stack:\n");
	while (current != NULL)
	{
		printf("{%d} ptr:%p->next:%p\n", current->value, current, current->next);
		current = current->next;
	}
}