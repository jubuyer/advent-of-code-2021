//DAY 1 PART 1
//provided by R. Shahid
import java.io.*;
import java.util.Scanner;
public class d1p1 {
    public static void main(String[] args) throws FileNotFoundException{
        Scanner s1 = new Scanner(new File(/*path to input file*/) );
        int a = Integer.parseInt(s1.next());
        System.out.println(a);
        int counter = 0;
        while (s1.hasNext()){
            int b = Integer.parseInt(s1.next());
            if (b > a){
                counter++;
            }
            a = b;
        }
        s1.close();
        System.out.println(counter);
    }
}
