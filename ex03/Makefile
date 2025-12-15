NAME = Materia

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
 
SRC = main.cpp \
      AMateria.cpp \
      Character.cpp \
      Cure.cpp \
      Ice.cpp \
      MateriaSource.cpp \
      
      

INC = AMateria.h \
      Character.h \
      Cure.h \
      Ice.h \
      MateriaSource.h \
      ICharacter.h \
      IMateriaSource.h

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all