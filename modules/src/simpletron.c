int mem[100], i, a, operand, operation;

void simpletron_load(int debug){
    i = 0;
    do{
        if(debug){
            printf("%d ?\t",i);
        }
        scanf("%d", &mem[i]);
    }while(mem[i] != -99999 && ++i < 100);
}

void simpletron_print(){
    i = 0;
    do{
        printf("%d ?\t%d\n",i, mem[i]);
    }while(mem[i] != -99999 && ++i < 100);
}

void simpletron_run(int debug){
    i=0;
    do{
        operand = mem[i] % 100;
        operation = mem[i] / 100;
        if(debug){
            printf("%d\toperation: %d\toperand: %d",i,operation,operand);
        }
        switch(operation){
            case 10:
                if(debug){
                    printf("\t(read from concole to %d)\n", operand);
                }
                printf("input a number: ");
                scanf("%d", &mem[operand]);
                if(debug){
                    printf("inputed %d to %d\n", mem[operand], operand);
                }
                ++i;
                break;
            case 11:
                if(debug){
                    printf("\t(write %d to concole from %d)\n", mem[operand], operand);
                }
                printf("%d", mem[operand]);
                if(debug){
                    printf("\n");
                }
                ++i;
                break;
            case 20:
                if(debug){
                    printf("\t(load %d from %d to A)\n", mem[operand], operand);
                }
                a = mem[operand];
                ++i;
                break;
            case 21:
                if(debug){
                    printf("\t(store %d from A to %d)\n", a, operand);
                }
                mem[operand] = a;
                ++i;
                break;
            case 30:
                if(debug){
                    printf("\t(add to A(%d) %d from %d)\n", a, mem[operand], operand);
                }
                a += mem[operand];
                ++i;
                break;
            case 31:
                if(debug){
                    printf("\t(substract from A(%d) %d from %d)\n", a, mem[operand], operand);
                }
                a -= mem[operand];
                ++i;
                break;
            case 32:
                if(debug){
                    printf("\t(divisin A(%d) on %d from %d)\n", a, mem[operand], operand);
                }
                a /= mem[operand];
                ++i;
                break;
            case 33:
                if(debug){
                    printf("\t(multiply A(%d) on %d from %d)\n", a, mem[operand], operand);
                }
                a *= mem[operand];
                ++i;
                break;
            case 40:
                if(debug){
                    printf("\t(goto %d)\n", operand);
                }
                i = operand;
                break;
            case 41:
                if(debug){
                    printf("\t(if(%d < 0) goto %d)\n", a, operand);
                }
                if(a < 0){
                    i = operand;
                }else{
                    ++i;
                }
                break;
            case 42:
                if(debug){
                    printf("\t(if(%d == 0) goto %d)\n", a, operand);
                }
                if(a == 0){
                    i = operand;
                }else{
                    ++i;
                }
                break;
            case 43:
                if(debug){
                    printf("\t(HALT)\n", i, mem[operand], operand);
                }
                return(0);
            default:
                printf("wrong operation %d at %d\n", mem[i], i);
                if(mem[i] == -99999) return(0);
                ++i;

        }
    }while(1==1);
}
