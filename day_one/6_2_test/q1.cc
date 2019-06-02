class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        while(1)
        {
            if(a>b)
                a = a/2;
            else if(a<b)
                b = b/2;
            else
                break;
        }
        return a;
    }
};
