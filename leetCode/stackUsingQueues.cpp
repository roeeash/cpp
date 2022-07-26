class MyStack
{
public:
    queue<int> qIn;
    queue<int> qOut;

    MyStack()
    {
    }

    void push(int x)
    {
        qIn.push(x);
    }

    int pop()
    {
        int val;
        while (qIn.size() > 1)
        {
            qOut.push(qIn.front());
            qIn.pop();
        }
        // top
        val = qIn.back();
        qIn.pop();

        while (!qOut.empty())
        {
            qIn.push(qOut.front());
            qOut.pop();
        }

        // cout<<"val = "<<val<<endl;

        return val;
    }

    int top()
    {
        return qIn.back();
    }

    bool empty()
    {
        return (qIn.empty() && qOut.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */