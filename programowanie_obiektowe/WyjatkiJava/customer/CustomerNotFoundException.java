package customer;

public class CustomerNotFoundException extends Exception{
    private String imie;

    // Customer findByName(String name) {

    // } 
    CustomerNotFoundException(String warning) {
        System.out.println(warning);
    }
    
}
