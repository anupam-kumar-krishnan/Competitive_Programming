import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class C546 {
    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        PrintWriter p = new PrintWriter(System.out);

        int n = scan.nextInt();
        Deque<Integer> a = new ArrayDeque<>();
        int k1 = scan.nextInt();
        for(int i=0;i<k1;i++) {
            int temp = scan.nextInt();
            a.offerLast(temp);
        }
        Deque<Integer> b = new ArrayDeque<>();
        int k2 = scan.nextInt();
        for(int i=0;i<k2;i++) {
            int temp = scan.nextInt();
            b.offerLast(temp);
        }

        int ans = 0;
        int max = 1;
        for(int i=2;i<=n;i++) {
            max *= i;
        }
        while(!a.isEmpty() && !b.isEmpty()) {
            int f = a.pollFirst();
            int s = b.pollFirst();
            ans++;

            if(f > s) {
                a.offerLast(s);
                a.offerLast(f);
            }else {
                b.offerLast(f);
                b.offerLast(s);
            }
            if(ans > max) {
                p.print(-1);
                p.close();
                return;
            }
        }
        p.print(ans + " ");
        if(a.isEmpty()) {
            p.print(2);
        }else {
            p.print(1);
        }
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
