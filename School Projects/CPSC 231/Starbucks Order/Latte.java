 /**
 * The `Latte` class represents a customizable latte beverage with various options
 * such as size, pumpkin sauce pumps, milk type, espresso shots, and whipped cream.
 */

public class Latte {
    private String size;
    private int pumpkinSaucePumps;
    private String milkType;
    private int espressoShots;
    private boolean whippedCream;

    /**
     * Creates a new `Latte` instance with default values.
     */
    public Latte() {
        size = "grande";
        pumpkinSaucePumps = 4;
        milkType = "2%";
        espressoShots = 2;
        whippedCream = true;
    }

    /**
     * Creates a new `Latte` instance with specified parameters.
     *
     * @param size           The size of the latte (tall, grande, venti).
     * @param pumpkinSaucePumps The number of pumpkin sauce pumps.
     * @param milkType       The type of milk (2%, whole, oat, almond).
     * @param espressoShots  The number of espresso shots.
     * @param whippedCream   Whether it should contain whipped cream (true or false).
     */
    public Latte(String size, int pumpkinSaucePumps, String milkType, int espressoShots, boolean whippedCream) {
        this.size = size;
        this.pumpkinSaucePumps = pumpkinSaucePumps;
        this.milkType = milkType;
        this.espressoShots = espressoShots;
        this.whippedCream = whippedCream;
    }


    public Latte(Latte other) {
        this.size = other.size;
        this.pumpkinSaucePumps = other.pumpkinSaucePumps;
        this.milkType = other.milkType;
        this.espressoShots = other.espressoShots;
        this.whippedCream = other.whippedCream;
    }

    /**
     * Creates a new `Latte` instance as a deep copy of another `Latte` object.
     *
     * @param other The `Latte` object to copy.
     */
    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public int getPumpkinSaucePumps() {
        return pumpkinSaucePumps;
    }

    public void setPumpkinSaucePumps(int pumpkinSaucePumps) {
        this.pumpkinSaucePumps = pumpkinSaucePumps;
    }

    public String getMilkType() {
        return milkType;
    }

    public void setMilkType(String milkType) {
        this.milkType = milkType;
    }

    public int getEspressoShots() {
        return espressoShots;
    }

    public void setEspressoShots(int espressoShots) {
        this.espressoShots = espressoShots;
    }

    public boolean hasWhippedCream() {
        return whippedCream;
    }

    public void setWhippedCream(boolean whippedCream) {
        this.whippedCream = whippedCream;
    }

/**
     * Calculates the cost of the latte based on its attributes.
     *
     * @return The cost of the latte.
     */
    public double calcCost() {
        double cost = 0.0;
        switch (size) {
            case "tall":
                cost += 2.00;
                break;
            case "grande":
                cost += 2.50;
                break;
            case "venti":
                cost += 3.00;
                break;
        }
        cost += 0.25 * pumpkinSaucePumps;
        cost += 1.00 * espressoShots;
        cost += milkType.equals("oat") || milkType.equals("almond") ? 0.75 : 0.00;
        cost += whippedCream ? 0.50 : 0.00;
        return cost;
    }

  /**
     * Returns a string representation of the latte, including its attributes and cost.
     *
     * @return A string representation of the latte.
     */
    public String toString() {
        return  "       Cost: $" + calcCost() +  "\n" +
                "       Size: " + size + "\n" +
                "       Pumpkin Sauce Pumps: " + pumpkinSaucePumps + "\n" +
                "       Milk Type: " + milkType + "\n" +
                "       Espresso Shots: " + espressoShots + "\n" +
                "       Whipped Cream: " + (whippedCream ? "Yes" : "No") + "\n";
                
    }

 /**
     * Checks if two `Latte` objects are equal by comparing their attributes.
     *
     * @param other The `Latte` object to compare to.
     * @return true if the two lattes are equal, false otherwise.
     */
    public boolean equals(Latte other) {
        return size.equals(other.size) && pumpkinSaucePumps == other.pumpkinSaucePumps &&
                milkType.equals(other.milkType) && espressoShots == other.espressoShots &&
                whippedCream == other.whippedCream;
    }

   /*  public static void main(String[] args) {
        Latte defaultLatte = new Latte();
        System.out.println("Default Latte:");
        System.out.println(defaultLatte.toString());

        Latte customLatte = new Latte("tall", 2, "whole", 1, false);
        System.out.println("\nCustom Latte:");
        System.out.println(customLatte.toString());
    }
/* */

}
