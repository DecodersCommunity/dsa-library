## The Chinese Remainder Theorem
Code computes for every set of integers ai and set of moduli ni a unqiue integer x, such that x ≡ ai (mod ni) for i = 1,2,3,...,k.
The following conditions must be met:

All ni must be pairwise coprime and greater 1.
For every i, the integers ai with 0 ≤ ai < ni have one and only one integer x for which the previously stated congruences hold true.
Input
In each line: one integer k for the number of moduli, followed by k pairwise coprime moduli n1,...,nk and k integers a1,...,ak

Output
The output contains, for each line in the input, a unique interger x ≡ ai (mod ni) for i = 1,2,3,...,k.

## Code in JAVA

import java.util.Scanner;

import java.math.BigInteger;

import java.util.ArrayList;

// Chinese Remainder Theorem

public class CRT {
	
	static BigInteger x = new BigInteger("0");
	static BigInteger y = new BigInteger("0");
	
	// iterative implementation of Extended Euclidean Algorithm
	// calculate b_i such that b_i*p + q*c = gcd(r, q) <=> p*b_i == 1%q
	public static BigInteger extended_euclidean_algortihm(BigInteger p, BigInteger q){
		BigInteger s = new BigInteger("0"); // quotient during algorithm
		BigInteger s_old = new BigInteger("1"); // Bézout coefficient
		BigInteger t = new BigInteger("1"); // quotient during algorithm
		BigInteger t_old = new BigInteger("0"); // Bézout coefficient
		BigInteger r = q;
		BigInteger r_old = p; // greatest common divisor
		BigInteger quotient;
		BigInteger tmp;
		
		while (r.compareTo(BigInteger.valueOf(0)) != 0){ // do while r != 0
			quotient = r_old.divide(r);
			
			tmp = r; // temporarily store to update r, r_old simultaneously
			r = r_old.subtract(quotient.multiply(r));
			r_old = tmp;
			
			tmp = s;
			s = s_old.subtract(quotient.multiply(s));
			s_old = tmp;
			
			tmp = t;
			t = t_old.subtract(quotient.multiply(t));
			t_old = tmp;
		}

		x = s_old; // x*p + y*q == gcd(p,q) ; this means x will be our b_i 
		y = t_old;
		return x;
	}
	
    public static BigInteger chinese_remainder_theorem(ArrayList<BigInteger> A, ArrayList<BigInteger> Q, int k) {
    	
		BigInteger p, tmp;
		BigInteger prod = new BigInteger("1"); // stores product of all moduli
		BigInteger sum = new BigInteger("0"); // sum x of CRT, which is also the solution after x % prod

		for (int i = 0; i < k; i++) 
			prod = prod.multiply(Q.get(i)); // multiply all moduli together

		for (int i = 0; i < k; i++) {
			p = prod.divide(Q.get(i));	// divide by current modulus to get product excluding said modulus
			tmp = extended_euclidean_algortihm(p, Q.get(i)); // calculate mod_inv b_i such that b_i*p == 1 % Q.get(i)
			sum = sum.add(A.get(i).multiply(tmp).multiply(p)); // sum up all products of integer a, product p, modulo inverse of p and Q.get(i)
		}
		
		return sum.mod(prod); // mod with product of all moduli to get smallest/unique integer
    }
    
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int k = 0;
        
        ArrayList<BigInteger> A; // array for integers a_i
        ArrayList<BigInteger> Q; // array for pairwise coprime moduli q_i
        
        //solve for every line separately
        while (stdin.hasNextLine()) {
            
        	// initialisation
            A = new ArrayList<BigInteger>(); 
            Q = new ArrayList<BigInteger>();
            
            //read past line and split based on ' ' character
            String[] input = stdin.nextLine().split(" ");
            
            // first number is amount of each q_i and a_i
            k = Integer.parseInt(input[0]);
            
            // read in moduli and integers
            for(int i=1; i<=k; i++) {
            	Q.add(new BigInteger(input[(i)])); // first k numbers are moduli q_i
                A.add(new BigInteger(input[(i+k)])); // second k numbers are integers a_i
            }

            // perform CRT and output unique integer
            System.out.println(chinese_remainder_theorem(A, Q, k).toString());
            
        }
    }
}
