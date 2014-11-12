package org.jhpc.apt;

/*
 * This class is used in the ScanInfo class for maintaining context information
 * associated with backing up over new-lines in the scanner.
 */

public class LineColInfo {
    private int line, column;

    public LineColInfo(int line, int column) {
	this.line = line;
	this.column = column;
    }

    public int getLine() {
	return line;
    }

    public int getColumn() {
	return column;
    }

}
