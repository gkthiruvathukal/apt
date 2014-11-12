package org.jhpc.apt;

public class AstException extends Exception {
    private String message;

    public AstException(String message) {
	this.message = message;
    }

    public String toString() {
	return "Apt Scanning Tool Exception: " + message;
    }
}
