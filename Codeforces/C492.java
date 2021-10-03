import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.*;

public class C492 {
    public static void main(String[] args) throws IOException {
//        long time = System.nanoTime();
        Reader scan = new Reader();
        int n = scan.nextInt();
        int r = scan.nextInt();
        int avg = scan.nextInt();

        long sumReq = (long)avg * n;

        long sum = 0;
        Map<Integer, List<Integer>> map = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();

            if(map.containsKey(b)) {
                map.get(b).add(a);
            }else {
                List<Integer> list = new LinkedList<>();
                list.add(a);
                map.put(b, list);
            }
            sum += a;
        }
        if (sum == sumReq) {
            System.out.print(0);
        } else {
            long diff = sumReq - sum;
            List<Integer> keys = new ArrayList<>(map.keySet());
            long count = 0;
            int i = 0;
            int m = keys.size();
            while (diff > 0 && i < m) {
                List<Integer> mark = map.get(keys.get(i));
                int temp = mark.get(0);
                mark.remove(0);
                long canAdd = r - temp;

                if (diff - canAdd > 0) {
                    diff -= canAdd;
                    count += canAdd * keys.get(i);
                } else {
                    count += diff * keys.get(i);
                    diff = 0;
                }
                if(mark.size() == 0)
                    i++;
            }
            System.out.println(count);
//            System.out.println(System.nanoTime() - time);
        }
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
