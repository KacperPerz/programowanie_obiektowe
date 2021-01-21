package customer;

public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account(){}
    public Account(int n, Customer c, int p, String l) {
        this.accountNumber = n;
        this.owner = c;
        this.password = p;
        this.login = l;
    }
    public void login(String l, int passw) throws AccountLoginFailedException {
        this.login = l;
        this.password = passw;
    }
    public Customer getCustomer() {
        return this.owner;
    }
    public int getNumber() {
        return this.accountNumber;
    }
    public double getBalance() {
        return this.balance;
    }
    public double withdraw(double amount) {
        if(amount <= this.balance) {
            this.balance -= amount;
            return amount;
        }
        return 0;
    }
}
