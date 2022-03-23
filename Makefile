NAME		:=	philo

# Directories
INCL_DIR	:=	-I./includes
SRCS_DIR	:=	sources
OBJS_DIR	:=	objects
TEST_DIR	:=	tester
VPATH		:=	$(subst $(space),:,$(shell find $(SRCS_DIR) -type d))

# Sources and objects
MAIN		:=	main.c
export SRCS	:= 	philosophers.c \
				init_all.c \
				play_game.c \
				time.c \
				philo_utils.c \
				philo_eat.c \
				ft_putendl_fd.c \
				ft_calloc.c \
			  	ft_atoi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_bzero.c \
				ft_check_malloc.c \
				ft_strlen.c \
				ft_isdigit.c \
				ft_strlcpy.c \
				ft_free_char_array.c
ALL_SRCS	:=	$(MAIN) $(SRCS)
ALL_OBJS	:=	$(addprefix $(OBJS_DIR)/, $(ALL_SRCS:.c=.o))

# Config
ifdef debug
	FLAGS	:=	-Wall -Wextra -g3 -fsanitize=address
	COMPILE	:=	clang -c
	LINK	:=	clang
else
ifdef thread
	FLAGS	:=	-Wall -Wextra -g3 -fsanitize=thread
	COMPILE	:=	gcc -c
	LINK	:=	gcc
else
	FLAGS	:=	-Wall -Wextra -Werror -g3
	COMPILE	:=	gcc -c
	LINK	:=	gcc
endif
endif

# Config
all: $(NAME)

$(NAME): $(OBJS_DIR) $(ALL_OBJS)
	$(LINK) $(FLAGS) $(ALL_OBJS) -o $@

$(OBJS_DIR)/%.o: %.c
	$(COMPILE) $(FLAGS) $< $(INCL_DIR) -o $@	

run: all
	./$(NAME)

drun: all
	lldb $(NAME)

test: $(OBJS_DIR) $(ALL_OBJS)
	$(MAKE) -C $(TEST_DIR) test
	$(MAKE) -C $(TEST_DIR) runtest

dtest: fclean all $(OBJS_DIR) $(ALL_OBJS)
	$(MAKE) -C $(TEST_DIR) test
	$(MAKE) -C $(TEST_DIR) dtest

$(OBJS_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(TEST_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re


