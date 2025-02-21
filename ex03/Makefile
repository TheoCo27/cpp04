# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 17:42:10 by tcohen            #+#    #+#              #
#    Updated: 2025/02/21 21:35:05 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -g3
SRCS =	src/AMateria.cpp src/Cure.cpp src/Character.cpp src/MateriaSource.cpp src/Ice.cpp src/main.cpp \
		src/IMateriaSource.cpp src/ICharacter.cpp
SRCS_PRINT = src_print/AMateria.cpp src_print/Character.cpp src_print/Cure.cpp src_print/Ice.cpp \
		src_print/ICharacter.cpp src_print/IMateriaSource.cpp src_print/main.cpp src_print/MateriaSource.cpp
OBJDIR = obj
OBJDIR_PRINT = obj_print
OBJS = $(SRCS:src/%.cpp=$(OBJDIR)/%.o)
OBJS_PRINT = $(SRCS_PRINT:src_print/%.cpp=$(OBJDIR_PRINT)/%.o)
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

# Règle print : compilation avec les fichiers source du dossier src_print
print: $(OBJS_PRINT)
	$(CC) $(CFLAGS) $^ -o $(NAME)_print

# Compilation des fichiers objets pour print
$(OBJDIR_PRINT)/%.o: src_print/%.cpp
	@mkdir -p $(OBJDIR_PRINT)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJDIR) $(OBJDIR_PRINT)

# Nettoyage complet (obj + binaire)
fclean: clean
	rm -f $(NAME) $(NAME)_print

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re print
