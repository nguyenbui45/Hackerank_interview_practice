import java.io.*;
import java.util.StringTokenizer;
import java.lang.Integer;

public class IncreasingTripletSubsequences334
{
    public static boolean increasingTriplet(int[] nums)
    {
	int max1 =Integer.MAX_VALUE;
	int max2 =Integer.MAX_VALUE;
	for(int i:nums)
	{
	    if(i <=max1)
	    {
		max1 = i;
	    }
	    else if(i <= max2)
	    {
		max2 = i;
	    }
	    else
	    {
		return true;
	    }
	}
	return false;
    }

    public static void main(String [] args) throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	StringTokenizer n_str = new StringTokenizer(br.readLine());
	int n = Integer.parseInt(n_str.nextToken());

	StringTokenizer ele_str = new StringTokenizer(br.readLine());
	int[] nums = new int[n]; 
	for(int i = 0; i < n;i++)
	{
	     nums[i] = Integer.parseInt(ele_str.nextToken());
	}

	System.out.println(increasingTriplet(nums));

        // Close the I/O streams
        br.close();
        pw.close();
    }
}



