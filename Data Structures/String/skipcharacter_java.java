import java.util.*;
public class skip_character {
    public static void main(String[] args) {
        String s="bchapplejt";
        int i=0;
        System.out.println(skip(s,i));
    }
    static String skip(String str,int i){
        if(i<str.length()) {
            char ch = ' ';
            char c = str.charAt(i);
            if (c != 'p') {                   // skipping character 'p'
                return c + skip(str, i + 1);
            } else {
                return skip(str, i + 1);
            }
        }
        return "";
    }
}
