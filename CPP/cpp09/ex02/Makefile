# **************************************************************************** #
#                                    Makefile                                 #
# **************************************************************************** #

NAME    = PmergeMe
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM      = rm -f

SRCS    = main.cpp PmergeMe.cpp
OBJS    = $(SRCS:.cpp=.o)
DEPS    = PmergeMe.hpp

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
