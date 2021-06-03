all: compile

compile:
	@gcc *.c -o main.exe -Wall
	
run:
	@./main.exe
