class MinStack 
{
    Stack<Integer> s = new Stack<>();
    Stack<Integer> min = new Stack<>();
    public void push(int a) 
    {
        s.push(a);
        if(min.isEmpty())
            min.push(a);
        else if(a <= min.peek())
            min.push(a);
    }

    public void pop() 
    {
        if(!s.isEmpty())
        {
            if(s.pop()<=min.peek())
                min.pop();
        }
    }

    public int top() 
    {
        if(s.isEmpty())
            return -1;
        return s.peek();
    }

    public int getMin() 
    {
        if(min.isEmpty())
            return -1;
        return min.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
