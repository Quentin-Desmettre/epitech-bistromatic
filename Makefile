##
## EPITECH PROJECT, 2021
## Bistro-matic
## File description:
## makefile
##

NAME = calc

LIBS = -L ./lib/my/ -lmy

official:
	make -C ./lib/my/ && make -C ./lib/my/ clean
	make -C ./src/
	gcc -o $(NAME) *.o $(LIBS)

easy:
	make -s -C bonus/
	mv bonus/calc ./

graphical:
	rm -rf graphical
	mkdir -p graphical/
	cd graphical ; qmake ../bonus/Bistromatic_graphic/Bistromatic.pro ; make
	mv graphical/Bistromatic ./graphic
	rm -rf graphical
	make -s fclean -C bonus/

tests_run: fclean
	make -C ./lib/my/ && make -C ./lib/my/ clean
	make -C ./src/ tests
	make -C ./tests/
	gcc -o unit_tests *.o $(LIBS) --coverage -lcriterion
	./unit_tests
	gcovr --exclude test --html --html-details -o bistro.html

clean:
	rm -f *.o
	make -C ./src/ clean
	make -C ./tests/ clean
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.html
	rm -f *.css
	rm -f output
	rm -f graphic

re: fclean all
