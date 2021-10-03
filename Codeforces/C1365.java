import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class C1365 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        int n = scan.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];

        int[] posA = new int[n+1];
        for(int i=0;i<n;i++) {
            a[i] = scan.nextInt();
            posA[a[i]] = i;
        }
        int[] posB = new int[n+1];
        for(int i=0;i<n;i++) {
            b[i] = scan.nextInt();
            posB[b[i]] = i;
        }

        System.out.println(Math.max(leftR(a, b, posA, posB, n), rightR(a, b, posA, posB, n)));
    }
    static int leftR(int[] a, int[] b, int[] posA, int[] posB, int n) {
        int max = -1;
        int[] shifts = new int[n];
        for(int i=0;i<n;i++) {
            shifts[(posA[b[i]] - i + n) % n]++;
        }

        for(int i=0;i<n;i++) {
            if(shifts[i] > max) {
                max = shifts[i];
            }
        }
        return max;

    }
    static int rightR(int[] a, int[] b, int[] posA, int[] posB, int n) {
        int max = -1;
        int[] shifts = new int[n];
        for(int i=0;i<n;i++) {
            shifts[(posB[a[i]] - i + n) % n]++;
        }

        for(int i=0;i<n;i++) {
            if(shifts[i] > max) {
                max = shifts[i];
            }
        }
        return max;
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
