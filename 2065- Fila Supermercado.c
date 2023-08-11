            #include <stdio.h>
            #include <stdlib.h>

            typedef struct funcionario {
                int tempo;
                int id;
                struct funcionario *prox;
            }funcionario;

            typedef struct cliente {
                int item;
                struct cliente *prox;
            }cliente;

            typedef	struct {
                funcionario *ini;
                funcionario *fim;
            }filaf;

            typedef struct {
                cliente *ini;
                cliente *fim;
            }filac;

            void criarf(filaf *f)
            {
                f->ini = NULL;
                f->fim = NULL;
            }

            void criarc(filac *f){
                f->ini=NULL;
                f->fim=NULL;
            }

            int inserirf(filaf *f,int t,int i)
            {
                funcionario *novo;
                novo = (funcionario *) malloc(sizeof(funcionario));
                novo->prox = NULL;
                novo->tempo = t; 
                novo->id = i;
                
                if(!novo) return 0;
                
                if(f->ini == NULL) f->ini = novo;
                else f->fim->prox = novo;
                f->fim = novo;
                return 1;

            }

            int inserirc(filac *f,int i){
                cliente *novo;
                novo = ( cliente *) malloc (sizeof(cliente));
                novo->item = i;
                novo->prox=NULL;

                if(!novo) return 0;

                if(f->ini == NULL) f->ini=novo;
                else f->fim->prox= novo;
                f->fim = novo;
                return 1;
            }

            int removerc (filac *f){
                cliente *aux;
                if (f->ini == NULL) {
                    exit(1);
                }
                aux = f->ini;
                f->ini = aux->prox;
                if (f->ini == NULL)
                    f->fim = NULL;
                free(aux);
                return 1;
            }

        int atender (filaf *ff, filac *fc, int f, int c){
        funcionario *auxf=ff->ini;
        cliente *auxc=fc->ini;
        int tempot = 0;
        int tp;

        if (f == c) {  // caso o numero de funcionarios e de cliente for igual, o tempo tp sera o maior tempo individual
            while ((auxf != NULL) && (auxc != NULL)){
                tp = auxf->tempo * auxc->item;
                if (tp > tempot){
                    tempot = tp;
                }
                auxf=auxf->prox;
                auxc=auxc->prox;
            }
        }

        if (c > f) {  // quando o numero de clientes for maior que o numero de funcionarios
        int pl = 0;  // só pra marcar a primeira leva
        int tt[f];
        int i = 0, menor;
            while (fc->ini != NULL){  // até todos os clientes serem atendidos
            while ( auxf != NULL && pl == 0){  // primeira leva
                auxc = fc->ini;  
                tp = auxf->tempo * auxc->item;
                tt[i] = tp;
                i++;
                removerc(fc);
                auxf = auxf->prox;
            }
            pl = 1;
            auxf = ff->ini;
            auxc = fc->ini;
            i = 0;
            menor = tt[i]; 
            while (auxf != NULL){ // achar o menor tt
                if (tt[i] <= menor){
                    menor = tt[i];
                }
                auxf =  auxf->prox;
                i++;
            }
            for (i=0;tt[i] != menor;i++);  // achar o indice do menor tt
            
            auxf = ff->ini;

            while (i != auxf->id){ // achar o nó do menor tt
                auxf = auxf->prox;
            }

            tp = auxf->tempo * auxc->item;
            tt[i] = tp + tt[i];
            removerc(fc);
        }
        for (i=0; i < f;i++){  // achar o tempo total
            if (tt[i] > tempot){
                tempot = tt[i];
            }
        }
        }
        printf ("%d\n", tempot);
        }

        int main (){
            filaf ff;
            filac fc;
            criarf(&ff);
            criarc(&fc);

            int t,x,i = 0,y,f,c;
                
            scanf ("%d", &f);
            scanf ("%d", &c);
            for (x=0;x < f; x++){
                scanf ("%d", &t);
                inserirf(&ff,t,i);
                i++;
            }
            for (y=0;y < c; y++){
                scanf ("%d", &i);
                inserirc(&fc,i);
            }
            atender(&ff,&fc,f,c);
            }


            