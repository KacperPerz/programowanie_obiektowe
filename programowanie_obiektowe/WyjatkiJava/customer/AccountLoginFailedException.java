package customer;

import java.util.ArrayList;

public class AccountLoginFailedException extends Exception {
    static final long serialVersionUID = 1L;
    private int password;
    private String login;
    private int accountNumber;
    private Customer owner;
    private double balance;

    AccountLoginFailedException(){}
    AccountLoginFailedException(String errorMsg, String s, int passw) {
        super(errorMsg);
        login = s;
        password = passw;
    }
    int getPassword() {
        return this.password;
    }

}
