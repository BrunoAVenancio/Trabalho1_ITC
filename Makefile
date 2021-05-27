all: compile

compile:
	@gcc *.c -o main.run -Wall
	
run:
	@./main.run
