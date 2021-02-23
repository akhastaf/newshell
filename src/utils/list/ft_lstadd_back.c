#include "../../include/minishell.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (temp)
	{
		temp = ft_lstlast(temp);
		(temp)->next = new;
		new->prev = temp;
	}
	else
		*alst = new;
}