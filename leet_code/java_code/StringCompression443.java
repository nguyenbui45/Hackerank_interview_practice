import java.io.*;
import java.util.StringTokenizer;
import java.util.Vector;

public class StringCompression443
{
    public static int compress(char[] chars){
	Vector<Character> s = new Vector<>();
	int count = 0;
	char chr = ' ';
	
	if(chars.length == 1){
	    return 1;
	}

	for(int i = 0; i < chars.length;i++){
	    if(count == 0){
		chr = chars[i];
		count=1;
	    }
	    else if(count == 1 && chr!=chars[i]){
		s.add(chr);
		count=1;
		chr=chars[i];
		if(i == chars.length -1){
		    s.add(chr);
		}
	    }
	    else if(count>1 && chr!=chars[i]){
		s.add(chr);
		if(i != chars.length -1){
		    char [] num_char = (String.valueOf(count)).toCharArray();
		    for(char j:num_char){
			s.add(j);
		    }
		}
		else if(i== chars.length-1){
		    char [] num_char = (String.valueOf(count)).toCharArray();
		    for(char j:num_char){
			s.add(j);
		    }
		    s.add(chars[i]);
		}

		count=1;
		chr = chars[i];
	    }
	    else{
		if(i == chars.length-1){
		    count+=1;
		    s.add(chr);
		    char [] num_char = (String.valueOf(count)).toCharArray();
		    for(char j:num_char){
			s.add(j);
		    }
		}
		else{
		    count+=1;
		}
	    }
	}
	for(char k:s)
	{ System.out.println(k);}
	return s.size();
    }


    public static void main(String args[]) throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	StringTokenizer n_str = new StringTokenizer(br.readLine());
	int n = Integer.parseInt(n_str.nextToken());

	StringTokenizer ele_str = new StringTokenizer(br.readLine());
	char [] chars = new char[n];
	for(int i = 0; i < n; i++){
	    chars[i] = ele_str.nextToken().charAt(0);
	}
	System.out.println(compress(chars));


	// close the I/O stream
	br.close();
	pw.close();
    }

}



