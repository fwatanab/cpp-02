NAME	= lesson

SRC		= main.cpp FixedPoint.cpp

OBJS	= $(SRC:.cpp=.o)

CXX			= c++
CXXFLAGS	= -std=c++98
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all
