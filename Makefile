# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamarti <mamarti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 09:05:06 by mamarti           #+#    #+#              #
#    Updated: 2026/01/29 12:34:56 by mamarti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S		=	$(shell uname -s)

ifeq			($(UNAME_S), Linux)
MLX_DIR		=	minilibx-linux
MLX			=	$(MLX_DIR)/libmlx.a
LDFLAGS		=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm
CFLAGS 		+= -D__linux__
else ifeq		($(UNAME_S), Darwin)
MLX_DIR		=	minilibx-opengl
MLX			=	$(MLX_DIR)/libmlx.a
LDFLAGS		=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
else
MLX_DIR		=	minilibx-linux
MLX			=	$(MLX_DIR)/libmlx.a
LDFLAGS		= 	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm
$(warning OS non reconnu, utilisation des flags Linux par défaut.)
endif

SRC			=	main.c map.c map_loader.c map_utils.c  map_checker.c \
				path_checker.c game_loader.c game_utils.c textures_utils.c \
				handle_error.c render_utils.c handle_move.c

SRCBS		=	main_bonus.c map_bonus.c map_loader_bonus.c map_utils_bonus.c \
				map_checker_bonus.c path_checker_bonus.c game_loader_bonus.c \
				game_utils_bonus.c textures_utils_bonus.c handle_error_bonus.c \
				render_utils_bonus.c handle_move_bonus.c anim_utils_bonus.c \
				render_bonus.c mobs_utils_bonus.c

SRC_DIR			=	src
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
SRCBS_DIR	=	bonus/src
SRCSBS		=	$(addprefix $(SRCBS_DIR)/, $(SRCBS))
OBJ_DIR		=	objs
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJSBS		=	$(addprefix $(OBJ_DIR)/, $(SRCBS:.c=.o))
DEPS		=	$(OBJS:.o=.d)
DEPSBS		=	$(OBJSBS:.o=.d)
NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iinclude -MMD -MP
LIBFT		=	libft/libft.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRCBS_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

GREEN = \033[38;2;41;169;41m
BLUE = \033[38;2;119;181;254m
CYAN = \033[38;2;43;250;250m
RED = \033[38;2;234;66;88m
PURPLE = \033[38;2;159;83;236m
YELLOW = \033[38;2;236;236;83m
BROWN = \033[38;2;113;66;25m
NC = \033[0m

define ECHO_SUCCESS
	@echo "\n         $(YELLOW)*$(NC)"
	@echo "        $(GREEN)###$(NC)"
	@echo "       $(GREEN)###$(RED)O$(GREEN)#$(NC)"
	@echo "      $(GREEN)#######$(NC)"
	@echo "     $(GREEN)##$(PURPLE)O$(GREEN)####$(BLUE)O$(GREEN)#$(NC)"
	@echo "    $(GREEN)######$(CYAN)O$(GREEN)####$(NC)"
	@echo "   $(GREEN)#$(BLUE)O$(GREEN)#########$(RED)O$(GREEN)#$(NC)"
	@echo "  $(GREEN)###############$(NC)"
	@echo "  $(BROWN)      |||$(NC)"
	@echo "\n$(GREEN)[so_long] Compilation success!$(NC)"
	@echo "$(GREEN)Usage: ./so_long [map_file.ber]$(NC)"
endef

all:			$(NAME)

$(MLX):
				$(MAKE) -C $(MLX_DIR)

$(LIBFT):
				$(MAKE)	-C libft

$(NAME):		$(LIBFT) $(MLX) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)
				$(ECHO_SUCCESS)

bonus:			$(LIBFT) $(MLX) $(OBJSBS)
				$(CC) $(CFLAGS) $(OBJSBS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)
				$(ECHO_SUCCESS)

clean:
				rm -rf $(OBJ_DIR)
				$(MAKE) -C libft clean
				$(MAKE) -C $(MLX_DIR) clean

fclean:			clean
				rm -f $(NAME)
				$(MAKE) -C libft fclean

re:				fclean all

.PHONY:			all clean fclean re bonus

-include $(DEPS)
-include $(DEPSBS)
