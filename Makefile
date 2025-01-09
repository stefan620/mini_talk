
CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC1 = client.c ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_memcpy.c
SRC1_BONUS = client_bonus.c ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_memcpy.c
SRC2 = server.c ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_memcpy.c
SRC2_BONUS = server_bonus.c ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_memcpy.c
OBJ1 = $(SRC1:.c=.o)
OBJ1_BONUS = $(SRC1_BONUS:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ2_BONUS = $(SRC2_BONUS:.c=.o)


OUT1 = client
OUT2 = server
OUT1_BONUS = client_bonus
OUT2_BONUS = server_bonus

all: $(OUT1) $(OUT2)

bonus: $(OUT1_BONUS) $(OUT2_BONUS)


$(OUT1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(OUT1) $(OBJ1)

$(OUT1_BONUS): $(OBJ1_BONUS)
	$(CC) $(CFLAGS) -o $(OUT1_BONUS) $(OBJ1_BONUS)


$(OUT2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(OUT2) $(OBJ2)

$(OUT2_BONUS): $(OBJ2_BONUS)
	$(CC) $(CFLAGS) -o $(OUT2_BONUS) $(OBJ2_BONUS)

clean: 
	rm -f $(OBJ1) $(OBJ2) $(OBJ1_BONUS) $(OBJ2_BONUS)

fclean: clean
		rm -f $(OUT1) $(OUT2) $(OUT1_BONUS) $(OUT2_BONUS)
	
.PHONY: all clean fclean bonus
