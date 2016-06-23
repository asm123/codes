package codechef.june16;


import java.util.Scanner;

class DevArray
{
    int[] array;
    int minIndex = -1, maxIndex = -1;

    public DevArray(int[] array) {
        this.array = array;
        for (int i = 0; i < this.array.length; i++) {
            if (minIndex == -1 || this.array[minIndex] > this.array[i]) {
                minIndex = i;
            }
            if (maxIndex == -1 || this.array[maxIndex] < this.array[i]) {
                maxIndex = i;
            }
        }
    }

    public boolean isPossible(int x) {
        return x >= array[minIndex] && x <= array[maxIndex];
    }


    public static void main (String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = Integer.parseInt(scanner.next().trim());
        int Q = Integer.parseInt(scanner.next().trim());

        int[] array = new int[N];
        for (int i = 0; i < N; i++) {
                array[i] = Integer.parseInt(scanner.next().trim());
        }
        DevArray devArray = new DevArray(array);

        for (int i = 0; i < Q; i++) {
            int x = Integer.parseInt(scanner.next().trim());
            if (devArray.isPossible(x)) {
                System.out.println("Yes");
            }
            else {
                System.out.println("No");
            }
        }
    }
}