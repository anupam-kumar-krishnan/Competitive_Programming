import java.io.DataInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class C651 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        int n = scan.nextInt();
        int[][] a = new int[n][2];
        int[][] b = new int[n][2];
        Map<String, Integer> equal = new HashMap<>();

        for(int i=0;i<n;i++) {
            a[i][0] = scan.nextInt();
            a[i][1] = scan.nextInt();
            b[i][0] = a[i][0];
            b[i][1] = a[i][1];
            if(equal.containsKey("" + a[i][0] + a[i][1])) {
                equal.put("" + a[i][0] + a[i][1], equal.get("" + a[i][0] + a[i][1]) + 1);
            }else {
                equal.put("" + a[i][0] + a[i][1], 1);
            }
        }

        Arrays.sort(a, Comparator.comparingInt(c -> c[0]));
        Arrays.sort(b, Comparator.comparingInt(c -> c[1]));

        long count = 1;
        long ans = 0;
        for(int i=1;i<n;i++) {
            if(a[i][0] == a[i-1][0])
                count++;
            else  {
                ans += ((count * (count - 1))/2);
                count =1;
            }
        }
        ans += ((count * (count - 1))/2);
        count = 1;
        for(int i=1;i<n;i++) {
            if(b[i][1] == b[i-1][1])
                count++;
            else  {
                ans += ((count * (count - 1))/2);
                count =1;
            }
        }
        ans += ((count * (count - 1))/2);

        long[] temp = {0};
        equal.forEach((k, v) -> {
            temp[0] += ((long) v * (v - 1))/2;
        });
        ans -= temp[0];
        System.out.println(ans);
    }
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
