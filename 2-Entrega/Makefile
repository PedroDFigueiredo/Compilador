all: 	
		clear
		lex lexica.l
		yacc -d -v sintatica.y
		g++ -o glf y.tab.c -lfl
		./glf < exemplos/loop.ex > resultados/loop.cpp
		./glf < exemplos/aritmetico.ex > resultados/aritmetico.cpp
		./glf < exemplos/bloco.ex > resultados/bloco.cpp
		./glf < exemplos/condicional.ex > resultados/condicional.cpp
		./glf < exemplos/string.ex > resultados/string.cpp
		./glf < exemplos/relacional.ex > resultados/relacional.cpp
		./glf < exemplos/logico.ex > resultados/logico.cpp

		./glf < exemplos/loop.ex
		./glf < exemplos/loop.ex > resultados/loop.cpp

		# g++ -o main resultados/loop.cpp
		#  ./main
		# g++ -o main resultados/aritmetico.cpp
		#  ./main
		# g++ -o main resultados/bloco.cpp
		#  ./main
		# g++ -o main resultados/condicional.cpp
		#  ./main
		# g++ -o main resultados/relacional.cpp
		#  ./main
		# g++ -o main resultados/logico.cpp
		#  ./main

	