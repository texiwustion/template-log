inline char nc(){
    static char buf[100000],*l=buf,*r=buf;
    return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline auto rd(){
    auto res=0,f=1;char ch=nc();
    while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
    while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
    return res*f;
}