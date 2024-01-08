# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:45:55 by amakhrou          #+#    #+#              #
#    Updated: 2024/01/02 18:14:42 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BS = cub3D_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -I headers/

SRCS = mandatory/parse/ft_split.c mandatory/parse/read.c mandatory/main.c mandatory/parse/utilis1.c mandatory/parse/init.c mandatory/parse/utilis.c mandatory/parse/map_elements.c \
		mandatory/parse/check_map.c mandatory/parse/parse.c mandatory/parse/rgb.c mandatory/parse/get_next_line/get_next_line.c mandatory/parse/get_next_line/get_next_line_utils.c \
		mandatory/raycasting/get_coordinate.c mandatory/raycasting/draw.c mandatory/raycasting/castrays.c mandatory/raycasting/init_structs.c \
		mandatory/raycasting/keys.c mandatory/raycasting/moves.c mandatory/raycasting/castrays2.c mandatory/raycasting/norme.c

SRCS_BS = bonus/parse/ft_split.c bonus/parse/read.c bonus/main.c bonus/parse/utilis1.c bonus/parse/init.c bonus/parse/utilis.c bonus/parse/map_elements.c bonus/parse/check_map.c \
		bonus/parse/parse.c bonus/parse/rgb.c bonus/parse/get_next_line/get_next_line.c bonus/parse/get_next_line/get_next_line_utils.c \
		bonus/raycasting/get_coordinate.c bonus/raycasting/draw.c bonus/raycasting/castrays.c bonus/raycasting/init_structs.c \
		bonus/raycasting/mouse_moves.c bonus/raycasting/keys.c bonus/raycasting/moves.c bonus/raycasting/castrays2.c bonus/raycasting/norme.c

OBJS = $(SRCS:.c=.o)

OBJS_BS = $(SRCS_BS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


bonus: $(NAME_BS)

$(NAME_BS): $(OBJS_BS)
		$(CC) $(CFLAGS) $(OBJS_BS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BS)

re: fclean all