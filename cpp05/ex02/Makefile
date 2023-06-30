NAME = bureaucrat

SRCS = main.cpp ShrubberyCreationForm.cpp \
	   Bureaucrat.cpp PresidentialPardonForm.cpp AForm.cpp RobotomyRequestForm.cpp

CPP = c++

CXXFLAGS  = -std=c++98 -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: clean all
