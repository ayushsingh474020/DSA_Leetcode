int finalValueAfterOperations(char ** operations, int operationsSize){
    int x=0;
    for(int i=0 ; i<operationsSize ; i++){
        
            if(operations[i][0]=='X' && operations[i][1]=='+' && operations[i][2]=='+'){
                x++;
            }
            else if(operations[i][0]=='X' && operations[i][1]=='-' && operations[i][2]=='-'){
                x--;
            }
            else if(operations[i][0]=='+' && operations[i][1]=='+' && operations[i][2]=='X'){
                ++x;
            }
            else if(operations[i][0]=='-' && operations[i][1]=='-' && operations[i][2]=='X'){
                --x;
            }
        
    }
    return x;

}