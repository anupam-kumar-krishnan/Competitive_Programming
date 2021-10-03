import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class C1353 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        PrintWriter p = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder();

        int t = scan.nextInt();
        while (t-- > 0) {
            int n = scan.nextInt();
            long ans = 0;

            long count = 1;
            for(int i=0;i<=n/2;i++) {
                ans += i * ((count << 2) - 4);
                count += 2;
            }
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
