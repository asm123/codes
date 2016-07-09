/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nuvizz.june16;

import java.util.Scanner;

/**
 *
 * @author asmita
 */
public class PrimePrime {
    private static final int limit = 1000001;
	private static int[] primes = new int[limit];
	private static int[] primePrime = new int[limit];
	private static boolean isPrime[] = new boolean[limit];
	
	
	private static void sieve() {
		
		
		isPrime[0] = false;
		isPrime[1] = false;
		
		for (int i = 2; i < limit; i++) {
			isPrime[i] = true;
		}

		primes[0] = 0;
		primes[1] = 0;
		
		for (int i = 2; i < limit; i++) {
			primes[i] = primes[i-1];
			primePrime[i] = primePrime[i-1];
			
			if (isPrime[i]) {
				for (int j = i*2; j < limit; j += i) {
					isPrime[j] = false;
				}
				primes[i]++;
			}
			if (isPrime[primes[i]]) {
				primePrime[i]++;
			}
		}
	}
	
    public static void main(String args[] ) throws Exception {
    	sieve();
    	Scanner scanner = new Scanner(System.in);
    	int T = Integer.parseInt(scanner.nextLine());
    	
    	for (int t = 0; t < T; t++) {
    		int L = scanner.nextInt();
    		int R = scanner.nextInt();
    		
    		System.out.println(primePrime[R] - primePrime[L-1]);	
    		
    		
    	}
    }
}
