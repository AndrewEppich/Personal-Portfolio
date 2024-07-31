import java.util.LinkedList;
public class Player {
    private int playerNum;
    private LinkedList <Card> hand = new LinkedList <Card>(); 
    private String pattern;
    public Card TOP;
    public Card BOTTOM;
    private Game game;

    public Player() {
        playerNum = 1;
        pattern = "sandwich";
        TOP = null;
        BOTTOM = null;
    }
    

    public Player(int playerNum, LinkedList<Card> hand, String pattern) {
        this.playerNum = playerNum;
        this.hand = hand;
        this.pattern = pattern;
        TOP = hand.isEmpty() ? null : hand.getFirst();
        BOTTOM = hand.isEmpty() ? null : hand.getLast();
    }

    private void setBottom() {
        BOTTOM = hand.isEmpty() ? null : hand.getLast();
    }

    public Card getBOTTOM() {
        setBottom();
        return BOTTOM;
    }

    private void setTop() {
        TOP = hand.isEmpty() ? null : hand.getFirst();
    }

    public Card getTOP() {
        setTop();
        return TOP;
    }

public int getPlayerNum(){
    return playerNum;
}
public LinkedList<Card> getHand(){
    return hand;
}
public String getPattern(){
    return pattern;
}
public void setHand(LinkedList<Card> hand){
    this.hand = hand;
}


public Card playCard() {
    if (!hand.isEmpty()) {
        Card playedCard = hand.getFirst();
        hand.removeFirst();
        return playedCard;
    } else {
        return null;
    }
}




public boolean slaps() {

    switch (pattern) {
        case "top bottom":
            return game.getTopBottom();
        case "doubles":
            return game.getDoubles();
        case "sandwich":
            return game.getSandwich();
        default:
            return false;
    }
}


public String toString() {
    String s = "";
    s += "Player Number: " + playerNum + "\n"
            + "Pattern: " + pattern + "\n"
            + "Hand: " + hand + "\n";
    return s;
}




}
