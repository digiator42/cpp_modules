NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp

CXX = c++

CXXFLAGS  = -std=c++98 -Wall -Wextra -Werror -g3 -fsanitize=address #-D PRINT=1

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: clean all
