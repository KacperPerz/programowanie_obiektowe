package recycling;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Wezel {

    ArrayList<Wezel> polaczenia = new ArrayList<>();
    HashMap<Wezel,Boolean> poleczeniaHM= new HashMap<>();
    TreeMap<Wezel,Boolean> poleczeniaTM= new TreeMap<>();
    
    public void dodaj_do_HM(Wezel e){
        this.poleczeniaHM.put(e,true);
    }
    public void dodaj_do_TM(Wezel e){
        this.poleczeniaTM.put(e,true);
    }

    public void dodajPoleczenie(Wezel e) {
        this.polaczenia.add(e);
    }
    public void getPolaczenia() {
        polaczenia.size();
    }
    @Deprecated
    @Override
    protected void finalize() throws Throwable{
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        for(int i=0 ; i<10000000 ; i++) {
            Wezel w1 = new Wezel () ;
            Wezel w2 = new Wezel () ;
            w1.dodajPoleczenie(w2);
            w2.dodajPoleczenie(w1);
            w1.polaczenia.size();
        }
        //s.nextLine();
        s.close();
    }
    //Na konsoli nie wyswietlil sie napis "finalizowanie obiektu"
    //dla 10^6 iteracji wyrzuca "finalizowanie obiektu", prawdopodobnie jest tyle finalizacji ile nadwyżki obiektów - może kończy się pamięć?

}