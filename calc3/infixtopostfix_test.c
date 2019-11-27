#include "ctap.h"
#include "tokenizer.c"
#include "infixtopostfix.c"
TESTS {
   
    
   // ok(is_operator('+')==1, "1 does in fact equal 1");
    int temp=top;
    push('1');
    //ok(top==temp, "Stack Overflow");
    //ok(top==temp+1, "push function success");
   // ok(pop()==stack[top+1],"pop function success");
    FILE *fp=NULL;
    FILE *output=fopen("temp.txt","w");
    writechar(output,'c');
    fclose(output);
    fp=fopen("temp.txt","r");
    ok(fgetc(output)=='c',"writechar function success");
    ok(precedence('^')==3, "precedence function success");
   /* FILE *input=fopen("temp2.txt","w");
    
    writechar(input,'1');
     writechar(input,'+');
     writechar(input,'1');
    fclose(input);
    input=fopen("temp2.txt","r");
    FILE *output2= NULL;
    output2 = fopen("temp3.txt","w");;
    infix2postfix(input, output2);
    output2=fopen("temp3.txt","r");
    ok(readchar(output2)=='1',"infix2postfix function success");
    */
    testinfixtopostfix();
    FILE *input=fopen("postfix.txt","r");
    ok(input!=NULL,"infix2postfix function success");
}
