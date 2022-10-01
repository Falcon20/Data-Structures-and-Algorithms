// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    int result = 0, count = 0;
    bool temp = false;
    while(N)
    {
        if(N%2)
        {
            if(temp)
            result = max(result, count);
            temp = true;
            count = 0;
        }
        else {
        count++;
        }
        N/=2;
    }
    return result;
}