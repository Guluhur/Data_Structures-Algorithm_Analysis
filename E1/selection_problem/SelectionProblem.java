//: SelectionProblem.java
import java.util.*;

/** 找到一数组按从小到大排列后的第k个元素
 * @author Guluhur
 * @date 2020/10/5
 * @version 1.0
 */

public class SelectionProblem {
    private static final int N = 8182, MAX = 1000;
    private static int k = N/2;

    public static void printArray(int[] array) {
        System.out.println("Array = [");
        for(int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");
            if((i+1)%10 == 0) System.out.println();
        }
        System.out.println("]");
    }

    public static void selectSoft(int[] array, int softLength) {
        for(int i = 0; i < softLength; i++) {
            int idx = i;
            for(int j = i+1; j < array.length; j++)
                if(array[idx] > array[j]) idx = j;
            if(idx != i) {
                int tmp = array[idx];
                array[idx] = array[i];
                array[i] = tmp;
            }
        }
    }

    public static void main(String[] args) {
        int[] ary = new int[N];
        Random rand = new Random(11);
        for(int i = 0; i < ary.length; i++)
            ary[i] = rand.nextInt(MAX) + 1;
        //printArray(ary);
        Date beginT = new Date();
        selectSoft(ary, k);
        Date endT = new Date();
        //printArray(ary);
        System.out.println("Element[" + k + "] = " + ary[k-1]);
        System.out.println("Cost: " + (endT.getTime() - beginT.getTime()) + "ms");
    }
}   /* Output(50% match):
Element[4091] = 499
Cost: 22ms
*///:~
