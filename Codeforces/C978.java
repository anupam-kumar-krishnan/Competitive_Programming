import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class C978 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        PrintWriter p = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int n = scan.nextInt();
        int m = scan.nextInt();

        long[] a = new long[n];
        long[] prefix = new long[n];

        for(int i=0;i<n;i++) {
            a[i] = scan.nextLong();
            if(i == 0)
                prefix[i] = a[i];
            else
                prefix[i] = a[i] + prefix[i-1];
        }

        while(m-- > 0) {
            long key = scan.nextLong();
            int left = 0;
            int right = n-1;

            int ans = -1;
            while(left <= right) {
                int mid = left + (right - left)/2;

                if(prefix[mid] == key) {
                    ans = mid;
                    break;
                }else if(prefix[mid] > key) {
                    ans = mid;
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }
            int dor = ans+1;
            long room = (ans > 0)?key - prefix[ans - 1]: key;
            room = room % a[ans];
            if(room == 0)
                room = a[ans];

            sb.append(dor).append(' ');
            sb.append(room).append('\n');
        }
        p.print(sb);
        p.close();
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

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
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
