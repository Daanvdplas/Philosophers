# include "tester.h"

static void	run_all_tests(void)
{
	RUN_TEST_GROUP(test_input);
}

int	main(int argc, const char **argv)
{
	return (UnityMain(argc, argv, run_all_tests));
}

