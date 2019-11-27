#application target for execute
calc: ui.o tokenizer.o infixtopostfix.o codegen.o interpreter.o
	gcc -o calc ui.c infixtopostfix.c codegen.c interpreter.c tokenizer.c

test:
	gcc -o tokenizer_test.t tokenizer_test.c
	prove -v ./tokenizer_test.t

	gcc -o infixtopostfix_test.t infixtopostfix_test.c
	prove -v ./infixtopostfix_test.t

	gcc -o codegen_test.t codegen_test.c
	prove -v ./codegen_test.t
	
	gcc -o interpreter_test.t interpreter_test.c
	prove -v ./interpreter_test.t

#object file targets for testing:
tokenizer.o: 		tokenizer.h

ui.o:				ui.c

infixtopostfix.o: 	tokenizer.h infixtopostfix.h

codegen.o: 			tokenizer.h codegen.h

interpreter.o:		tokenizer.h interpreter.h


# clean target
clean:
	rm *.o *.t calc 
	


