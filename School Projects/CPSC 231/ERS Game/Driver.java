public class Driver {
    public static void main(String[] args) {
        int numPlayers = 4; 
        Game game = new Game(numPlayers);

        System.out.println("Game started with " + numPlayers + " players.");

        int winner = game.play();

        System.out.println("Player " + winner + " is the winner!");
        

        for (Player player : game.getPlayers()) {

            System.out.println("Player " + player.getPlayerNum() + " hand: " + player.getHand());
        }
    }
}