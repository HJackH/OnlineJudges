import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static BigInteger F[] = new BigInteger[5100];

    public static void main(String[] args) {

        F[0] = BigInteger.ZERO;
        F[1] = BigInteger.ONE;
        for (int i = 2; i <= 5000; i++) {
            F[i] = F[i - 1].add(F[i - 2]);
        }

        Scanner input = new Scanner(System.in);
        int n;
        
        while (input.hasNext()) {
            n = input.nextInt();
            System.out.println("The Fibonacci number for " + n + " is " + F[n]);
        }
    }
}