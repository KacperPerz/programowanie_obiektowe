package customer;

public class Customer {
    private String name;
    private String pesel;
    private int rokUrodzenia;

    public Customer(){}
    public Customer(String s, String pesel, int rokUrodzenia) {
        this.name = s;
        this.pesel = pesel;
        this.rokUrodzenia = rokUrodzenia;
    }
    public String getName() {
        return this.name;
    }
    public String getPesel() {
        return this.pesel;
    }

    @Override //equals jest funkcja zbudowana, wiec jezeli chcemy ja spersonalizowac, warto dodac naglowek override
    public boolean equals(Object c){
        if(!(c instanceof Customer)){
            return false;
        }
        Customer o=(Customer) c;
        return this.name.equals(o.name);
    }
     
}