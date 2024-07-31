import java.util.LinkedList;
public class testCards {
    public static void main(String[] args) {

        Dealer dealer = new Dealer();

        dealer.initializeDeck();

        System.out.println("Initial deck:\n" + dealer);

        LinkedList<Card> dealtCards = dealer.deals(5);

        System.out.println("Dealt cards:\n" + dealtCards);

        System.out.println("Deck after dealing 5 cards:\n" + dealer);

        System.out.println("Deck size: " + dealer.getSize());
    }
}
