static int rnd;

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


int myRandom(){
    int a=4096, c=150889, m=714025;
    rnd = (a * rnd + c) % m;
    return rnd;
}

void initMyRandom(int start){
    rnd = start;
}

int indexOfInt(int a, int *arr, int sz){
    for(int i=0; i<sz; ++i){
        if(a == arr[i]) return i;
    }
    return -1;
}

void displayArrayInt(int *arr, int sz){
    for(int i=0; i<sz; ++i){
        printf("%d ",arr[i]);
    }
}

int maxInt(int *arr, int sz){
    int m = arr;
    for(int i=1; i<sz; ++i){
        if(arr[i]>m) m = arr[i];
    }
    return m;
}

int minInt(int *arr, int sz){
    int m = arr;
    for(int i=1; i<sz; ++i){
        if(arr[i]<m) m = arr[i];
    }
    return m;
}
