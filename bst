public class Iterator {

    private Stack<Node> stack = new Stack<>();
    private Node current;

    private Iterator(Node argRoot) {
        current = argRoot;
    }

    public Node next() {
        while (current != null) {
            stack.push(current);
            current = current.left;
        }

        current = stack.pop();
        Node node = current;
        current = current.right;

        return node;
    }

    public boolean hasNext() {
        return (!stack.isEmpty() || current != null);
    }

    public static Iterator iterator(Node root) {
        return new Iterator(root);
    }
}
