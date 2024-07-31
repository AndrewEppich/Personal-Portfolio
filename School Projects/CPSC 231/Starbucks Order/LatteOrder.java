/**
 * The `LatteOrder` class represents an order of lattes.
 * It allows adding and calculating the total cost of multiple lattes in an
 * order.
 */

public class LatteOrder {
    private Latte[] m_order;
    private int m_numLattes;

    public LatteOrder() {
        m_numLattes = 1;
        m_order = new Latte[m_numLattes];
        m_order[0] = new Latte();
    }

    /**
     * Creates an instance of the `LatteOrder` with a specific number of lattes.
     *
     * @param numLattes The number of lattes to be included in the order.
     */
    public LatteOrder(int numLattes) {
        m_numLattes = numLattes;
        m_order = new Latte[m_numLattes];
        for (int i = 0; i < m_numLattes; i++) {
            m_order[i] = null;
        }
    }

    /**
     * Adds a latte to the order. If the order is full, it cannot add more lattes.
     *
     * @param latte The latte to be added to the order.
     * @return 1 if the latte was successfully added, -1 if the order is full and
     *         cannot add more.
     */
    public int addLatte(Latte latte) {
        for (int i = 0; i < m_numLattes; i++) {
            if (m_order[i] == null) {
                m_order[i] = latte;
                return 1;
            }
        }

        return -1;
    }

    /**
     * Calculates the total cost of the order by summing the costs of all lattes in
     * the order.
     *
     * @return The total cost of the order.
     */
    public double calcTotal() {
        double totalCost = 0.0;
        for (int i = 0; i < m_numLattes; i++) {
            if (m_order[i] != null) {
                totalCost += m_order[i].calcCost();
            }
        }
        return totalCost;
    }

    /**
     * Returns a string representation of the order, including the total cost and
     * details of each latte.
     *
     * @return A string representing the order with individual latte details and the
     *         total cost.
     */
    public String toString() {
        StringBuilder orderString = new StringBuilder(
                "Order: " + "\n" + 
                        "Total Cost: $" + calcTotal() + "\n");
        for (int i = 0; i < m_numLattes; i++) {
            if (m_order[i] != null) {
                orderString.append("Latte ").append(i).append(":\n");
                orderString.append(m_order[i].toString()).append("\n");
            }
        }
        return orderString.toString();
    }
}
/*
 * public static void main(String[] args) {
 * Latte outer = new Latte();
 * 
 * LatteOrder order = outer.new LatteOrder(3);
 * 
 * Latte latte1 = new Latte("tall", 2, "whole", 1, false);
 * Latte latte2 = new Latte("venti", 3, "oat", 3, true);
 * 
 * int addResult1 = order.addLatte(latte1);
 * int addResult2 = order.addLatte(latte2);
 * 
 * System.out.println("Add Result 1: " + (addResult1 == 1 ? "Successful" :
 * "Unsuccessful"));
 * System.out.println("Add Result 2: " + (addResult2 == 1 ? "Successful" :
 * "Unsuccessful"));
 * 
 * System.out.println(order.toString());
 * }
 * }
 * 
 * /*
 */
