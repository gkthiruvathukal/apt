package org.jhpc.apt;

import java.util.*;
import java.io.*;

public class ScanInfo {
    
    private Reader file;
    private int currentState;
    private int currentAttribute;
    private CharBuffer buffer;
    private CharBuffer ungetBuffer;
    private char currentChar;
    private boolean eof;
    private int line, column, tokenLine, tokenColumn;
    private Stack lcStack;

    public ScanInfo(Reader file) {
	this.file = file;
	this.currentState = -1;
	this.currentAttribute = -1;
	this.buffer = new CharBuffer();
	this.ungetBuffer = new CharBuffer();
	this.eof = false;
	this.line = this.column = this.tokenLine = this.tokenColumn = 1;
	this.lcStack = new Stack();
    }

    public boolean anotherCharPlease() {

	/* try the unget buffer; return false if we read from here. */
	try {
	    currentChar = ungetBuffer.pop();
	    return false;
	} catch(Exception e) {}
	
	/* try the reader; return true if we read from here. */
	try {
	    int nextChar = file.read();
	    if (nextChar >= 0) {
		currentChar = (char) nextChar;
		return true;
	    }
	} catch(Exception e) {}

	/* if we could not read from either place; eof has been encountered */
	eof = true;
	return true;
    }

    public char getNextChar() {
	return currentChar;
    }

    public void setState(int newState) {
	currentState = newState;
    }

    public int getState() {
	return currentState;
    }

    public void setAttribute(int newAttribute) {
	currentAttribute = newAttribute;
    }


    public int getAttribute() {
	return currentAttribute;
    }

    public void setBuffer(CharBuffer newBuffer) {
	buffer = newBuffer;
    }

    public CharBuffer getBuffer() {
	return buffer;
    }

    public void setFile(Reader newFile) {
	file = newFile;
    }

    public Reader getFile() {
	return file;
    }


    public void Advance() {
	buffer.push(currentChar);
	updateLineColumn();
    }

    public void AdvanceDelete() {
	Advance();
	try {
	    char c = buffer.pop();
	    c = buffer.pop();
	} catch(Exception e) {
	    // Can safely be ignored.
	}

    }

    public void noteTokenStart() {
	tokenLine = line;
	tokenColumn = column;
    }

    public void InitAdvance() {
	noteTokenStart();
	Advance();
    }

    public void Flush() { 
	updateLineColumn();
	buffer.reset();
    }

    public void Ignore() {
	updateLineColumn();
    }

    public void InitIgnore() {
	noteTokenStart();
	updateLineColumn();
    }

    public void Match() {
	buffer.push(currentChar);
    }

    public void InitMatch() {
	noteTokenStart();
	Match();
    }

    public void PushBack() {
	reverseUpdateLineColumn();
    }

    public void PushBackTwo() {
	reverseUpdateLineColumn();
	try {
	    currentChar = buffer.pop();
	    reverseUpdateLineColumn();
	} catch(Exception e) {
	    // Can safely be ignored.
	}
    }
    public void PushBackThree() {
	reverseUpdateLineColumn();
	try {
	    currentChar = buffer.pop();
	    reverseUpdateLineColumn();
	    currentChar = buffer.pop();
	    reverseUpdateLineColumn();
	} catch(Exception e) {
	    // Can safely be ignored
	}
    }

    public void reverseUpdateLineColumn() {
	if (currentChar != '\n')
	    column--;
	ungetBuffer.push(currentChar);
    }

    public void updateLineColumn() {
	LineColInfo lc;
	boolean fresh;

	if (currentChar == '\n') {
	    line++; 
	    column = 1;
	} else
	    column++;

	fresh = anotherCharPlease();

	if (currentChar == '\n')
	    if (fresh) {
		lc = new LineColInfo(line, column);
		lcStack.push(lc);
	    } else {
		try {
		    lc = (LineColInfo) lcStack.pop();
		    line = lc.getLine();
		    column = lc.getColumn();
		} catch(Exception e) {
		    // This is ok.
		}
	    }
    }

    public void clearTokenBuffer() {
	buffer.reset();
    }

    public Token asToken() {
	Token newToken = new Token(buffer.getText(), tokenLine,
				   tokenColumn, currentAttribute);
	return newToken;
    }

    public boolean cins(String s) {
	return s.indexOf(currentChar) >= 0;
    }

    public boolean ALPHA() {
	return Character.isLetter(currentChar);
    }

    public boolean UPPERALPHA() {
	return Character.isUpperCase(currentChar);
    }

    public boolean ALPHANUMERIC() {
	return Character.isLetterOrDigit(currentChar);
    }

    public boolean NUMERIC() {
	return Character.isDigit(currentChar);
    }

    public boolean DEFAULT() {
	return true;
    }

    public boolean LAMBDA() {
	return true;
    }

    public boolean ENDOFFILE() {
	return eof;
    }

    public boolean HEXDIGIT() {

	return NUMERIC() || cins("ABCDEFabcdef");
    }

    public boolean OCTDIGIT() {
	return cins("01234567");
    }

    public boolean WHITESPACE() {
	return cins(" \t\n") || Character.isWhitespace(currentChar);
    }

}
