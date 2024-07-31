import java.util.LinkedList;

public class Game {
    private LinkedList<Player> players = new LinkedList<>();
    private LinkedList<Card> pile = new LinkedList<>();
    private Dealer dealer;
    private String[] patterns = { "doubles", "top bottom", "sandwich" };
    private int currentPlayerIndex = 0;
    public Card TOP;

    public LinkedList<Player> getPlayers() {
        return players;
    }

    public LinkedList<Card> getPile() {
        return pile;
    }

    public Dealer getDealer() {
        return dealer;
    }

    public String[] getPatterns() {
        return patterns;
    }

    public int getCurrentPlayerIndex() {
        return currentPlayerIndex;
    }

    public boolean getSandwich() {
        return sandwich();
    }

    public boolean getTopBottom() {
        return topBottom();
    }

    public boolean getDoubles() {
        return doubles();
    }

    public void setPatterns(String[] patterns) {
        this.patterns = patterns;
    }

    public void setPlayers(LinkedList<Player> players) {
        this.players = players;
    }

    public Game() {
        this(2);
    }

    public Game(LinkedList<Player> players) {
        this.players = players;
    }

    public Game(int numPlayers) {
        for (int i = 1; i <= numPlayers; i++) {
            players.add(new Player());
        }

        dealer = new Dealer();
        dealer.initializeDeck();
        currentPlayerIndex = 0;
    }

    public int play() {
        while (players.size() > 1) {
            dealCardsToPlayers();

            while (!players.get(currentPlayerIndex).getHand().isEmpty()) {
                Card playedCard = players.get(currentPlayerIndex).playCard();
                if (playedCard != null) {
                    pile.add(playedCard);
                    System.out.println("Player " + players.get(currentPlayerIndex).getPlayerNum() +
                            " played card: " + playedCard);
                }

                handlePatterns();
                if (players.size() == 1) {
                    break;
                }
                nextPlayer();
            }

            if (!pile.isEmpty() && players.size() > 1) {
                Player winner = players.get(currentPlayerIndex);
                players.get(currentPlayerIndex).getHand().addAll(pile);
                pile.clear();
                System.out.println("Player " + winner.getPlayerNum() + " won the pile!");
            }

            if (players.size() > 1) {
                players.removeIf(player -> player.getHand().isEmpty());
            }
        }

        return players.get(0).getPlayerNum();
    }

    private void dealCardsToPlayers() {
        int numCardsToDeal = dealer.getSize() / players.size();
        // used chat gpt for help with this
        for (Player player : players) {
            // end used chat gpt for help
            player.getHand().addAll(dealer.deals(numCardsToDeal));
        }

        TOP = pile.isEmpty() ? null : pile.getLast();
    }

    private void handlePatterns() {
        if (isFaceCard(pile.getLast())) {
            int chances = getChancesForFaceCard(pile.getLast());

            while (chances > 0 && !pile.isEmpty() && isFaceCard(pile.getLast())) {
                Card additionalCard = players.get(currentPlayerIndex).playCard();
                if (additionalCard != null) {
                    pile.add(additionalCard);
                    System.out.println("Player " + players.get(currentPlayerIndex).getPlayerNum() +
                            " played card: " + additionalCard);
                    // used chat gpt for help here
                    chances--;
                    //end used chat gpt for help here
                }
            }

            if (chances == 0) {
                Player winner = players.get(currentPlayerIndex);
                nextPlayer();
                System.out.println("Player " + winner.getPlayerNum() + " won by face card!");
            }
        } else {
            if (topBottom() || doubles() || sandwich()) {
                Player winner = players.get(currentPlayerIndex);
                nextPlayer();
                System.out.println("Player " + winner.getPlayerNum() + " won by slapping!");
            }
        }
    }

    private boolean isFaceCard(Card card) {
        return card.getRank() == 11 || card.getRank() == 12 || card.getRank() == 13 || card.getRank() == 14;
    }

    private int getChancesForFaceCard(Card faceCard) {
        switch (faceCard.getRank()) {
            case 11:
                return 1;
            case 12:
                return 2;
            case 13:
                return 3;
            case 14:
                return 4;
            default:
                return 0;
        }
    }

    private boolean topBottom() {
        return pile.size() >= 2 && pile.getLast().equals(pile.getFirst());
    }

    private boolean doubles() {
        return pile.size() >= 2 && pile.getLast().equals(pile.get(pile.size() - 2));
    }

    private boolean sandwich() {
        return pile.size() >= 3 && pile.getLast().equals(pile.get(pile.size() - 3));
    }

    private void nextPlayer() {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }
}
