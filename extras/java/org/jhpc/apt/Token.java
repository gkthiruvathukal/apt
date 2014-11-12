package org.jhpc.apt;

public class Token {
    private int line, column;
    private int attribute;
    private String matchedText;

    public Token(String matchedText, int line, int column, int attribute) {
	this.matchedText = matchedText;
	this.line = line;
	this.column = column;
	this.attribute = attribute;
    }

    public int getLine() {
	return line;
    }

    public int getColumn() {
	return column;
    }

    public int getAttribute() {
	return attribute;
    }
    
    public String getText() {
	return matchedText;
    }

    public String toString() {
	return "Token: text=" + matchedText +
	    " line=" + line + " column=" + column + " attr="+attribute;
    }
}

