import org.jhpc.apt.*;
import java.io.*;

public class TestScannerSimple {

  public static void main(String args[]) {
    try {
    FileReader sr = new FileReader(args[0]);
    ScannerSimple ss = new ScannerSimple(sr);
    Token t;

    while (true) {
      try {
        t = ss.Scan();
        System.out.println(t);
	if (t.getAttribute() == ScannerSimple.T_EoF)
           break;
      } catch(Exception e) {
        System.out.println("The scanner died. Ouch. Exception:" + e);
      }
    } 
    } catch(Exception e) { System.out.println("usage: java TestScannerSimple <filename>"); }
  }
}

