
CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC1 = client.c ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c
SRC2 = server.c ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c


OUT1 = client
OUT2 = server

all: $(OUT1) $(OUT2)


$(OUT1): $(SRC1)
	$(CC) $(CFLAGS) -o $(OUT1) $(SRC1)


$(OUT2): $(SRC2)
	$(CC) $(CFLAGS) -o $(OUT2) $(SRC2)


clean:
	rm -f $(OUT1) $(OUT2) 
