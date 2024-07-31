public class Card { 
    private int m_rank;
    private int m_suit;
    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;
    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;

public Card(){
    m_rank = ACE;
    m_suit = SPADES;

}

public Card(int rank, int suit) {
    this.m_rank = rank;
    this.m_suit = suit;
}

//copy construcor
public Card(Card other){
    this.m_rank = other.m_rank;
    this.m_suit = other.m_suit;
}

public int getRank(){
    return m_rank;
}

public int getSuit(){
    return m_suit;
}

public void setRank(int rank) {
    if (rank >= 2 && rank <= 14) {
        this.m_rank = rank;
    } else {
        System.out.println("Invalid rank. Rank should be between 2 and 14.");

    }
}

public void setSuit(int suit) {
    if (suit >= 0 && suit <= 3) {
        this.m_suit = suit;
    } else {
        System.out.println("Invalid suit. Suit should be between 0 and 3.");

    }
}
public String toString() {
    return "Rank: " + getRankAsString() + "\n"
         + "Suit: " + getSuitAsString() + "\n";
}

private String getRankAsString() {
    switch (m_rank) {
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        case 14:
            return "Ace";
        default:
            return Integer.toString(m_rank);
    }
}
private String getSuitAsString(){
    switch(m_suit) {
        case 0:
        return "Hearts";
        case 1:
        return "Spades";
        case 2:
        return "Clubs";
        case 3:
        return "Diamonds";
        default:
        return Integer.toString(m_suit);
    }


}

// got help on this from my friend
public boolean equals(Object other){
    if (!(other instanceof Card)){
        return false;
    }else{
        Card newCard = (Card) other;
        return this.m_rank == newCard.m_rank;
    }
// end of code I got help on from my friend
}


}
