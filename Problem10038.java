import java.lang.Integer;
import static java.lang.Math.abs;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Problem10038 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        //int n = sc.nextInt();
        while(sc.hasNextInt()) {
            int[] v = new int[2];
            //Set<Integer> found = new HashSet<Integer>();
			Set<Integer> found = new TreeSet<Integer>();
            boolean second = false;
            int n = sc.nextInt();
            for(int i = 0; i < n; i++) {
                v[i % 2] = sc.nextInt();
                if (second)
                    found.add(abs(v[0] - v[1]));
                else
                    second = true;
            }
            boolean wasFound = true;
            for (int i = 1; i < n; i++) {
                if (!found.contains(i)) {
                    wasFound = false;
                    break;
                }
            }
            if (wasFound)
                System.out.println("Jolly");
            else
                System.out.println("Not jolly");
        }
    }
}

