# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 16:42:48 by umeneses          #+#    #+#              #
#    Updated: 2025/08/23 22:23:09 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				= \e[0;31m
GREEN  			= \e[0;32m
YELLOW 			= \e[0;33m
BLUE			= \e[0;34m
PURPLE			= \e[0;35m
CYAN   			= \e[0;36m
ORANGE			= \e[0;91m
MAGENT			= \e[0;95m
RESET  			= \e[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

SRC_DIR			:= ./src/
BUILD_DIR		:= ./build/
BIN_DIR			:= ./bin/
TESTS_DIR		:= ./tests/
LIBS_DIR		:= ./libs/
HEADERS_DIR		:= ./headers/

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

NAME			:= $(BIN_DIR)form
SRC_F			+= main.cpp
SRC_F			+= Bureaucrat.cpp
SRC_F			+= Form.cpp

SRC_F_ALL		:= $(addprefix $(SRC_DIR), $(SRC_F))
OBJ_F			:= $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.o, $(SRC_F_ALL))

TEST_NAME		:= $(BIN_DIR)run_tests
TEST_SRC_F		:= TestModule05Ex01.cpp
TEST_SRC_F_ALL	:= $(addprefix $(TESTS_DIR), $(TEST_SRC_F))
TEST_OBJ_F		:= $(patsubst $(TESTS_DIR)%.cpp, $(BUILD_DIR)%.o, $(TEST_SRC_F_ALL))
LIB_OBJ_F		:= $(filter-out $(BUILD_DIR)main.o, $(OBJ_F))
ALL_HEADERS		:= $(addprefix -I, $(HEADERS_DIR))

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM				:= rm -rf
MKDIR			:= mkdir -p
CP				:= cp -r
MV_OBJS			:= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR			:= umeneses
COMPILER		:= c++
FLAGS			:= -Wall -Wextra -Werror -Wshadow
LIMITATIONS		:= -std=c++98
GTEST_FLAGS		:= -lgtest -lgtest_main -pthread
DEBUG			:= -g3


# **************************************************************************** #
#								VARIABLE									   #
# **************************************************************************** #

define args_for_testing
	""
endef

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_F) | $(BIN_DIR)
	@printf "$(BLUE)Linking Objects      ->  $(notdir $@)\n$(RESET)"
	@$(COMPILER) $(FLAGS) $(LIMITATIONS) $(DEBUG) $^ -o $@
	@printf "$(GREEN)C++ Program Ready!\n\n$(RESET)"

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp | $(BUILD_DIR)
	@printf "$(CYAN)Compiling C++ Files  ->  $(YELLOW)$(notdir $@)\n$(RESET)"
	@$(COMPILER) $(FLAGS) $(LIMITATIONS) $(ALL_HEADERS) -c -o $@ $<

$(BUILD_DIR)%.o: $(TESTS_DIR)%.cpp | $(BUILD_DIR)
	@printf "$(CYAN)Compiling Test Files ->  $(YELLOW)$(notdir $@)\n$(RESET)"
	@$(COMPILER) $(FLAGS) $(LIMITATIONS) $(ALL_HEADERS) -c -o $@ $<

$(BUILD_DIR) $(BIN_DIR):
	@$(MKDIR) $@

.PHONY: clean
clean:
	@printf "$(RED)Objects Cleaning     ->	$(YELLOW)$(BUILD_DIR)\n"
	@$(RM) $(BUILD_DIR)
	@printf "$(RESET)"

.PHONY: fclean
fclean: clean
	@printf "$(RED)Full Cleaning        ->	$(YELLOW)$(BIN_DIR)\n"
	@$(RM) $(BIN_DIR)
	@printf "$(RESET)"

.PHONY: re
re:		fclean all
	@printf "$(PURPLE)::::::::::::::::::::: \n"
	@printf "$(CYAN)Program just rebuilt -> $(YELLOW)$(NAME)\n$(RESET)"

.PHONY: go
go:	all
	@./$(NAME)

.PHONY: val
val: all
	@valgrind --leak-check=full ./$(NAME) $(call args_for_testing)

.PHONY: test
test: $(TEST_NAME)
	@./$(TEST_NAME)

$(TEST_NAME): $(LIB_OBJ_F) $(TEST_OBJ_F) | $(BIN_DIR)
	@printf "$(BLUE)Linking Tests        ->  $(notdir $@)\n$(RESET)"
	@$(COMPILER) $(FLAGS) $(LIMITATIONS) $(DEBUG) $^ -o $@ $(GTEST_FLAGS)
