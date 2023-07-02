NAME = phonebook

SRCS = 	Contact.cpp \
		Phonebook.cpp	\
		main.cpp

CPP = c++

FLAGS  = -std=c++98 -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: clean all