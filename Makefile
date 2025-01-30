# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: figarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 18:43:32 by figarcia          #+#    #+#              #
#    Updated: 2025/01/13 19:26:45 by figarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgetnextline.a
BONUS_NAME = libftgetnextline_bonus.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = get_next_line.h
BONUS_HEADER = get_next_line_bonus.h
SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
AR = ar rcs
RM = rm -f

ifdef BUFFER_SIZE
CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
endif


all: $(NAME)
	
bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(AR)	$(NAME)	$(OBJS)

$(BONUS_NAME): $(BONUS_OBJS)
	$(AR)	$(BONUS_NAME)	$(BONUS_OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC)	$(CFLAGS) -c $< -o $@

%.o: %.c $(BONUS_HEADER) Makefile
	$(CC)	$(CFLAGS) -c $< -o $@

clean:
	$(RM)	$(OBJS)	$(BONUS_OBJS)

fclean: clean
	$(RM)	$(NAME)	$(BONUS_NAME)

re: fclean all

.PHONY: clean fclean re all bonus
