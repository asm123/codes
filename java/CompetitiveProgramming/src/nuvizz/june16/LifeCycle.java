/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nuvizz.june16;

import java.util.Scanner;

class LifeCycle {
    public static void main(String args[] ) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] str = new String[N];
        
        for (int i = 0; i < N; i++) {
            str[i] = scanner.nextLine();
        }
		
        int maxDayStreak = 0;
        int maxTotalStreak = 0;
		
        int resumedStreakCount = 0;
	
        int streakCount = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < str[i].length(); j++) {
                if (str[i].charAt(j) == 'C') {
                    streakCount++;
                    resumedStreakCount++;
                }
                else {
                    if (resumedStreakCount > 0) {
                        maxTotalStreak = Math.max(maxTotalStreak, resumedStreakCount);
                        resumedStreakCount = 0;
                    }
                    if (streakCount > 0) {
                        maxDayStreak = Math.max(maxDayStreak, streakCount);
                        streakCount = 0;
                    }
                }
                if (j == str[i].length()-1) {
                    if (streakCount > 0) {
                        maxDayStreak = Math.max(maxDayStreak, streakCount);
                        streakCount = 0;
                    }
                }
            }
        }

        System.out.println(maxDayStreak + " " + maxTotalStreak);
    }
}

