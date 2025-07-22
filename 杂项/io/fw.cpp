struct Fwrite {
    char pbuf[1 << 20], *pp = pbuf;

    ~Fwrite () {
        fwrite(pbuf, 1, pp - pbuf, stdout);
    }

    void push(const char &c) { // 字符
        if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
        *pp++ = c;
    }

    void str(const string &s) {
        for (auto ch : s) push(ch);
    }

    void i64(long long x) {
        static long long sta[65];
        int top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }

    void i32(int x) {
        static int sta[35];
        int top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }
} fw;
// 使用举例
// #define Yes (fw.str("YES\n"))
// #define No (fw.str("NO\n"))
// Yes
// No