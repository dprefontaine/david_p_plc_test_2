package test_2_problem_4;

import java.io.BufferedReader;
import java.io.IOException;
import java.lang.Character;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;

//DAVID PREFONTAINE
//4/23/20

//FOR PROBLEM FOUR OF TEST TWO

//MODULO LINES MARKED WITH A COMMENT
//ERROR FUNCTIONALITY IMPLEMENTED AT THE BOTTOM
//

public class FrontAndRda {
	//CHARACTERS
	static final int LETTER = 0;
	static final int DIGIT = 1;
	static final int UNKNOWN = 99;

	//TOKENS
	static final int INT_LIT = 10;
	static final int IDENT = 11;
	static final int ASSIGN_OP = 20;
	static final int ADD_OP = 21;
	static final int SUB_OP = 22;
	static final int MULT_OP = 23;
	static final int DIV_OP = 24;
	static final int MODULO_OP = 25;				//MODULO IMPLEMENTATION HERE
	static final int LEFT_PAREN = 26;
	static final int RIGHT_PAREN = 27;
	static final int EOF = 28;
	
	static final int NO_ERROR = 0;
	static final int RHS_ERROR = 1;
	static final int UNKNOWN_ERROR = 2;
	
	static private int charClass;
	static private StringBuilder lexeme = new StringBuilder();
	static private char nextChar;
	static private int lexLength;
	//static private int token;
	static private int nextToken = LETTER;
	static int errorFlag = NO_ERROR;
	static private String errorLog = "";
	
	//PARSING LINE
	static private String lineToParse;
	
	public static void main(String[] args) {
		//
		/*
		 * The directory can be modified to whatever, the purpose of this
		 * problem is to convert the functionality of front and rda from C to Java.
		 */
		
		Path frontPath = FileSystems.getDefault().getPath("", "front.in");
	
		try (BufferedReader inputToParse = Files.newBufferedReader(frontPath)){
			//GET THE LINE
			while ((lineToParse = inputToParse.readLine()) != null && nextToken != EOF && errorFlag == NO_ERROR) {

				getChar();
				
		 		do {
		 			lex();
		 		} while (nextToken != EOF && errorFlag == NO_ERROR);
			}
			
			if (errorFlag != NO_ERROR) {
				System.out.println("Error: " + getError());
			}
			
		} catch (IOException e) {
			System.out.println("ERROR - cannot open front.in");
		}
	}
	
	//LOOKING UP TOKENS
	private static int lookup(char ch) {
		 switch (ch) {
			 case '(':
				 addChar();
				 nextToken = LEFT_PAREN;
				 break;
			 case ')':
				 addChar();
				 nextToken = RIGHT_PAREN;
				 break;
			 case '+':
				 addChar();
				 nextToken = ADD_OP;
				 break;
			 case '-':
				 addChar();
				 nextToken = SUB_OP;
				 break;
			 case '*':
				 addChar();
				 nextToken = MULT_OP;
				 break;
			 case '/':
				 addChar();
				 nextToken = DIV_OP;
				 break;
			 case '%':
				 addChar();
				 nextToken = MODULO_OP;				//MODULO IMPLEMENTATION HERE
				 break;
			 default:
				 addChar();
				 nextToken = EOF;
				 break;
		 }
		 return nextToken;
	}
	
	//ADDING CHARACTER
	static private void addChar() {
		if (lexLength <= 98) {
			lexeme.append(String.valueOf(nextChar));
		} else {
			System.out.println("Error - lexeme is too long");
		}
	}
	
	//
	static private void getChar() {
		char charIn = lineToParse.charAt(0);
		lineToParse = lineToParse.substring(0);
		
		 if ((nextChar = charIn) != EOF) {
			 if (Character.isLetter(nextChar))
			 	charClass = LETTER;
			 else if (Character.isDigit(nextChar))
			 	charClass = DIGIT;
			 else
			 	charClass = UNKNOWN;
		 } else
		 	charClass = EOF;
	}
	
	//
	static private void getNonBlank() {
		while (Character.isWhitespace(nextChar))
		getChar();
	}
	
	//LEXING
	static private int lex() {
		 lexLength = 0;
		 getNonBlank();
		 switch (charClass) {
			//LETTER OR IDENTIFIERS
			 case LETTER:
				 addChar();
				 getChar();
				 while (charClass == LETTER || charClass == DIGIT) {
					 addChar();
					 getChar();
				 }
				 nextToken = IDENT;
				 break;
			//INTEGERS
			 case DIGIT:
				 addChar();
				 getChar();
				 while (charClass == DIGIT) {
					 addChar();
					 getChar();
				 }
				 nextToken = INT_LIT;
			 	break;
			//PARENTHESIS AND OPERATIONS
			 case UNKNOWN:
				 lookup(nextChar);
				 getChar();
				 break;
			//EOF
			case EOF:
				 nextToken = EOF;
				 lexeme.delete(0,lexeme.capacity());
				 lexeme.append('E');
				 lexeme.append('O');
				 lexeme.append('F');
				 
			 	break;
		 } /* End of switch */
		 
		 System.out.println("Next token is: " + nextToken + " Next lexeme is " + lexeme.toString());
		 return nextToken;
	}
	
	//****************************************
	//RDA
	//****************************************
	/* expr
	 Parses strings in the language generated by the rule:
	 <expr> -> <term> {(+ | -) <term>}
	 */
	static private void expr() {
		System.out.println("Enter <expr>");
		
		/* Parse the first term */
		 term();
		/* As long as the next token is + or -, get
		 the next token and parse the next term */
		 while (nextToken == ADD_OP || nextToken == SUB_OP) {
			 lex();
			 term();
		 }
		 
		 System.out.println("Exit <expr>");
	}

	/* term
	 Parses strings in the language generated by the rule:
	 <term> -> <factor> {(* | /) <factor>}
	 */
	static private void term() {
		System.out.println("Enter <term>");
		
		/* Parse the first factor */
		 factor();
		/* As long as the next token is * or /, get the
		 next token and parse the next factor */
		 while (nextToken == MULT_OP || nextToken == DIV_OP || nextToken == MODULO_OP) {    				//MODULO IMPLEMENTATION HERE
			 lex();
			 factor();
		 }
		 
		 System.out.println("Exit <term>");
	}

	/* factor
	 Parses strings in the language generated by the rule:
	 <factor> -> id | int_constant | ( <expr> )
	 */
	static private void factor() {
		System.out.println("Enter <factor>");
		
		/* Determine which RHS */
		 if (nextToken == IDENT || nextToken == INT_LIT)
			/* Get the next token */
			 	lex();
			/* If the RHS is ( <expr> ), call lex to pass over the
			 left parenthesis, call expr, and check for the right
			 parenthesis */
		 else { if (nextToken == LEFT_PAREN) {
			 	lex();
			 	expr();
			 if (nextToken == RIGHT_PAREN)
			 	lex();
			 else
			 	error(RHS_ERROR);
			 }
			/* It was not an id, an integer literal, or a left
			 parenthesis */
			 else
			 error(UNKNOWN_ERROR);
		 }
		 System.out.println("Exit <factor>");
	}
	
	static private void error(int errorFlag) {
		switch (errorFlag) {
		case (RHS_ERROR):
			errorLog = "No right parenthesis";
			break;
		case (UNKNOWN_ERROR):
			errorLog = "Unidentified character";
			break;
		}
	}
	
	static String getError() {
		return errorLog;
	}
}
