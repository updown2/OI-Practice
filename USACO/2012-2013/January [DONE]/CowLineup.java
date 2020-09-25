import java.lang.*;
import java.io.*;
import java.util.*;

public class CowLineup {

  static int inp[];
  static int on;
  static HashMap<Integer, Integer> cnt;

  public static void main(String[] args) throws FileNotFoundException {
    //Scanner in = new Scanner (new File("test.in"));
    //PrintWriter pw = new PrintWriter(System.out);
    Scanner in = new Scanner (new File("lineup.in"));
    PrintWriter pw = new PrintWriter("lineup.out");

    cnt = new HashMap<Integer, Integer>();
    int N = in.nextInt();
    int K = in.nextInt();
    inp = new int[N];
    int out = 0;

    for (int i=0; i<N; i++) {
      inp[i] = in.nextInt();
    }

    int lp = 0;
	for (int rp=0; rp<N; rp++) {
		add (rp);
		while (on > K+1) {
			remove (lp);
			lp++;
		}
		out = Math.max(out, cnt.get(inp[rp]));
	}

    pw.println(out);
    pw.close();
  }

  public static void add(int i) {
    int val = inp[i];
    if (!cnt.containsKey(val)) {
        cnt.put(val, 0);
    }
    if (cnt.get(val) == 0) {
        on++;
    }

    cnt.replace(val, cnt.get(val) + 1);
  }

  public static void remove(int i) {
    int val = inp[i];
    cnt.replace(val, cnt.get(val) - 1);
    if (cnt.get(val) == 0) {
        on--;
    }
  }

}

