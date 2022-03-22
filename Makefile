# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 13:38:20 by mdeclerf          #+#    #+#              #
#    Updated: 2021/08/10 15:23:20 by mdeclerf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	
CLIENT	=			client
SERVER	=			server
CLIENT_BONUS	=	client_bonus
SERVER_BONUS	=	server_bonus

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror 

INCLUDE = -I minitalk.h

SRCS_CLIENT	=		client.c		\
					utils.c			\
					utils_bis.c		\
					utils_ter.c		\

SRCS_SERVER	=		server.c					\
					server_sig_handler.c		\
					utils.c						\
					utils_bis.c					\

SRCS_CLIENT_BONUS	=	client_bonus.c			\
						client_bonus_message.c	\
						utils.c					\
						utils_bis.c				\
						utils_ter.c				\

SRCS_SERVER_BONUS	=	server_bonus.c				\
						server_bonus_sig_handler.c	\
						utils.c						\
						utils_bis.c					\
						utils_ter.c					\

OBJS_CLIENT	=			$(SRCS_CLIENT:.c=.o)
OBJS_SERVER	=			$(SRCS_SERVER:.c=.o)
OBJS_CLIENT_BONUS	=	$(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS	=	$(SRCS_SERVER_BONUS:.c=.o)

all :		$(CLIENT) $(SERVER)

$(NAME):	all

$(CLIENT):	$(OBJS_CLIENT)
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_CLIENT) -o $(CLIENT)

$(SERVER):	$(OBJS_SERVER)
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_SERVER) -o $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS):	$(OBJS_CLIENT_BONUS)
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_CLIENT_BONUS) -o $(CLIENT_BONUS)

$(SERVER_BONUS):	$(OBJS_SERVER_BONUS)
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_SERVER_BONUS) -o $(SERVER_BONUS)

clean:		
			@rm -f $(OBJS_CLIENT)
			@rm -f $(OBJS_SERVER)
			@rm -f $(OBJS_CLIENT_BONUS)
			@rm -f $(OBJS_SERVER_BONUS)
			
fclean:		clean
			@rm -f $(CLIENT)
			@rm -f $(SERVER)
			@rm -f $(CLIENT_BONUS)
			@rm -f $(SERVER_BONUS)

re:			fclean all