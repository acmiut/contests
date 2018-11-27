import java.io.*;
import java.util.*;

public class aerodynamics_as implements Runnable {

    class Point3D {
        int x;
        int y;
        int z;

        Point3D(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    class Point {
        double x;
        double y;

        double ang;
        double len;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        Point sub(Point that) {
            return new Point(x - that.x, y - that.y);
        }

        double vp(Point that) {
            return x * that.y - y * that.x;
        }
    }

    final static double ANG_EPS = 1e-9;
    final static double LEN_EPS = 1e-9;

    long tFindMin = 0;
    long tCountAngLen = 0;
    long tSort = 0;
    long tStack = 0;
    long tArea = 0;

    double convexHull(ArrayList<Point> p) {
        int n = p.size();

        long time = System.currentTimeMillis();
        Point pp0 = p.get(0);
        for (int i = 1; i < n; i++) {
            if (p.get(i).y < pp0.y - LEN_EPS || Math.abs(p.get(i).y - pp0.y) < LEN_EPS && p.get(i).x < pp0.x) {
                pp0 = p.get(i);
            }
        }
        final Point p0 = pp0;

        tFindMin += System.currentTimeMillis() - time;

        time = System.currentTimeMillis();
        for (int i = 0; i < n; i++) {
            Point q = p.get(i);
            q.ang = Math.atan2(q.y - p0.y, q.x - p0.x);
            assert q.ang >= 0;

            q.len = (q.y - p0.y) * (q.y - p0.y) + (q.x - p0.x) * (q.x - p0.x);
        }
        tCountAngLen += System.currentTimeMillis() - time;

        time = System.currentTimeMillis();
        Collections.sort(p, new Comparator<Point>() {
            public int compare(Point p1, Point p2) {
                return p1.ang < p2.ang - ANG_EPS ? -1 : p1.ang > p2.ang + ANG_EPS ? 1 : p1.len < p2.len ? -1 : p1.len > p2.len ? 1 : 0;
            }
        });
        tSort += System.currentTimeMillis() - time;

        time = System.currentTimeMillis();
        ArrayList<Point> pc = new ArrayList<Point>();
        pc.add(p.get(0));
        for (int i = 1; i < n; i++) {
            if (Math.abs(p.get(i).ang - p.get(i - 1).ang) > ANG_EPS || Math.abs(p.get(i).len - p.get(i - 1).len) > LEN_EPS) {
                pc.add(p.get(i));
            }
        }
        p = pc;

        ArrayList<Point> stack = new ArrayList<Point>();
        stack.add(p.get(0));
        stack.add(p.get(1));
        for (int i = 2; i < p.size(); i++) {
            Point p1 = stack.get(stack.size() - 2);
            Point p2 = stack.get(stack.size() - 1);
            Point p3 = p.get(i);
            while (stack.size() > 1 &&
                    (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y) < 0) {
                stack.remove(stack.size() - 1);
                p2 = p1;
                p1 = stack.size() > 1 ? stack.get(stack.size() - 2) : null;
            }
            stack.add(p.get(i));
        }
        tStack += System.currentTimeMillis() - time;


        time = System.currentTimeMillis();
        double r = 0;
        for (int i = 1; i < stack.size(); i++) {
            r += stack.get(i - 1).sub(pp0).vp(stack.get(i).sub(pp0));
        }
        tArea += System.currentTimeMillis() - time;
        return r / 2;
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out, true);

        int n = in.nextInt();
        int zmin = in.nextInt();
        int zmax = in.nextInt();

        Point3D[] p = new Point3D[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Point3D(in.nextInt(), in.nextInt(), in.nextInt());
        }

        for (int z = zmin; z <= zmax; z++) {
            ArrayList<Point> pp = new ArrayList<Point>();
            for (int j = 0; j < n; j++) {
                if (p[j].z == z) {
                    pp.add(new Point(p[j].x, p[j].y));
                } else if (p[j].z < z) {
                    for (int k = 0; k < n; k++) {
                        if (p[k].z > z) {
                            pp.add(new Point(
                                    p[j].x + 1.0 * (p[k].x - p[j].x) * (z - p[j].z) / (p[k].z - p[j].z),
                                    p[j].y + 1.0 * (p[k].y - p[j].y) * (z - p[j].z) / (p[k].z - p[j].z)
                            ));
                        }
                    }
                }
            }
            if (pp.size() <= 2) {
            	out.printf("0.0\n");
            } else {
                out.printf("%.10f\n", convexHull(pp));
            }
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            System.exit(64);
        }
    }

    public static void main(String[] arg) throws IOException {
        Locale.setDefault(Locale.US);
        new Thread(new aerodynamics_as()).start();
    }
}
