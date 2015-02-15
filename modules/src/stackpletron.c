int mem[100], i, a, bias = 0, top = 100, operand, operation;
int imax=0;

void simpletron_load(int debug){
    i = 0;
    do{
        if(debug){
            printf("%d ?\t",i);
        }
        scanf("%d", &mem[i]);
    }while(mem[i] != -99999 && ++i <= 100);
    imax = i;
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
        if(operation < 0) operation *= -1;
        if(debug){
            printf("%d\toperation: %d\toperand: %d",i,operation,operand);
        }
        switch(operation){
            case 10:
                if(debug){
                    printf("\t(read from concole to %d + %d)\n", operand, bias);
                }
                printf("input a number: ");
                scanf("%d", &mem[operand + bias]);
                if(debug){
                    printf("inputed %d to %d + %d\n", mem[operand + bias], operand, bias);
                }
                ++i;
                break;
            case 11:
                if(debug){
                    printf("\t(write %d to concole from %d + %d)\n", mem[operand + bias], operand,bias);
                }
                printf("%d", mem[operand + bias]);
                if(debug){
                    printf("\n");
                }
                ++i;
                break;
            case 20:
                if(debug){
                    printf("\t(load %d from %d + %d to A)\n", mem[operand + bias], operand, bias);
                }
                a = mem[operand + bias];
                ++i;
                break;
            case 21:
                if(debug){
                    printf("\t(store %d from A to %d + %d)\n", a, operand, bias);
                }
                mem[operand + bias] = a;
                ++i;
                break;
            case 22:
                if(debug){
                    printf("\t(load %d from Top to A)\n", top);
                }
                a = top;
                ++i;
                break;
            case 23:
                if(debug){
                    printf("\t(store %d from A to Top)\n", a);
                }
                top = a;
                ++i;
                break;
            case 24:
                if(debug){
                    printf("\t(load %d from Bias to A)\n", bias);
                }
                a = bias;
                ++i;
                break;
            case 25:
                if(debug){
                    printf("\t(store %d from A to Bias)\n", a);
                }
                bias = a;
                ++i;
                break;
            case 26:        //PUSH
                if(debug){
                    printf("\t(Push %d from A to stack(%d)). Bias %d.\n", a, top - 1, bias);
                }
                if(top <= imax){
                    printf("Stack overflow %d", top);
                    return -1;
                }
                mem[--top] = a;
                ++i;
                break;
            case 27:        //POP
                if(debug){
                    printf("\t(Pop %d from stack(%d) to A). Bias %d.\n", mem[top], top, bias);
                }
                if(top >= 100){
                    printf("Stask is empty %d", top);
                    return -1;
                }
                a = mem[top++];
                ++i;
                break;
            case 30:
                if(debug){
                    printf("\t(add to A(%d) %d from %d + %d)\n", a, mem[operand + bias], operand, bias);
                }
                a += mem[operand + bias];
                ++i;
                break;
            case 31:
                if(debug){
                    printf("\t(substract from A(%d) %d from %d + %d)\n", a, mem[operand + bias], operand, bias);
                }
                a -= mem[operand + bias];
                ++i;
                break;
            case 32:
                if(debug){
                    printf("\t(divisin A(%d) on %d from %d + %d)\n", a, mem[operand + bias], operand, bias);
                }
                a /= mem[operand] + bias;
                ++i;
                break;
            case 33:
                if(debug){
                    printf("\t(multiply A(%d) on %d from %d + %d)\n", a, mem[operand + bias], operand, bias);
                }
                a *= mem[operand + bias];
                ++i;
                break;
            case 34:        //LITERAL
                if(debug){
                    printf("\t(put %d from command to A)\n", operand);
                }
                a = operand;
                ++i;
                break;
            case 40:
                if(debug){
                    printf("\t(goto %d). Top %d. Bias %d.\n", operand, top, bias);
                }
                i = operand;
                break;
            case 41:
                if(debug){
                    printf("\t(if(%d < 0) goto %d). Top %d. Bias %d.\n", a, operand, top, bias);
                }
                if(a < 0){
                    i = operand;
                }else{
                    ++i;
                }
                break;
            case 42:
                if(debug){
                    printf("\t(if(%d == 0) goto %d). Top %d. Bias %d.\n", a, operand, top, bias);
                }
                if(a == 0){
                    i = operand;
                }else{
                    ++i;
                }
                break;
            case 43:
                if(debug){
                    printf("\t(HALT). Top %d. Bias %d.\n", i, mem[operand], operand, top, bias);
                }
                return(0);
            case 44:        //CALL
                if(debug){
                    printf("\t(Call %d). Top %d. Bias %d.\n", operand, top, bias);
                }
                if(top <= imax){
                    printf("Stack overflow %d", top);
                    return -1;
                }
                mem[--top] = i;
                i = operand;
                break;
            case 45:        //RETURN
                if(debug){
                    printf("\t(Return to %d (%d). Push %d. Top[%d,%d,%d]=[%d,%d,%d]. Bias %d.)\n", mem[top], top, operand,  top-1,top,top+1,mem[top-1],mem[top],mem[top+1],bias);
                }
                if(top + operand >= 100){
                    printf("Stask is empty %d", top);
                    return -1;
                }
                i = mem[top] + 1;
                top += operand + 1;
                break;
            default:
                printf("\twrong operation %d at %d\n", mem[i], i);
                if(mem[i] == -99999) return(0);
                if(i > 100) return -1;
                ++i;

        }
    }while(1==1);
}
