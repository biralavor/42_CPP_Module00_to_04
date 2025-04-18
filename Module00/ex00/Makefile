# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 16:02:28 by umeneses          #+#    #+#              #
#    Updated: 2025/04/03 13:22:24 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
ORANGE			:= \033[0;91m
MAGENT			:= \033[0;95m
RESET			:= \033[0m


# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

SRC_DIR			:= ./src/
BUILD_DIR		:= ./build/
BIN_DIR			:= ./bin/
LIBS_DIR		:= ./libs/
HEADERS_DIR		:= ./headers/

GTEST_DIR		:= /usr/bin/googletest/
GTEST_LIB		:= /usr/lib/libgtest.a /usr/lib/libgtest_main.a

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

NAME			:= $(BIN_DIR)megaphone

SRC_F			= $(wildcard $(SRC_DIR)*.cpp)
OBJ_F			= $(wildcard $(SRC_DIR)%.cpp, $(BUILD_DIR)%.o, $(SRC_F))

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
FLAGS			:= -Wall -Wextra -Werror
LIMITATIONS		:= -std=c++98
DEBUG			:= -g3
ALL_HEADERS		:= -I$(HEADERS_DIR)

RM				:= rm -rf
MKDIR			:= mkdir -p

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(OBJ_F) | $(BIN_DIR)
				@echo "$(GREEN)Compiling C++ Files -> $(YELLOW)$(notdir $<)"
				@printf "$(RESET)"
				@$(COMPILER) $(FLAGS) $(LIMITATIONS) $(DEBUG) $^ -o $(NAME)
				@echo "$(GREEN)C++ Program Ready!$(RESET)"

$(BUILD_DIR)%.o:	$(SRC_DIR)%.cpp | $(BUILD_DIR)
	$(COMPILER) $(FLAGS) $(LIMITATIONS) $(ALL_HEADERS) -c -o $@ $<

$(BIN_DIR):
	@$(MKDIR) $(BIN_DIR)

clean:
	@$(RM) $(BUILD_DIR)
	@echo "$(RED)Cleaning -> $(YELLOW)$(BUILD_DIR)"
	@printf "$(RESET)"

fclean: clean
	@$(RM) $(BIN_DIR)
	@echo "$(RED)Cleaning -> $(YELLOW)$(BIN_DIR)"
	@printf "$(RESET)"

re:		fclean all
	@echo "$(PURPLE)>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "$(CYAN)Program just rebuilt -> $(YELLOW)$(NAME) $(RESET)"

go:	all
	@./$(NAME) $*

.PHONY: all clean fclean re go