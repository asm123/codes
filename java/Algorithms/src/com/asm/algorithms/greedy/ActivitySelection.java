/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.greedy;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author asmita
 */

class Activity {
    private int startTime;
    private int finishTime;

    public int getStartTime() {
        return startTime;
    }

    public void setStartTime(int startTime) {
        this.startTime = startTime;
    }

    public int getFinishTime() {
        return finishTime;
    }

    public void setFinishTime(int finishTime) {
        this.finishTime = finishTime;
    }
}

class ActivityComparator implements Comparator<Activity> {

    @Override
    public int compare(Activity o1, Activity o2) {
        return Integer.compare(o1.getFinishTime(), o2.getFinishTime());
    }
    
}

public class ActivitySelection {
    
    public int getMaximumActivities (List <Activity> activities) {
        int maximumNumber = 0;
        Collections.sort(activities, new ActivityComparator());
        
        int previousFinishTime = -1;
        for (int i = 0; i < activities.size(); i++) {
            Activity currentActivity = activities.get(i);
            if (i == 0) {
                maximumNumber++;
                previousFinishTime = currentActivity.getFinishTime();
            }
            else {
                if (currentActivity.getStartTime() >= previousFinishTime) {
                    maximumNumber++;
                    previousFinishTime = currentActivity.getFinishTime();
                }
            }
        }
        
        return maximumNumber;
    }
    
    public static void main (String[] args) {
        List <Activity> activities;
        Scanner scanner = new Scanner(System.in);
        
        String line = scanner.next().trim();
        int testCases = Integer.parseInt(line);
        for (int t = 0; t < testCases; t++) {
            line = scanner.next().trim();
            int numberOfActivities = Integer.parseInt(line);
            activities = new ArrayList<>(numberOfActivities);
            
            // input start times
            for (int i = 0; i < numberOfActivities; i++) {
                int startTime = Integer.parseInt(scanner.next());
                Activity activity = new Activity();
                activity.setStartTime(startTime);
                activities.add(activity);
            }
            // input finish times
            for (int i = 0; i < numberOfActivities; i++) {
                int finishTime = Integer.parseInt(scanner.next());
                activities.get(i).setFinishTime(finishTime);
            }
            System.out.println(new ActivitySelection().getMaximumActivities(activities));
        }
    }
}
