int gcd(int a, int b){
    if(b == 0) return a;
    while(a%b != 0){
        int c = a%b;
        a = b; b = c;
    }
    return b;
}

int lcm(int a, int b){
    return a * (b / gcd(a,b));
}

char *_10tor(int a, int r, char *buff){
    int i=0, d;
    char c;
    while(a>0){
        d = a % r;
        buff[i] = d<10 ? '0'+d : 'A'+d%10;
        a /= r;
        i++;
    }
    for(--i,d=0;d<=i/2;++d){
        c = buff[d];
        buff[d] = buff[i-d];
        buff[i-d] = c;
    }
    return buff;
}
