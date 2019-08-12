#include <iostream>
#include <vector>


bool JudgeIsTrue(std::vector<int> &v, int tot, int ret)
{
    if (v.empty())
        return tot == ret;

    for (int i = 0; i < v.size(); i++)
    {
        std::vector<int> cur(v);
        cur.erase(cur.begin() + i);
        if  (
                JudgeIsTrue(cur, tot, ret + v[i]) ||  
                JudgeIsTrue(cur, tot, ret - v[i])  || 
                JudgeIsTrue(cur, tot, ret * v[i])  || 
                JudgeIsTrue(cur, tot, ret / v[i])

            )
            return true;

    }
    return false;

}

int main()
{
    std::vector<double> v(4, 0);
    while (std::cin >> v[0] >> v[1] >> v[2] >> v[3])
    {
        bool ret = JudgeIsTrue(v, 0, 0);

    }
    return 0;

}
