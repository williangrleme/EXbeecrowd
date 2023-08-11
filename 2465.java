import java.util.*;

public class Main {
    static class aluno {
        int camisa;
        int grau=0;
        int ant[] = new int[2]; 
        boolean bolinha=false;
        boolean bandeira=false;
    }

    public static void main(String[] args) throws Exception {
        int n,i,j,primeira_linha,primeira_coluna;
        int v[] = new int[2];

        Scanner ler = new Scanner(System.in);

        n = ler.nextInt();
        aluno m[][]  = new aluno[n][n];
        primeira_linha = ler.nextInt();
        primeira_coluna = ler.nextInt();

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                m[i][j] = new aluno();
                m[i][j].camisa = ler.nextInt();
            }
        }
        ler.close();
        m[primeira_linha-1][primeira_coluna-1].bandeira = true;
        m[primeira_linha-1][primeira_coluna-1].bolinha = true;

        while(m[primeira_linha-1][primeira_coluna-1].grau  < 4){
            v = achar_bolinha(m, n);        
            if(m[v[0]][v[1]].grau == 0){
                m[v[0]][v[1]].grau++;
                if((v[1]+1)<n){ //ver se n ultrapassa o tamanho
                    if((m[v[0]][v[1]+1].camisa >= m[v[0]][v[1]].camisa) && (m[v[0]][v[1]+1].bandeira == false)){ //se eh maior, se bandeira ta abaixa
                        m[v[0]][v[1]].bolinha= false;   //tirando a bolinha
                        m[v[0]][v[1]+1].bolinha = true; //dando a bolinha
                        m[v[0]][v[1]+1].bandeira = true;    //levantando a bandeira
                        m[v[0]][v[1]+1].ant[0] = v[0];      //guardando a posicao de quem passou a bolinha 
                        m[v[0]][v[1]+1].ant[1] = v[1];      //guardando a posicao de quem passou a bolinha
                    }
                }
            }
            else {
                if(m[v[0]][v[1]].grau == 1){
                    m[v[0]][v[1]].grau++;
                    if((v[0]+1)<n){
                        if((m[v[0]+1][v[1]].camisa >= m[v[0]][v[1]].camisa) && (m[v[0]+1][v[1]].bandeira == false)){
                            m[v[0]][v[1]].bolinha= false;
                            m[v[0]+1][v[1]].bolinha = true;
                            m[v[0]+1][v[1]].bandeira = true;
                            m[v[0]+1][v[1]].ant[0] = v[0];
                            m[v[0]+1][v[1]].ant[1] = v[1];
                        }
                    }
                }
                else{
                    if(m[v[0]][v[1]].grau == 2){
                        m[v[0]][v[1]].grau++;
                        if((v[1]-1)>=0){
                            if((m[v[0]][v[1]-1].camisa >= m[v[0]][v[1]].camisa) && (m[v[0]][v[1]-1].bandeira == false)){
                                m[v[0]][v[1]].bolinha= false;
                                m[v[0]][v[1]-1].bolinha = true;
                                m[v[0]][v[1]-1].bandeira = true;
                                m[v[0]][v[1]-1].ant[0] = v[0];
                                m[v[0]][v[1]-1].ant[1] = v[1];
                            }
                        }
                    }
                    else {
                        if(m[v[0]][v[1]].grau == 3){
                            m[v[0]][v[1]].grau++;
                            if((v[0]-1)>=0){
                                if((m[v[0]-1][v[1]].camisa >= m[v[0]][v[1]].camisa) && (m[v[0]-1][v[1]].bandeira == false)){
                                    m[v[0]][v[1]].bolinha= false;
                                    m[v[0]-1][v[1]].bolinha = true;
                                    m[v[0]-1][v[1]].bandeira = true;
                                    m[v[0]-1][v[1]].ant[0]= v[0];
                                    m[v[0]-1][v[1]].ant[1] = v[1];
                                }
                                else{
                                    m[m[v[0]][v[1]].ant[0]][m[v[0]][v[1]].ant[1]].bolinha = true;   //devolve a bolinha
                                    m[v[0]][v[1]].bolinha = false;      //tira a bolinha do meliante
                                }
                            }
                        }
                        else{
                            if(m[v[0]][v[1]].grau >= 4){
                                m[m[v[0]][v[1]].ant[0]][m[v[0]][v[1]].ant[1]].bolinha = true;   //devolve a bolinha
                                m[v[0]][v[1]].bolinha = false;      //tira a bolinha do meliante
                            }
                        }
                    }
                }
            }
        }   
        contar(m, n);
    }


    public static void contar(aluno m[][],int n){
        int i,j,b=0;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(m[i][j].bandeira == true){
                    b++;
                }
            }
        }
        System.out.printf("%d\n",b);
    }

    public static int[] achar_bolinha(aluno m[][],int n){
        int i,j;
        int v[] = new int[2];  //matriz paraguardar posicao

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(m[i][j].bolinha == true){
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }

}
