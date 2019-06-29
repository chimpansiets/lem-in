# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vmulder <vmulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:18:40 by vmulder        #+#    #+#                 #
#    Updated: 2019/06/29 18:50:49 by vmulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
C      = gcc
FLAGS  = -g -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = lem-in

### INCLUDES ###
LIBFT  = libft
OBJ_PATH  = objs
HEADER = incl
SRC_PATH  = srcs

### SOURCES ###
SOURCES = main.c input.c

### OBJECTS ###
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### RULES ###
all: $(NAME)

$(NAME):
	@make -C ./libft
	@$(CC) $(SRCS) -I $(HEADER) $(FLAGS) -L $(LIBFT) -lft -o $@ $^
	@echo "Project successfully compiled"

##tmp:
##	@mkdir -p objs

##$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
##	@$(CC) $(FLAGS) -I $(HEADER) -c -g -o $@ $<

clean:
	@echo "Cleaning..."
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "Fcleaning..."
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean