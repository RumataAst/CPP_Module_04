# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akretov <akretov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 16:15:06 by akretov           #+#    #+#              #
#    Updated: 2025/01/17 16:57:18 by akretov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= BraiiiiiiinnnzzzZ
SRCS    := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
BIN		:= bin
OBJS    := $(addprefix $(BIN)/, $(SRCS:.cpp=.o))
INC		:= include

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I${INC}

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BIN)/%.o: %.cpp | $(BIN)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN):
	+@mkdir $(BIN)

clean:
	@rm -rf $(BIN)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
