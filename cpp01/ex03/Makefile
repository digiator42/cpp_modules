NAME = attack

SRCS = 	HumanA.cpp	HumanB.cpp	Weapon.cpp	main.cpp	\

CPP = c++

CXXFLAGS  = -std=c++98 -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: clean all