import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        while (T-- > 0) {
            String gg = input.nextLine();
            String str = input.nextLine();
            BigInteger m = new BigInteger(str);
            int n = input.nextInt();

            boolean flag = true;
            for (int i = 0; i < n; i++) {
                BigInteger tmp = input.nextBigInteger();
                if (!m.mod(tmp).equals(BigInteger.ZERO)) {
                    flag = false;
                }
            }

            System.out.print(str + " - ");
            if (flag) {
                System.out.println("Wonderful.");
            } else {
                System.out.println("Simple.");
            }
        }
    }
}