//DAY 2 PART 2
//provided by R. Shahid
import java.io.*;
import java.util.Scanner;

public class d2p2 {
    public static void main(String[] args) throws FileNotFoundException{
        Scanner s1 = new Scanner(new File(/*path to input file*/) );

        int horizontal = 0;
        int depth = 0;
        int output = 0;
        int aim = 0;


        while (s1.hasNext()){
            String currentLine = s1.nextLine();
            if (currentLine.contains("forward")){
                if (aim != 0){
                    depth += aim * Integer.parseInt(currentLine.substring(currentLine.length()-1));
                }
                horizontal += Integer.parseInt(currentLine.substring(currentLine.length()-1));
            }
            else if (currentLine.contains("down")){
                aim += Integer.parseInt(currentLine.substring(currentLine.length()-1));
            }
            else if (currentLine.contains("up")){
                aim -= Integer.parseInt(currentLine.substring(currentLine.length()-1));
            }
        }

        output = horizontal * depth;
        s1.close();
        System.out.println(output);
    }
}
