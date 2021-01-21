package customer;

public class AccountNotFoundException extends Exception {

    AccountNotFoundException(String warning) {
        System.out.println(warning);
    }
}
