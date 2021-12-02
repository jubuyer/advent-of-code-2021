//DAY 1 PART 2
//provided by R. Shahid
import java.io.*;
import java.util.Scanner;
public class d1p2 {
    public static void main(String[] args) throws FileNotFoundException{
        Scanner s1 = new Scanner(new File(/*path to input file*/) );

        int a = Integer.parseInt(s1.next());
        int b = Integer.parseInt(s1.next());
        int c = Integer.parseInt(s1.next());;
        int d,sum1,sum2,counter = 0;

        while (s1.hasNext()){
            d = Integer.parseInt(s1.next());
            sum1 = a + b + c;
            sum2 = b + c + d;

            if (sum2 > sum1){
                counter++;
            }
            a = b;
            b = c;
            c = d;
        }

        s1.close();
        System.out.println(counter);
    }
}
