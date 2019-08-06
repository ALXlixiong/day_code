class MyStack {
    public:
        /** Initialize your data structure here. */
        MyStack() {}

        /** Push element x onto stack. */
        void push(int x) {
            if(q1.empty())
                q2.push(x);
            else
                q1.push(x);

        }

        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            if(!q1.empty())
            {
                while(q1.size() != 1)
                {
                    q2.push(q1.front());
                    q1.pop();

                }
                int tmp = q1.front();
                q1.pop();
                return tmp;

            }
            else
            {
                while(q2.size() != 1)
                {
                    q1.push(q2.front());
                    q2.pop();

                }
                int tmp = q2.front();
                q2.pop();
                return tmp;

            }

        }

        /** Get the top element. */
        int top() {
            if(!q1.empty())
            {
                while(q1.size() != 1)
                {
                    q2.push(q1.front());
                    q1.pop();

                }
                int tmp = q1.front();
                q2.push(q1.front());
                q1.pop();
                return tmp;

            }
            else
            {
                while(q2.size() != 1)
                {
                    q1.push(q2.front());
                    q2.pop();

                }
                int tmp = q2.front();
                q1.push(q2.front());
                q2.pop();
                return tmp;

            }

        }

        /** Returns whether the stack is empty. */
        bool empty() {
            return q1.empty() && q2.empty();

        }
    private:
        queue<int> q1;
        queue<int> q2;

};

/**
 *  * Your MyStack object will be instantiated and called as such:
 *   * MyStack* obj = new MyStack();
 *    * obj->push(x);
 *     * int param_2 = obj->pop();
 *      * int param_3 = obj->top();
 *       * bool param_4 = obj->empty();
 *        */
