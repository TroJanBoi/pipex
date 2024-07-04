# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 19:05:16 by pesrisaw          #+#    #+#              #
#    Updated: 2024/07/02 23:06:05 by pesrisaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
# CFLAGS	= -Wextra -Wall -Werror -g
CFLAGS	= -g
LIBFT	= ./libft
PTF		= ./ft_printf

HEADERS	= -I $(LIBFT) -I $(PTF)

SRCS	=	pipex.c \
			ft_error.c

OBJS	= ${SRCS:.c=.o}

all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME) -L. $(LIBFT)/libft.a

%.o: %.c $(HEADER_FILE)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)  && printf "Compiling: $(notdir $<)"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re