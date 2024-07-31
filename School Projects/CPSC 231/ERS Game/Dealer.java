import java.util.LinkedList;
import java.util.Random;

public class Dealer {
    private LinkedList<Card> m_deck = new LinkedList<>();

    public void initializeDeck() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 2; j <= 14; ++j) {
                m_deck.add(new Card(j, i));
                
            }
        }
    }

    public LinkedList<Card> deals(int n) {
        if (m_deck.isEmpty()) {
            return new LinkedList<>();
        }
// had to consult chatGPT for this way to shuffle the deck
        Random r = new Random();
        for (int i = m_deck.size() - 1; i > 0; i--) {
            int j = r.nextInt(i + 1);
            Card temp = m_deck.get(i);
            m_deck.set(i, m_deck.get(j));
            m_deck.set(j, temp);
// end of code I got help from chatGPT on
        }

        LinkedList<Card> dealtCards = new LinkedList<>();
        // I got help from chatGPT on this part
        int cardsToDeal = Math.min(n, m_deck.size());
        // end of code I got help from chatGPT on
        for (int i = 0; i < cardsToDeal && !m_deck.isEmpty(); ++i) {
            dealtCards.add(m_deck.poll());
        }

        return dealtCards;
    }

    public int getSize() {
        return m_deck.size();
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < m_deck.size(); ++i) {
            s.append(m_deck.get(i)).append("\n");
        }
        return s.toString();
    }
}
