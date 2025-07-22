#include "minishell.h"

int	ft_expention(t_shell *mini)
{
	t_parce *parce;

	parce = mini->start;
	while (parce)
	{
		if (ft_check_dollar_sign(parce->str))
			ft_expend_it(parce);
		parce = parce->next;
	}
}

