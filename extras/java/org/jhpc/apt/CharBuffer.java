package org.jhpc.apt;

import java.util.*;

/*
 * This is a simple abstraction for a character pushdown. I had to write this
 * because the StringBuffer class of Java does not allow me to un-put a 
 * character (and appropriately resize it). Too bad. 
 */


public class CharBuffer {
    private StringBuffer sb;
    private int pos;
  
    public CharBuffer() {
	sb = new StringBuffer();
	pos = 0;
    }

    public int getSize() {
	return pos;
    }

    public void reset() {
	pos = 0;
    }
    
    public void push(char c) {
	if (pos < sb.length())
	    sb.setCharAt(pos, c);
	else
	    sb.append(c);
	pos++;
    }

    public char pop() throws CharBufferException {
	if (pos > 0) {
	    pos--;
	    return sb.charAt(pos);
	} else
	    throw new CharBufferException();
    }

    public char top() throws CharBufferException {
	if (pos > 0) {
	    return sb.charAt(pos-1);
	} else
	    throw new CharBufferException();
    }
		
    public String getText() {
	char[] textChars = new char[pos];
	sb.getChars(0, pos, textChars, 0);
	return new String(textChars);
    }
	

    public char charAt(int index) throws CharBufferException {
	if (index < pos)
	    return sb.charAt(pos);
	else
	    throw new CharBufferException();
    }
    
    public String toString() {
	return "CharBuffer: " + "size=" + pos + " text=" + getText();
    }

    public static void main(String args[]) {
	CharBuffer cb = new CharBuffer();
	char c;

	System.out.println("Pushing 1, 2, 3");
	cb.push('1');
	System.out.println(cb);
	cb.push('2');
	System.out.println(cb);
	cb.push('3');
	System.out.println(cb);

	
	/* test top */
	System.out.print("top test: ");
	try {
	    System.out.println(cb.top());
	} catch(Exception e) {
	    System.out.println("failed");
	}
	System.out.println(cb);
	/* test pop */
	System.out.println("pop test (should be 3 items): ");
	try {
	    System.out.println(cb.pop());
	    System.out.println(cb);
	    System.out.println(cb.pop());
	    System.out.println(cb);
	    System.out.println(cb.pop());
	    System.out.println(cb);
	} catch(Exception e) {
	    System.out.println("failed");
	}
	System.out.println(cb);
	cb.push('a');
	System.out.println(cb);
	cb.reset();
	System.out.println(cb);
    }
}
