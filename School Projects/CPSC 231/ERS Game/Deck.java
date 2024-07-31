import java.util.LinkedList;
import java.util.Random;
public class Deck {
    private LinkedList<Card> m_cards = new LinkedList <Card>();

    public Deck(){
        for (int i = 0; i <= Card.DIAMONDS; ++i){
            for (int j = 2; j <= Card.ACE; ++j){
                m_cards.add(new Card(i , j));
            }
        }
    }

    public Card getCard(int index){
        return m_cards.get(index);
    }

    public int getSize(){
        return m_cards.size();
    }

    public Deck(Deck d){
        for (int i = 0; i < d.getSize(); ++i){
            this.m_cards.add(new Card(d.getCard(i)));
        }
    }

    public String toString(){
        String s = "";
        for (int i = 0; i < this.getSize(); ++i){
            s += this.getCard(i).toString();
        }
        return s;
    }

    // Beginning of code I Got help from my friend on part of this
    public Card deal(){
        Random r = new Random();
        int index = r.nextInt(this.getSize());
        Card tempCard = new Card(m_cards.get(index));
        m_cards.remove(index);
        return tempCard;
    }
// end of code I got help from my friend on
    
}