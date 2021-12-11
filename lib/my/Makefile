##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile for libmy
##

GRAPHICS = get_color.c \
	swap_endian_color.c

IOMANIP = my_getnbr.c \
	my_getnbr_base.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_show_word_array.c \
	get_input.c

LINKED_LIST_DATA_MANIP = apply_on_matching_nodes.c \
	apply_on_nodes.c \
	rev_list.c \
	sort_list.c

LINKED_LIST_GET_DATA = find_node.c \
	list_size.c

LINKED_LIST_SIZE_MANIP = concat_list.c \
	delete_nodes.c \
	delete_single_node.c \
	insert_in_list.c \
	merge_lists.c \
	append_node.c

MATH = my_pow.c

OTHERS = my_sort_int_array.c \
	my_sort_word_array.c \
	my_swap.c

PATH_LLDM = linked_list/data_manip/
PATH_LLGD = linked_list/get_data/
PATH_LLSM = linked_list/size_manip/

STRMANIP = my_strcat.c              \
	my_strcmp.c              \
	my_strcpy.c              \
	my_strdup.c              \
	my_strlen.c              \
	my_strncat.c             \
	my_strncmp.c             \
	my_strncpy.c             \
	my_strstr.c              \
	my_str_to_word_array.c   \
	my_revstr.c \
	contain.c \
	replace_str.c \
	my_memset.c \
	append_char.c

OBJ = $(GRAPHICS:.c=.o) \
	$(IOMANIP:.c=.o) \
	$(LINKED_LIST_DATA_MANIP:.c=.o) \
	$(LINKED_LIST_GET_DATA:.c=.o) \
	$(LINKED_LIST_SIZE_MANIP:.c=.o) \
	$(MATH:.c=.o) \
	$(OTHERS:.c=.o) \
	$(STRMANIP:.c=.o)

NAME = libmy.a

FLAGS = -c -Wall -Wextra

GCC = gcc -c $(FLAGS)

all: compile build move

compile:
	cd graphics/ && $(GCC) $(GRAPHICS) && mv *.o ../
	cd iomanip/ && $(GCC) $(IOMANIP) && mv *.o ../
	cd $(PATH_LLDM) && $(GCC) $(LINKED_LIST_DATA_MANIP) && mv *.o ../../
	cd $(PATH_LLGD) && $(GCC) $(LINKED_LIST_GET_DATA) && mv *.o ../../
	cd $(PATH_LLSM) && $(GCC) $(LINKED_LIST_SIZE_MANIP) && mv *.o ../../
	cd math/ && $(GCC) $(MATH) && mv *.o ../
	cd others/ && $(GCC) $(OTHERS) && mv *.o ../
	cd strmanip/ && $(GCC) $(STRMANIP) && mv *.o ../

build:
	ar rc $(NAME) $(OBJ)

move:
	mkdir -p ../../include/lib
	cp include/*.h ../../include/lib

clean:
	rm -f $(OBJ)
