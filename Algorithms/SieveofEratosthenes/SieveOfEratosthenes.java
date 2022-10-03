import java.util.*;
/**
 * Time Complexity O(Nlog(LogN))
 * Used to find prime numbers upto N
 */
public class SieveOfEratosthenes {
    static void sieveOfEratosthenes(int n){
        boolean bool []=new boolean [n+1];
        for(int i=0;i<bool.length;i++)bool[i]=true;
        for(int i=2;i<=Math.sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i)
            bool[j]=false;
        }
        System.out.println("The prime number upto n are ");
        for(int i=2;i<bool.length;i++){
            if(bool[i]==true){
                System.out.print(i+" ");
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sieveOfEratosthenes(n);
        sc.close();
    }
}