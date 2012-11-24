import java.util.Locale;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.math.BigInteger;
import java.text.DecimalFormatSymbols;

public class _10137 {
    private static BigDecimal work(List<BigDecimal> v) {
        BigDecimal avg = new BigDecimal(0);
        for (BigDecimal i: v) {
            avg = avg.add(i);
        }
        avg = avg.divide(new BigDecimal(v.size()), RoundingMode.HALF_DOWN);
        System.out.println(">>> " + avg);

        BigDecimal pos = new BigDecimal(0),
            neg = new BigDecimal(0); 
        for (BigDecimal i: v) {
            BigDecimal aux = i.subtract(avg);
            if (aux.compareTo(new BigDecimal(0)) == 1) {
                pos = pos.add(aux);
            } else {
                neg = neg.subtract(aux);
            }
        }

        if (pos.subtract(neg).abs().compareTo(new BigDecimal("0.1")) == 1) {
            return pos.add(neg).divide(new BigDecimal(2), RoundingMode.DOWN).setScale(2, RoundingMode.DOWN);
        } else {
            return pos.min(neg).setScale(2, RoundingMode.DOWN);
            }
    }

    public static void main(String args[]) {
        int n;
        List<BigDecimal> v 
            = new ArrayList<BigDecimal>();
        Scanner in = new Scanner(System.in);
        DecimalFormat formatter = (DecimalFormat)DecimalFormat.getInstance(new Locale("en_US"));
        DecimalFormatSymbols symbols = formatter.getDecimalFormatSymbols();
        symbols.setGroupingSeparator('#');
        formatter.setDecimalFormatSymbols(symbols);
        in.useLocale(new Locale("C"));
        n = in.nextInt();
        while(n != 0) {
            for (int i = 0; i < n; i++){
                v.add(in.nextBigDecimal());
            }
            BigDecimal bd = work(v);
            long remainder = bd.multiply(new BigDecimal(100)).longValue() % 100;
            System.out.println("$" + formatter.format(bd.longValue()).replace("#", "") + "." + String.format("%02d", new Integer((int)remainder)));
            v.clear();
            n = in.nextInt();
        }
    }

    private static MathContext mathContext
        = new MathContext(3, RoundingMode.DOWN);
}
