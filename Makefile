# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akadi <akadi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 20:12:39 by akadi             #+#    #+#              #
#    Updated: 2022/03/01 16:39:39 by akadi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk.a
cc = cc
flags = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
csrc = client.c Minitalk_utils.c
ssrc = server.c Minitalk_utils.c
csrcbonus = client_bonus.c Minitalk_utils.c
ssrcbonus = server_bonus.c Minitalk_utils.c
cobj = $(csrc:.c=.o)
sobj = $(ssrc:.c=.o)
cobjbonus = $(csrcbonus:.c=.o)
sobjbonus = $(ssrcbonus:.c=.o)

all : $(NAME)
	@echo "\033[0;94m\
			███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n\
			████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n\
			██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n\
			██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n\
			██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n\
			╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n\033[0m"

$(NAME) : $(cobj) $(sobj)
	$(cc) $(flags) $(csrc) -o $(CLIENT)
	$(cc) $(flags) $(ssrc) -o $(SERVER)
	ar -rc $(NAME) $(cobj) $(sobj)
%.o : %.c Minitalk.h
	$(cc) $(flags) -c $< -o $@

bonus : $(NAME) $(cobj) $(cobjbonus) $(sobj) $(sobjbonus)
	$(cc) $(flags) $(csrcbonus) -o client_bonus
	$(cc) $(flags) $(ssrcbonus) -o server_bonus
	ar -rc $(NAME) $(cobj) $(cobjbonus) $(sobj) $(sobjbonus)
clean :
	rm -rf $(cobj) $(cobjbonus) $(sobj) $(sobjbonus) 
fclean : clean
	rm -rf $(NAME) $(CLIENT) $(SERVER) client_bonus server_bonus
re : fclean all

.PHONY : all fclean clean re bonus
