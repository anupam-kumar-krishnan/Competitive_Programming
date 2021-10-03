import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class C1454 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        PrintWriter p = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int t = scan.nextInt();
        while (t-- > 0) {
            int n = scan.nextInt();
            int[] a = new int[n];

            for(int i=0;i<n;i++) {
                a[i] = scan.nextInt();
            }

            int[] h = new int[n];
            System.arraycopy(a, 0, h, 0, n);
            Arrays.sort(h);

            int countMin = n+1, res = -1, count = 1;
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i - 1])
                    count++;
                else {
                    if (count < countMin) {
                        countMin = count;
                        res = a[i - 1];
                    }
                    count = 1;
                }
            }
            if (count < countMin) {
                res = a[n - 1];
            }

            int ans = 0;
            for(int i=0;i<n;i++) {
                if(a[i] == res) {
                    for(int j = i+1;j<n;j++) {
                        if(a[j] == res) {
                            if(j - i > 1) {
                                ans++;
                            }
                            i = j - 1;
                            break;
                        }
                    }
                }
            }
            if(a[0] != res)
                ans++;
            if(a[n-1] != res)
                ans++;
            sb.append(ans).append('\n');
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
