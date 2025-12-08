

Name = Animal

CPP = c++ -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp 


OBJ = ${SRC:.cpp=.o}

${NAME} : ${OBJ}
	${CPP} ${OBJ} -o $@


%.o:%.cpp Cat.h Dog.h Animal.h
	${CPP}  -c $< -o $@

clean :
	rm -f ${OBJ}

fclean: clean 
	rm -f ${NAME}

re : fclean all 
