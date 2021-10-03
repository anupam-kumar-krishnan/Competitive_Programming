import java.io.DataInputStream;
import java.io.IOException;
import java.util.Arrays;

public class D1419 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        StringBuilder sb = new StringBuilder();
        int n = scan.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }

        Arrays.parallelSort(a);

        int count = 0;
        for (int i = 1; i < n-1; i += 2) {
            swap(a, i, i - 1);
            count++;
        }

        sb.append(count).append('\n');
        for (int i = 0; i < n; i++) {
            sb.append(a[i]).append(' ');
        }
        System.out.println(sb);
    }
    static void swap(int[] a,int i,int j) {
        a[i] = a[i] ^ a[j];
        a[j] = a[i] ^ a[j];
        a[i] = a[i] ^ a[j];
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
