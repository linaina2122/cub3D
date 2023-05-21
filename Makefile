# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 02:58:29 by bkamal            #+#    #+#              #
#    Updated: 2023/05/20 14:20:12 by hcharef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = cub3D
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -fsanitize=address -g3
 
# PRSDIR   = sources/parsing
2DMDIR	 = sources/2Dmap
OBJDIR   = objects
INCDIR   = includes

# SRCP	 = error_checks.c
SRC2	 = main.c\
			draw.c\
			file.c\
			myfun.c\
			mouvements.c\
			utils.c\
			castray.c\
			3d.c\
			mlx_func.c
# OBJP     = $(addprefix $(OBJDIR)/,$(notdir $(SRCP:.c=.o)))
OBJ2D    = $(addprefix $(OBJDIR)/,$(notdir $(SRC2:.c=.o)))
INC		 = -I$(INCDIR)

#NEEDED FOR MLX FUNCTIONS
#2DMAP AND 3DWALLS/VISION
MLX		 = -lmlx -framework OpenGL -framework AppKit

RM       = rm -rf

ARG		 = ./maps/map1.cub

all: $(NAME)

# $(OBJDIR)/%.o: $(PRSDIR)/%.c $(2DMDIR)/%.c | $(OBJDIR)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

#2DMAP
$(OBJDIR)/%.o: $(2DMDIR)/%.c | $(OBJDIR)
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@
	@ echo "Compiling object files..."

# PARSING
# $(NAME): $(OBJP)
# 	@ $(MAKE) -C ./libft/
# 	$(CC) $(CFLAGS) $(OBJP) ./libft/libft.a -o $(NAME)

# 2DMAP
$(NAME): $(OBJ2D)
	@ $(MAKE) -C ./libft/
	@ $(CC) $(CFLAGS) $(OBJ2D) $(MLX) ./libft/libft.a -o $(NAME)


$(OBJDIR):
	@ mkdir -p $@

clean:
	@ $(RM) $(OBJDIR)
	@ $(MAKE) -C ./libft/ clean

fclean:	clean
	@ $(RM) $(NAME)
	@ $(MAKE) -C ./libft/ fclean

re:		fclean all

ARG		 = ./maps/map1.cub
run: re
	./cub3D

# Convenient for parsing and later on 
# $(ARG)

.PHONY: all clean fclean re