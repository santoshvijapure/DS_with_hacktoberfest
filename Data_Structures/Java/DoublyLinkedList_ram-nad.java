import java.util.Iterator;

class DoublyLinkedList<E> implements Iterable<E> {

    public class Node {

        private E data;

        public Node prev;
        public Node next;

        public Node() {
            this.data = null;
            this.prev = null;
            this.next = null;
        }

        public void setData(E data) {
            this.data = data;
        }

        public void deleteData() {
            this.data = null;
        }

        public E getData() {
            return this.data;
        }

        public void delete() {
            if (this.prev != null) {
                this.prev.next = this.next;
            }
            if (this.next != null) {
                this.next.prev = this.prev;
            }
            this.next = null;
            this.prev = null;
            this.deleteData();
        }

        @Override
        public String toString() {
            return ("Node: " + data.toString());
        }

    }

    private Node head;

    DoublyLinkedList() {
        this.head = null;
    }

    public boolean isEmpty() {
        return (this.head == null);
    }

    public void addNode(E data) {
        if (this.head == null) {
            this.head = new Node();
            this.head.setData(data);
        } else {
            Node ptr = head;
            while (ptr.next != null) {
                ptr = ptr.next;
            }
            ptr.next = new Node();
            ptr.next.prev = ptr;
            ptr.next.setData(data);
        }
    }

    public Node search(E data) {
        if (this.head == null) {
            return null;
        }
        Node ptr = head;
        while (ptr != null) {
            if (data.equals(ptr.getData())) {
                return ptr;
            }
            ptr = ptr.next;
        }
        return null;
    }

    public void deleteNode(Node n) {
        if (n == null) {
            return;
        }
        if (this.head == n) {
            this.head = n.next;
            n.delete();
        } else {
            Node ptr = this.head;
            while (ptr != null) {
                if (ptr == n) {
                    n.delete();
                    return;
                } else {
                    ptr = ptr.next;
                }
            }
        }
    }

    public class DLIterator implements Iterator<E> {

        private Node next;

        DLIterator() {
            next = head;
        }

        @Override
        public boolean hasNext() {
            if (next == null) {
                return false;
            }
            return true;
        }

        @Override
        public E next() {
            if (next != null) {
                E data = next.getData();
                next = next.next;
                return data;
            }
            return null;
        }
    }

    @Override
    public Iterator<E> iterator() {
        return new DLIterator();
    }

    public static void main(String args[]) {
        DoublyLinkedList<String> list = new DoublyLinkedList<String>();

        list.addNode("Hello");
        list.addNode("This");
        list.addNode("Is");
        list.addNode("Test!");

        System.out.println("Data in List: ");
        for (String i : list) {
            System.out.println(i);
        }

        System.out.println("Found: " + list.search("Is"));

        list.deleteNode(list.search("Hello"));

        System.out.println("After deleting `Hello`");
        for (String i : list) {
            System.out.println(i);
        }
    }

}