# include "tester.h"

t_rules	*rules;
char	**arguments;

TEST_GROUP (test_input);

static char	**make_argv(char *one, char *two, char *three, char *four, char *five)
{
	char	**argv;
	int		len;

	argv = (char **)malloc(7 * sizeof(char *));
	ft_check_malloc(argv, "make_argv");
	argv[0] = (char *)malloc(6 * sizeof(char));
	ft_check_malloc(argv, "make_argv");
	ft_strlcpy(argv[0], "philo", 6);
	len = ft_strlen(one);
	argv[1] = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(argv[1], one, len + 1);
	len = ft_strlen(two);
	argv[2] = (char *)malloc(len + 1 * sizeof(char));
	ft_strlcpy(argv[2], two, len + 1);
	len = ft_strlen(three);
	argv[3] = (char *)malloc(len + 1 * sizeof(char));
	ft_strlcpy(argv[3], three, len + 1);
	len = ft_strlen(four);
	argv[4] = (char *)malloc(len + 1 * sizeof(char));
	ft_strlcpy(argv[4], four, len + 1);
	if (five)
	{
		len = ft_strlen(five);
		argv[5] = (char *)malloc(len + 1 * sizeof(char));
		ft_strlcpy(argv[5], five, len + 1);
	}
	else
		argv[5] = NULL;
	argv[6] = NULL;
	return (argv);
}

static void	init_test(char *one, char *two, char *three, char *four, char *five)
{
	rules = malloc(sizeof(t_rules));
	ft_check_malloc(rules, "init_test");
	arguments = make_argv(one, two, three, four, five);
	ft_check_malloc(arguments, "TEST_SETUP");
	rules = init_all(arguments);
}

static void	test_shitandforks(int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		TEST_ASSERT_EQUAL_INT(i + 1, rules->philo[i].id);
		TEST_ASSERT_EQUAL_INT(0, rules->philo[i].x_eaten);
		TEST_ASSERT_EQUAL_INT(i + 1, rules->philo[i].left_fork);
		TEST_ASSERT_EQUAL_INT((i + 1) % (rules->nbr_of_philo + 1), rules->philo[i].right_fork);
		TEST_ASSERT_EQUAL_INT(0, rules->philo[i].last_meal);
		TEST_ASSERT_NOT_NULL(rules->philo[i].rules);
		i++;
	}
}

TEST_SETUP(test_input)
{
}

TEST_TEAR_DOWN(test_input)
{
	ft_free_char_array(arguments);
	free(rules);
}

TEST(test_input, test1)
{
	init_test("5", "2", "4", "40", "44");
	TEST_ASSERT_NOT_NULL(rules);
	TEST_ASSERT_EQUAL_INT(5, rules->nbr_of_philo);
	TEST_ASSERT_EQUAL_INT(2, rules->time_to_die);
	TEST_ASSERT_EQUAL_INT(4, rules->time_to_eat);
	TEST_ASSERT_EQUAL_INT(40, rules->time_to_sleep);
	TEST_ASSERT_EQUAL_INT(44, rules->nbr_of_meals);
	test_shitandforks(rules->nbr_of_philo);
}

TEST(test_input, test2)
{
	init_test("21212", "3522", "203", "40", NULL);
	TEST_ASSERT_NULL(rules);
}

TEST(test_input, test3)
{
	init_test("error", "3522", "203", "40", NULL);
	TEST_ASSERT_NULL(rules);
}

TEST(test_input, test4)
{
	init_test("30249", "3522", "203", "40", "-2");
	TEST_ASSERT_NULL(rules);
}

TEST(test_input, test5)
{
	init_test("200error", "3522", "203", "40", "34");
	TEST_ASSERT_NULL(rules);
}

TEST(test_input, test6)
{
	init_test("123", "232", "42", "404", NULL);
	TEST_ASSERT_NOT_NULL(rules);
	TEST_ASSERT_EQUAL_INT(123, rules->nbr_of_philo);
	TEST_ASSERT_EQUAL_INT(232, rules->time_to_die);
	TEST_ASSERT_EQUAL_INT(42, rules->time_to_eat);
	TEST_ASSERT_EQUAL_INT(404, rules->time_to_sleep);
	TEST_ASSERT_EQUAL_INT(-2, rules->nbr_of_meals);
	test_shitandforks(rules->nbr_of_philo);
}


TEST_GROUP_RUNNER(test_input)
{
	RUN_TEST_CASE(test_input, test1);
	RUN_TEST_CASE(test_input, test2);
	RUN_TEST_CASE(test_input, test3);
	RUN_TEST_CASE(test_input, test4);
	RUN_TEST_CASE(test_input, test5);
	RUN_TEST_CASE(test_input, test6);
}

