package customer;

public class Main {

    public static void main(String args[]) {
        Bank bank = new Bank();
        Customer c1 = new Customer("Anna", "10000000", 1994);
        Customer c2 = new Customer("Jan", "01111111", 1997);

        bank.addCustomer(c1);
        bank.addAccount(c1, 1, 1234, "log");

        bank.addCustomer(c2);
        bank.addAccount(c2, 2, 4321, "gol");
        bank.addAccount(c2, 3, 4321, "gol2");
        try{
            bank.findByNumber(4);
        } catch(AccountNotFoundException e) {
            e.printStackTrace();
        }

        try{
            System.out.println("Istniejacy uzytkownik: " + bank.findAllCustomerAccounts(c2).size());
        }catch(AccountNotFoundException e) {}
        try{
            System.out.println("Nieistniejacy uzytkownik: " + bank.findAllCustomerAccounts(new Customer()).size());
        }catch(AccountNotFoundException e) {}

        try{
            System.out.println(bank.findByName("Jan").getPesel());
        } catch(CustomerNotFoundException e) {}
        try{
            System.out.println(bank.findByName("Joanna").getPesel());
        } catch(CustomerNotFoundException e) {
            e.fillInStackTrace();
        }
    }
}
