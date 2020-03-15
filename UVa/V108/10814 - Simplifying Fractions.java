import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        while (N-- > 0) {
            BigInteger a = input.nextBigInteger();
            String slash = input.next();
            BigInteger b = input.nextBigInteger();

            BigInteger GCD = a.gcd(b);
            System.out.println(a.divide(GCD) + " / " + b.divide(GCD));
        }
    }
}