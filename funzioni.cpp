#include "header.h"


// FUNZIONE: Conta le righe nel file "filename" e ne restituisce la lunghezza 
int count_line(const string& filename){
    ifstream infile(filename); //apre e legge il file filename e se va a buon fine continua, altimenti
    if(!infile.good())         //stampa un errore
        cout << "Error... Cannot open the file." << endl;
    
    int count = 0;     //dichiara le variabili count = lunghezza file,
    string str = "";   //str = strnga in cui inserisce la riga nel getline
    
    while(!infile.eof()){                //finchè non è finito il file, conta le righe e aggiunge 1 alla
        getline(infile, str);            //variabile count dichiarata prima
        count++;
    }

    infile.clear();    //pulisce, riporta a 0 e chiude 
    infile.seekg(0);   //il file filename aperto prima
    infile.close();
    
    return count;   //restituisce la lunghezza
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNZIONE: Carica nell'array "vec" di dimensione "lenght" i dati del file aperto nella variabile infile
void load_data(const string& filename, ...* vec, int length){ //i puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    ifstream infile(filename);   //apre e legge il file filename e se va a buon fine continua, altimenti
    if(!infile.good())           //stampa un errore
           cout << "Error... Cannot open the file." << endl;

    for(int i = 0; i < length; i++)    //carico vettore vec inserendo i dati del file infile 
        infile >> vec[i]. >> vec[i].;  //es. infile >> vec[i].x  infile >> vec[i].p[j].x  infile >> vec[i].p[2].x (prende il 3 elemento di p)

    infile.close(); //chiude il file letto
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNZIONE: stampa l'array vec e la sua lunghezza
void print_first(...* vec, int length){  // puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    for(int i = 0; i < length; i++){
        cout << "Inserire testo qui: " << vec[i]. << "\t" << vec[i]. << endl; //stampo il vettore e in "inserisci testo" mettere
    }                                                                         //la descrizione e es. cout << vec[i].x  cout << vec[i].p[j].x  cout << vec[i].p[2].x (prende il 3 elemento di p)
    cout << "Inserire testo qui: " << length << endl; //stampo la dimensione del vettore vec
    cout << endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNZIONE: inverte il primo elemento con il secondo elemento 
void swap(...& x, ...& y){ // puntini"..." inserire il nome del tipo di dato da scambiare (nomestruct se x è di tipo struct)
    ... tmp = x;  //tmp deve essere dello stesso tipo dei due elementi da scambiare 
    x = y; 
    y = tmp;
}

//FUNZIONE:riordina gli elementi del vettore in base a una condizione (in questo caso primo > secondo)
void sort(...* vec, int length){ //puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    for(int i = 0; i < length - 1; i++) {
        for(int j = i + 1; j < length; j++){
            if(vec[i]. > vec[j].) //es. if(vec[i].x> vec[j].x) oppure if(vec[i].p.x> vec[j].p.x)...
                swap(vec[i], vec[j]); //chiamo la funzione che inverte 
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNZIONE: permette di stampare il vettore ordinato dopo aver chiamato le due funzioni sort e swap
void print_sorted(...* vec, int length){ //puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    for(int i = 0; i < length; i++)
        cout << "Inserire testo qui: " << vec[i]. << "\t" << vec[i]. << endl; //cout << vec[i].x  cout << vec[i].y <<...
    cout << endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNZIONE: permette di trovare il più piccolo elemento di un array vec in funzione di una sua variabile
double find_min(...* vec, int length){ //puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    double min = vec[0].;  //double int min = vec[0].x (se sto valutando il minimo di x); dichiaro variabile min
    for(int i = 0; i < length; i++) 
        if(vec[i]. < min) //condizione per aggiornare min (es. vec[i].x < min)
            min = vec[i].; //assegno a min il vettore più piccolo trovato e lo restituisco (es. min = vec[i].x)
    return min;
}

//FUNZIONE: permette di trovare il più grande elemento di un array vec in funzione di una sua variabile
double find_max(...* vec, int length){ //puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    double max = vec[0].; //double int max = vec[0].x (se sto valutando il massimo di x); dichiaro variabile max
    for(int i = 0; i < length; i++)  
        if(vec[i]. > max) //condizione per aggiornare max (es. vec[i].x < max)
            max = vec[i].;//assegno a max il vettore più grande trovato e lo restituisco (es. max = vec[i].x)
    return max;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNZIONE: stampa il minimo e il massimo dell'array vec a video 
void print_third(...* vec, int length){ //puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    cout << "Inserire testo qui: " << find_min(vec,length) << "\tInserire testo qui: " << find_max(vec, length) << endl; 
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNZIONE: permette di creare un file in cui stampa quanto richiesto 
void print_file(const string& filename, ...* vec, int length){ //puntini "..." inserire tipo di array es. nomestruct * vec= new nomestruct [lenght]
    ofstream outfile(filename); //apre un file output chiamato filename
    if(!outfile.good())
        cout << "Error...Cannot open the file." << endl;

    outfile << "Inserire testo qui" << length << "\n" << endl; //stampa sul file aperto in outfile lenght

    for(int i = 0; i < length; i++)
        outfile << "Inserire testo qui: " << vec[i].x << "\tInserire testo qui: " << vec[i].y << endl;  //stampa sul file aperto in outfile le due coordinate del vettore
    cout << endl;

    outfile << "Inserire testo qui: " << find_min(vec, length) << "\n" << endl;  //stampa sul file aperto in outfile il return della funzione find_min
    outfile << "Inserire testo qui: " << find_max(vec, length) << "\n" << endl;  //stampa sul file aperto in outfile il return della funzione find_max
}
