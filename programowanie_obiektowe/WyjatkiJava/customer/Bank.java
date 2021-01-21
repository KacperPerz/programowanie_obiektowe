package customer;

import java.util.ArrayList;


//dzieki interfejsom zyskujemy wielokrotne dziedziczenie i wygodny szablon wielu klas
interface SearchCustomers{
    Customer findByName(String name) throws CustomerNotFoundException;
}

interface SearchAccounts{
    Account findByNumber(int number) throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException;
}  

public class Bank implements SearchAccounts, SearchCustomers{
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts= new ArrayList<Account>();

    @Override
    public Customer findByName(String name) throws CustomerNotFoundException{
            for (Customer customer : customers) {
                if(customer.getName().equals(name))
                    return customer;
            }
            throw new CustomerNotFoundException("Nie znaleziono osobnika");
    }
    @Override
    public Account findByNumber(int num) throws AccountNotFoundException{
            for(Account account : accounts) {
                if(account.getNumber() == num)
                    return account;
            }
            throw new AccountNotFoundException("Nie znaleziono konta");
        }
    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException{
        ArrayList<Account> lista = new ArrayList<Account>();
        for (Account account : accounts) {
            if(account.getCustomer().equals(cust))
                lista.add(account);
        }
        if(lista.size() != 0)
            return lista;
        throw new AccountNotFoundException("Nie znaleziono kont tego uzytkownika.");
    }

    public void addCustomer(Customer c) {
        customers.add(c);
    }
    public void addAccount(Customer c, int accountNumber, int pass, String l) {
        Account a = new Account(accountNumber,c,pass,l);
        accounts.add(a);
    }

    
}