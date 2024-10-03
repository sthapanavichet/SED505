/**
 * The TravelSimulation class demonstrates the usage of the Vehicle class.
 * It creates instances of different types of vehicles (Boat, Car, Airplane),
 * simulates their travel over specified distances, and displays their information.
 * Additionally, it adds fuel to each vehicle and simulates further travel.
 * 
 * The main steps include:
 * 1. Creating instances of Vehicle for Boat, Car, and Airplane.
 * 2. Simulating travel for each vehicle and displaying their information.
 * 3. Adding fuel to each vehicle.
 * 4. Simulating further travel for each vehicle and displaying their updated information.
 */
import vehiclePackage.*;

class TravelSimulation {
    public static void main(String[] args) {
        Vehicle boat = new Vehicle("Boat");
        Vehicle car = new Vehicle("Car");
        Vehicle airplane = new Vehicle("Airplane");
        // the boat travels 100km and information about the boat is printed
        
        boat.Travel(100.0);
        boat.DisplayVehicle();

        // the car travels 1000km and information about the car is printed
        car.Travel(1000.0);
        car.DisplayVehicle();

        // the airplane travels 10000km and information about the airplane is printed
        airplane.Travel(10000.0);
        airplane.DisplayVehicle();

        // Add fuel to each
        System.out.println();
        System.out.println("Adding fuel...");
        System.out.println();

        boat.AddFuel(120);
        car.AddFuel(40);
        airplane.AddFuel(50000);

        // Travel again
        // Boat
        boat.Travel(100.0);
        boat.DisplayVehicle();

        // Car
        car.Travel(1000.0);
        car.DisplayVehicle();

        // Airplane
        airplane.Travel(10000.0);
        airplane.DisplayVehicle();
    }
}