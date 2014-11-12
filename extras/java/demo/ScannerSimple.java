import org.jhpc.apt.*;
import java.io.*;
import java.util.*;
public class ScannerSimple {

	public static final int S_Float2 = 0;
	public static final int S_Float1 = 1;
	public static final int S_Comment = 2;
	public static final int S_Integer = 3;
	public static final int S_Ident = 4;
	public static final int S_Start = 5;
	public static final int S_Error = 6;
	public static final int NumberOfStates = 6;

	public static final int T_error = 0;
	public static final int T_equals = 1;
	public static final int T_comma = 2;
	public static final int T_mod = 3;
	public static final int T_div = 4;
	public static final int T_mul = 5;
	public static final int T_sub = 6;
	public static final int T_add = 7;
	public static final int T_rbrack = 8;
	public static final int T_lbrack = 9;
	public static final int T_semico = 10;
	public static final int T_rparen = 11;
	public static final int T_lparen = 12;
	public static final int T_rbrace = 13;
	public static final int T_lbrace = 14;
	public static final int T_ident = 15;
	public static final int T_Float = 16;
	public static final int T_Integer = 17;
	public static final int T_EoF = 18;
	public static final int NumberOfTerminals = 19;
	public static final int NumberOfTokens = 19;
	public ScannerSimple(Reader file) {
		scanInfo = new ScanInfo(file);
	}

	private ScanInfo scanInfo;

	public Token Scan() throws AstException
	{
		char CurrentChar = 0;

		scanInfo.setState(S_Start);
		scanInfo.setAttribute(-1);
		scanInfo.clearTokenBuffer();
		scanInfo.Ignore();
		for (;;) {
			CurrentChar = scanInfo.getNextChar();
			switch(scanInfo.getState()) {
				case S_Float2:
					if (scanInfo.NUMERIC()) {
						scanInfo.Advance();
					}
					else if (scanInfo.LAMBDA()) {
						scanInfo.PushBack();
						scanInfo.setAttribute(T_Float);
						return (scanInfo.asToken());
					}
					break;
				case S_Float1:
					if (scanInfo.NUMERIC()) {
						scanInfo.Advance();
						scanInfo.setState(S_Float2);
					}
					else if (scanInfo.LAMBDA()) {
						scanInfo.PushBack();
						scanInfo.setAttribute(T_Float);
						return (scanInfo.asToken());
					}
					break;
				case S_Comment:
					if (scanInfo.cins("\n")) {
						scanInfo.Ignore();
						scanInfo.setState(S_Start);
					}
					else if (scanInfo.LAMBDA()) {
						scanInfo.Ignore();
					}
					break;
				case S_Integer:
					if (scanInfo.cins(".")) {
						scanInfo.Advance();
						scanInfo.setState(S_Float1);
					}
					else if (scanInfo.NUMERIC()) {
						scanInfo.Advance();
					}
					else if (scanInfo.LAMBDA()) {
						scanInfo.PushBack();
						scanInfo.setAttribute(T_Integer);
						return (scanInfo.asToken());
					}
					break;
				case S_Ident:
					if (scanInfo.NUMERIC()) {
						scanInfo.Advance();
					}
					else if (scanInfo.cins("_")) {
						scanInfo.Advance();
					}
					else if (scanInfo.ALPHA()) {
						scanInfo.Advance();
					}
					else if (scanInfo.LAMBDA()) {
						scanInfo.PushBack();
						scanInfo.setAttribute(T_ident);
						return (scanInfo.asToken());
					}
					break;
				case S_Start:
					if (scanInfo.WHITESPACE()) {
						scanInfo.Ignore();
					}
					else if (scanInfo.cins("=")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_equals);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins(",")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_comma);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("%")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_mod);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("/")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_div);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("*")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_mul);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("-")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_sub);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("+")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_add);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("]")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_rbrack);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("[")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_lbrack);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins(";")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_semico);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins(")")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_rparen);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("(")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_lparen);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("}")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_rbrace);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("{")) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_lbrace);
						return (scanInfo.asToken());
					}
					else if (scanInfo.cins("#")) {
						scanInfo.Ignore();
						scanInfo.setState(S_Comment);
					}
					else if (scanInfo.NUMERIC()) {
						scanInfo.InitAdvance();
						scanInfo.setState(S_Integer);
					}
					else if (scanInfo.cins("_")) {
						scanInfo.InitAdvance();
						scanInfo.setState(S_Ident);
					}
					else if (scanInfo.ALPHA()) {
						scanInfo.InitAdvance();
						scanInfo.setState(S_Ident);
					}
					else if (scanInfo.ENDOFFILE()) {
						scanInfo.InitIgnore();
						scanInfo.setAttribute(T_EoF);
						return (scanInfo.asToken());
					}
					else if (scanInfo.LAMBDA()) {
						scanInfo.InitMatch();
						scanInfo.setAttribute(T_error);
						return (scanInfo.asToken());
					}
					break;
				default:
					throw new AstException("State Encountered");
			}
		}
	}
}
