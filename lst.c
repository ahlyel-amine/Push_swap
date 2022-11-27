#include "push_swap.h"
#include "libft.h"

t_lst	*ft_lstnew(int	nbr, t_lst *next, t_lst *prev)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (!list)
		return (NULL);
	list->content = nbr;
	list->next = next;
	list->prev = prev;
	return	(list);
}

t_lst	*ft_lstlast(t_lst *list)
{
	while (list->next)
		list = list->next;
	return	(list);
}

t_lst	*ft_lstfirst(t_lst *list)
{
	while (list->prev)
		list = list->prev;
	return	(list);
}

void	ft_addfront(t_lst **list, t_lst *new)
{
	*list = ft_lstfirst(*list);
	(*list)->prev = new;
	new->next = *list;
	*list = new;
}

void	ft_addback(t_lst **list, t_lst *new)
{
	*list = ft_lstlast(*list);
	(new)->prev = *list;
	(*list)->next = new;
}
