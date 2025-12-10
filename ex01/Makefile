NAME = Animal  

CPP = c++ -Wall -Wextra -Werror -std=c++98


SRC = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp  Brain.cpp

OBJ = ${SRC:.cpp=.o}

all: ${NAME} 

${NAME} : ${OBJ}
	${CPP} ${OBJ} -o $@


%.o:%.cpp Animal.h Cat.h Dog.h WrongAnimal.h WrongCat.h Brain.h
	${CPP} -c $< -o $@

clean :
	rm -f ${OBJ}

fclean: clean 
	rm -f ${NAME}

re : fclean all