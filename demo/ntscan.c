import java.io.*
import java.util.*
public class ntscanScanner {

	public static final int S_Integer = 0;
	public static final int S_Comment = 1;
	public static final int S_FileIdent = 2;
	public static final int S_Ident = 3;
	public static final int S_Start = 4;
	public static final int S_Error = 5;
	public static final int NumberOfStates = 5;

	public static final int T_integer = 0
	public static final int T_comma = 2
	public static final int T_deref = 4
	public static final int T_rbrack = 6
	public static final int T_lbrack = 8
	public static final int T_semico = 10
	public static final int T_rbrace = 12
	public static final int T_lbrace = 14
	public static final int T_fileIdent = 16
	public static final int T_ident = 18
	public static final int T_EoF = 20
	public static final int NumberOfTerminals = 22
	public static final int NumberOfTokens = 22
	private ScanInfo scanInfo = new ScanInfo();

	public Token Scan(Reader file)
	{
		char CurrentChar = 0;

		scanInfo.setFile(file);
		scanInfo.setState(S_Start);
		scanInfo.setAttribute(-1);
		scanInfo.setBuffer( new StringBuffer());
		scanInfo.Ignore();
		for (;;) {
			CurrentChar = scanInfo.getNextChar();
			switch(scanInfo.getState()) {
				case S_Integer:
					if (AST.NUMERIC(CurrentChar)) {
						scanInfo.Advance();
					}
					else if (AST.LAMBDA(CurrentChar)) {
						scanInfo.PushBack();
						scanInfo.setAttribute(T_integer);
						return (scanInfo.asToken());
					}
					break;
				case S_Comment:
					if (AST.cins(CurrentChar,"\n")) {
						scanInfo.Ignore();
						scanInfo.setState(S_Start);
					}
					else if (AST.LAMBDA(CurrentChar)) {
						scanInfo.Ignore();
					}
					break;
				case S_FileIdent:
					if (AST.cins(CurrentChar,"./")) {
						scanInfo.Advance();
					}
					else if (AST.NUMERIC(CurrentChar)) {
						scanInfo.Advance();
					}
					else if (AST.ALPHA(CurrentChar)) {
						scanInfo.Advance();
					}
					else if (AST.LAMBDA(CurrentChar)) {
						scanInfo.PushBack();
						scanInfo.setAttribute(T_fileIdent);
						return (scanInfo.asToken());
					}
					break;
				case S_Ident:
					if (AST.cins(CurrentChar,"./")) {
						scanInfo.Advance();
						scanInfo.setState(S_FileIdent);
					}
					else if (AST.cins(CurrentChar,"_")) {
						scanInfo.Advance();
					}
					else if (AST.NUMERIC(CurrentChar)) {
						scanInfo.Advance();
					}
					else if (AST.ALPHA(CurrentChar)) {
						scanInfo.Advance();
					}
					else if (AST.LAMBDA(CurrentChar)) {
						scanInfo.PushBack();
						scanInfo.setAttribute(T_ident);
						return (scanInfo.asToken());
					}
					break;
				case S_Start:
					if (AST.cins(CurrentChar,",")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_comma);
						return (scanInfo.asToken());
					}
					else if (AST.cins(CurrentChar,"*")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_deref);
						return (scanInfo.asToken());
					}
					else if (AST.cins(CurrentChar,"]")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_rbrack);
						return (scanInfo.asToken());
					}
					else if (AST.cins(CurrentChar,"[")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_lbrack);
						return (scanInfo.asToken());
					}
					else if (AST.cins(CurrentChar,";")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_semico);
						return (scanInfo.asToken());
					}
					else if (AST.cins(CurrentChar,"}")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_rbrace);
						return (scanInfo.asToken());
					}
					else if (AST.cins(CurrentChar,"{")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_lbrace);
						return (scanInfo.asToken());
					}
					else if (AST.cins(CurrentChar,"#")) {
						scanInfo.Ignore();
						scanInfo.setState(S_Comment);
					}
					else if (AST.cins(CurrentChar,"./")) {
						scanInfo.InitAdvance();
						scanInfo.setState(S_FileIdent);
					}
					else if (AST.cins(CurrentChar,"_")) {
						scanInfo.InitAdvance();
						scanInfo.setState(S_Ident);
					}
					else if (AST.NUMERIC(CurrentChar)) {
						scanInfo.InitAdvance();
						scanInfo.setState(S_Integer);
					}
					else if (AST.ALPHA(CurrentChar)) {
						scanInfo.InitAdvance();
						scanInfo.setState(S_Ident);
					}
					else if (AST.ENDOFFILE(CurrentChar)) {
						scanInfo.InitIgnore();
						scanInfo.setAttribute(T_EoF);
						return (scanInfo.asToken());
					}
					else if (AST.LAMBDA(CurrentChar)) {
						scanInfo.Ignore();
					}
					break;
				default:
					throw new AstException("State Encountered");
			}
		}
	}
}
