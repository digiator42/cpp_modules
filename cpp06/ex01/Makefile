NAME = serialize

SRCS = serialize.cpp main.cpp

CXX = c++

CFLAGS  = -std=c++98 -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: clean all
