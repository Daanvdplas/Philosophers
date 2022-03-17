#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Sorry, you gave too little arguments", 2);
		return (EXIT_FAILURE);
	}
	else if (argc == 5 || argc == 6)
	{
		if (philosophers(argv))
		{
			ft_putendl_fd("Sorry, you gave incorrect arguments", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

