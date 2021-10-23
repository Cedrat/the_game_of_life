NAME = game_of_life
VPATH =objs:./srcs

SRCS = main.cpp LifeGame.cpp convert_pos_1d_in_2d.cpp

PATH_OBJS = ./.objs/
OBJS = $(addprefix ${PATH_OBJS},${SRCS:.cpp=.o})

CXX= clang++

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(PATH_OBJS)%.o : %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

all : 		${PATH_OBJS} ${NAME} 

${NAME}:	${OBJS} 
			$(CXX)  -o ${NAME} ${CFLAGS} ${OBJS} 
			@echo "\n\033[032;1mexample of use : ./game_of_life [width height][percent of empty cells][frame per second]\033[0m\n"

clean :		
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all

${PATH_OBJS}:
	mkdir -p $@

.PHONY : all clean fclean re