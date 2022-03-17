#  directories
INCL_DIR	:=	-I../includes
UNITY_DIR	:=	unity
VPATH		:=	$(subst $(space),:,$(shell find $(UNITY_DIR) -type d))

# Test sources
TEST_SRCS	:=	test.c \
				init_tester.c \
				$(UNITY_DIR)/src/unity.c \
				$(UNITY_DIR)/extras/fixture/src/unity_fixture.c
				
# Test includes
TEST_INCL	:=	-D UNITY_OUTPUT_COLOR \
				-D UNITY_FIXTURE_NO_EXTRAS \
				-I./unity/src \
				-I./unity/extras/fixture/src \
				-I../includes \
				-I./tester.h
				
# Test objects
OBJS_DIR	:=	../objects
T_OBJS_DIR	:=	../objects/test_objects
PHILO_OBJS	:=	$(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
TEST_OBJS	:=	$(addprefix $(T_OBJS_DIR)/, $(notdir $(TEST_SRCS:.c=.o)))

# Test results
EXECUTOR	:=	tester

# Config
ifdef debug
	FLAGS	:=	-Wall -Wextra -g3 -fsanitize=address
	COMPILE :=	clang -c
	LINK	:=	clang
else
ifdef leaks
	FLAGS	:= 	-Wall -Wextra -g3 -fsanitize=address
	COMPILE	:=	gcc -c
	LINK	:=	gcc
else
	FLAGS	:=	-Wall -Wextra -Werror -g3
	COMPILE	:= 	gcc -c
	LINK	:= 	gcc
endif
endif

# Config
test: $(EXECUTOR)	

$(EXECUTOR): $(T_OBJS_DIR) $(TEST_OBJS)
	$(LINK) $(FLAGS) $(TEST_OBJS) $(PHILO_OBJS) -o $@

$(T_OBJS_DIR)/%.o: %.c 
	$(COMPILE) $(FLAGS) $< $(TEST_INCL) -o $@

$(T_OBJS_DIR):
	mkdir -p $@

runtest:
	./$(EXECUTOR)

dtest:
	lldb $(EXECUTOR)

fclean:
	rm -f $(EXECUTOR)

.PHONY: test runtest fclean
