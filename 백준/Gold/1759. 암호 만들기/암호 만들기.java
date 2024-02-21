import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int L, C;
	static List<Each> list = new ArrayList<>();
	static boolean[] visited;
	static String[] selected;

	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		visited = new boolean[C];
		selected = new String[L];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<C; i++) {
			list.add(new Each(st.nextToken(), 0));
		}
		
		Collections.sort(list);
		
		comb(0, 0);
		
	}

	static void comb(int srcIdx, int tgtIdx) {
		if(tgtIdx == L) {
			String str = "";
			int mo = 0, ja = 0;
			for(int i=0; i<L; i++) {
				if (selected[i].equals("a") || selected[i].equals("e") || selected[i].equals("i")
                        || selected[i].equals("o") || selected[i].equals("u"))
                    mo++;
				else
					ja++;
				str += selected[i];
			}
			if(mo >= 1 && ja >= 2)
				System.out.println(str);
			return;
		}
		
		if(srcIdx == C)
			return;
		
		for(int i=srcIdx; i<C; i++) {
			selected[tgtIdx] = list.get(i).alphabet;
			comb(i+1, tgtIdx+1);
		}
	}

	static class Each implements Comparable<Each>{
		String alphabet;
		int idx;
		
		public Each(String alphabet, int idx) {
			this.alphabet = alphabet;
			this.idx = idx;
		}
		
		@Override
		public int compareTo(Each other) {
			return this.alphabet.compareTo(other.alphabet);
		}
	}
	
}
