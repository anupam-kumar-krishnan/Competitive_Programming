// Node class is necessary because on its basis we are creating the linked list
class Node{
    // Data members
    int data;
    Node next;
    Node (){data = 0; next = null;}
    // Constructor
    Node(int d){
        data = d;
        next = null;
    }
}

// This is the class where we are defining the linked list to be circular in nature
class CircularLinkedList{
    // Data members
    Node head, last, list;
    // Constructor
    CircularLinkedList(){
        head = null;
        last = null;

    }
    // Getters and Setters
    public Node getList()
    {
        return list;
    }

    public void setList(Node list) {
        this.list = list;
        }

    //This is the method which used to insert the node inside the list
    // Here we are not only adding the list but also sorting it.
    // The sorting mechanism is working in a sense that It use to first check
    // the previous node values and then on its basis it is adding the next value.
    public void sortAndInsert(Node node){
        //Checking for the first node
        if (check(node.data)){
            if(head == null && last == null){ // step 1.
                node.next = node;
                head = last = node;
                last.next = head;
            }
            //Checking if previous node data is greater than the new one
            else {

                if (node.data > last.data)
                {
                    node.next = last.next;
                    last.next = node;
                    last = node;
                }
                else
                {
                    Node insertionNode = head;
                    while (insertionNode != null && node.data >= insertionNode.next.data)
                    {
                        insertionNode = insertionNode.next;
                    }
                    if (head != null && node.data < head.data)
                    {
                        node.next = last.next;
                        last.next = node;
                        head = node;
                    }
                    else if (insertionNode != null && node.data >= insertionNode.data)
                    {
                        node.next = insertionNode.next;
                        insertionNode.next = node;
                    }
                }
            }
        }
        // Set function in the end returning head as a pointer for the next function call
        setList(head);
    }
    // This boolean method check for the duplicate node values.
    // based on the evaluation it's returns the true and false statement
    public boolean check(int num)
    {
        if (head != null) {
            Node curr = head;
            do {
                if (curr.data == num) {
                    return false;
                }
                curr = curr.next;
            } while (curr != null && curr != head);
        }
        return  true;
    }
}