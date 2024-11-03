# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 20:46:49 by shurtado          #+#    #+#              #
#    Updated: 2024/11/03 16:48:12 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Config
CC = cc
TARGET = push_swap
BONUS = checker
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR)
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/include
BNS_INCLUDES = -I$(BNS_INC_DIR) -I$(LIBFT_DIR)/include

# Debug
#CFLAGS += -g -O0
# Directory
SRC_DIR = src
BNS_SRC_DIR = src/bonus
OBJ_DIR = obj
BNS_OBJ_DIR = obj/bonus
INC_DIR = include
BNS_INC_DIR = include/bonus
LIB_DIR = lib

# Librarys
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source + obj
SRCS_FILES = push_swap.c check_args.c init_stacks.c swaps.c pushes.c rotates.c reverses.c sort.c cost.c new_sort.c move.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRCS_FILES))

# Bonus Source + Objs
BNS_SRCS_FILES = main_bonus.c check_args_bonus.c init_free.c
BNS_SRCS = $(addprefix $(BNS_SRC_DIR)/,$(BNS_SRCS_FILES))

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
BNS_OBJS = $(patsubst $(BNS_SRC_DIR)/%.c,$(BNS_OBJ_DIR)/%.o,$(BNS_SRCS))

# Main entrance
all: libft $(TARGET)

bonus: libft $(BONUS)

# Compile Checker
$(BONUS): $(BNS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BNS_INCLUDES) $(BNS_OBJS) $(LIBFT) $(LDFLAGS) -o $(BONUS)
	@echo "\033[1;36mBinary $@ created\033[0m"

# Compile Binary
$(TARGET): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(TARGET)
	@echo "\033[1;36mBinary $@ created\033[0m"


# -MMD to include header dependences to .d file and run $(OBJ_DIR) if not exist.make
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

$(BNS_OBJ_DIR)/%.o: $(BNS_SRC_DIR)/%.c Makefile | $(BNS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(BNS_INCLUDES) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(BNS_OBJ_DIR):
	@mkdir -p $(BNS_OBJ_DIR)

libft:
	@$(MAKE) --silent --no-print-directory -C $(LIBFT_DIR)

# Utils
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "\033[1;31mObjects deleted\033[0m"; \
	fi
	@$(MAKE) --silent --no-print-directory -C $(LIBFT_DIR) fclean

fclean: clean
	@if [ -f "$(TARGET)" ]; then \
		rm -f $(TARGET); \
		echo "\033[1;31m$(TARGET) deleted\033[0m"; \
	fi


re: fclean all

-include $(OBJS:.o=.d)
-include $(BNS_OBJS:.o=.d)

.PHONY: all clean fclean re
