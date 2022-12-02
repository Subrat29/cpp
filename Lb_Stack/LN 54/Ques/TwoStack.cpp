#include <bits/stdc++.h>
using namespace std;

class TwoStack {
    int *arr;
    int size;
    int top1;
    int top2;
    
public:
    
    // Initialize TwoStack.
    TwoStack(int s) {
        arr = new int[s];   // this is wrong syntax arr = new int(s);
        this->size = s;
        top1 = -1;
        top2 = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0)
        {
            int ans = arr[top1]; // to return pop element
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    TwoStack st(5);

    st.push1(1);
    st.push1(2);
    st.push1(3);    
    st.push1(4);
    st.push2(5);

    st.pop1();
    st.pop2();
    st.pop1();

    return 0;
}