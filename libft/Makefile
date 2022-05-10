NAME = libft.a

FILES = ft_itoa.c ft_putnbr_fd.c ft_strmapi.c ft_atoi.c ft_memccpy.c ft_putstr_fd.c ft_strncmp.c ft_bzero.c ft_memchr.c ft_split.c ft_strnstr.c ft_calloc.c ft_memcmp.c ft_strchr.c ft_strrchr.c ft_isalnum.c ft_memcpy.c ft_strdup.c ft_strtrim.c ft_isalpha.c ft_memmove.c ft_strjoin.c ft_substr.c ft_isascii.c ft_memset.c ft_strlcat.c ft_tolower.c ft_isdigit.c ft_putchar_fd.c ft_strlcpy.c ft_toupper.c ft_isprint.c ft_putendl_fd.c ft_strlen.c ft_utoa.c ft_strldup.c ft_ultoa_base.c ft_utoa_base.c get_next_line.c free_malloc_2d.c

FILESBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c

OBJS = $(FILES:.c=.o)

OBJSBONUS = $(FILESBONUS:.c=.o)

.c.o: $(FILES)
	gcc -c -Wall -Wextra -Werror $(FILES)

.c.o2: $(FILESBONUS)
	gcc -c -Wall -Wextra -Werror $(FILES)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)
	
bonus: $(OBJSBONUS) $(OBJS)
	ar rc $(NAME) $(OBJS) $(OBJSBONUS)
	ranlib $(NAME)

clean :
	rm -f $(OBJS) $(OBJSBONUS)

fclean : clean 
	rm -f $(NAME)

re : fclean 
	make all

.PHONY: re fclean clean all bonus
