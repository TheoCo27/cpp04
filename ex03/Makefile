# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 17:42:10 by tcohen            #+#    #+#              #
#    Updated: 2025/02/21 18:24:34 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -g3
SRCS =	src/AMateria.cpp src/Cure.cpp src/Character.cpp src/MateriaSource.cpp src/Ice.cpp src/main.cpp \
		#src/IMateriaSource.cpp src/ICharacter.cpp
OBJDIR = obj
OBJS = $(SRCS:src/%.cpp=$(OBJDIR)/%.o)
NAME = Materia

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compilation des fichiers objets
$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJDIR)

# Nettoyage complet (obj + binaire)
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
