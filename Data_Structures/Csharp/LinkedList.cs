using System;
using System.IO;

namespace DataStructures
{
    public class LinkedList<T>
    {
        public class Node<T1>
        {
            public T1 Value { get; set; }
            public Node<T1> Next { get; set; }
        }
        private Node<T> Head { get; set; }

        public Node<T> Push(T value)
        {
            var newNode = new Node<T> { Value = value, Next = Head };
            Head = newNode;
            return newNode;
        }

        public Node<T> InsertAfter(T value, Node<T> prevNode)
        {
            if (prevNode == null)
                throw new ArgumentNullException(nameof(prevNode));
            var newNode = new Node<T> { Value = value, Next = prevNode.Next };
            prevNode.Next = newNode;
            return newNode;
        }

        public Node<T> Tail 
        {
            get
            {
                if (Head == null)
                    return null;
                var last = Head;
                while(last.Next != null)
                {
                    last = last.Next;
                }
                return last;
            }
        }

        public Node<T> Append(T value)
        {
            var newNode = new Node<T> { Value = value, Next = null };
            if (Head == null)
            {
                Head = newNode;
                return Head;
            }
            Tail.Next = newNode;
            return newNode;
        }


        public void Print(TextWriter io)
        {
            var node = Head;
            while(node != null)
            {
                io.Write($"{node.Value} ");
                node = Head.Next;
            }
        }
    }
}
