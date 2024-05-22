int mostWordsFound(char ** sentences, int sentencesSize){
    int max=0;
    int space=0;
    for(int i=0 ; i<sentencesSize ; i++){
        for(int x=0 ; x<strlen(sentences[i]) ; x++){
            if(sentences[i][x]==' '){
                space++;
            }
        }
        if(max<space+1){
            max=space+1;
        }
        space=0;
    }
    return max;

}