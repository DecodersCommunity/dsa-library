import java.util.ArrayDeque;
import java.util.Deque;


public class DequeDemo extends Thread{

    public static Deque<Integer> deque;

    public static void main(String[] args) throws InterruptedException {
        deque = new ArrayDeque<>();

        //add at last
        deque.add(1);
        //deque : 1

        //add at first
        deque.addFirst(3);
        //deque : 3 -> 1

        //add at last
        deque.addLast(2);
        //deque: 3 -> 1 -> 2

        //add at last
        deque.add(4);
        //deque : 3 -> 1 -> 2 -> 4

        //remove at first
        deque.removeFirst();
        //deque : 1 -> 2 -> 4

        deque.forEach(a -> System.out.print(a+"->"));
        System.out.println();

    }
}
