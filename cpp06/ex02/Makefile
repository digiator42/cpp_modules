NAME = convertor

SRCS = dynamic.cpp main.cpp

CXX = c++

CXXFLAGS  = -std=c++98 -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: clean all
