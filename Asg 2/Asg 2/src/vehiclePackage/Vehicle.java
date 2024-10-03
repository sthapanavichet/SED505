/**
 * The Vehicle class represents a vehicle that can be a Car, Boat, or Airplane.
 * It implements the VehicleFunction interface and provides methods to travel,
 * add fuel, and display vehicle information.
 * 
 * This class demonstrates aggregation/composition with Car, Boat, and Airplane
 * classes.
 * 
 * Attributes:
 * - car: An instance of the Car class, initialized if the vehicle type is "Car".
 * - boat: An instance of the Boat class, initialized if the vehicle type is "Boat".
 * - airplane: An instance of the Airplane class, initialized if the vehicle type is "Airplane".
 * 
 * Constructor:
 * - Vehicle(String vehicleType): Initializes the Vehicle object based on the provided vehicle type.
 *   If the vehicle type is "Car", a Car object is created. If the vehicle type is "Boat", a Boat object is created.
 *   If the vehicle type is "Airplane", an Airplane object is created.
 * 
 * Methods:
 * - Travel(double distance): Implements the Travel method from the VehicleFunction interface.
 *   This method delegates the travel logic to the appropriate vehicle type (Car, Boat, or Airplane).
 *   For example, if the vehicle is a Car, it calls the carTravel method of the Car class.
 * 
 * - AddFuel(double fuel): Implements the AddFuel method from the VehicleFunction interface.
 *   This method delegates the add fuel logic to the appropriate vehicle type (Car, Boat, or Airplane).
 * 
 * - DisplayVehicle(): Displays the type of vehicle being used along with its travel distance, travel time,
 *   fuel level, and fuel cost. This method checks which vehicle type is initialized and prints the relevant
 *   information using the respective getter methods from the Car, Boat, or Airplane class.
 */

package vehiclePackage;
// Package declaration for the Vehicle class

public class Vehicle implements VehicleFunction {
    // Aggregation/Composition with Car, Boat, and Airplane
    private Car car = null;
    private Boat boat = null;
    private Airplane airplane = null;

    // Constructor to initialize all vehicle types
    public Vehicle(String vehicleType) {
        if (vehicleType.equals("Car")) {
            car = new Car();
        } else if (vehicleType.equals("Boat")) {
            boat = new Boat();
        } else if (vehicleType.equals("Airplane")) {
            airplane = new Airplane();
        }
    }

    // Implements Travel from VehicleFunction interface
    @Override
    public void Travel(double distance) {
        if (car != null) {
            car.carTravel(distance);
        } else if (boat != null) {
            boat.boatTravel(distance);
        } else if (airplane != null) {
            airplane.airplaneTravel(distance);
        }
    }
    // Implements AddFuel from VehicleFunction interface
    @Override
    public void AddFuel(double fuel) {
        if (car != null) {
            car.carAddFuel(fuel);
        } else if (boat != null) {
            boat.boatAddFuel(fuel);
        } else if (airplane != null) {
            airplane.airplaneAddFuel(fuel);
        }
    }

    // Display the type of vehicle being used and it's information
    public void DisplayVehicle() {
        if (car != null) {
            System.out.println("Vehicle Type: Car");
            System.out.printf("Travel Distance: %.3fkm\n", car.getCarDistance());
            System.out.printf("Travel Time: %.4f hours\n", car.getCarTime());
            System.out.printf("Fuel Level: %.4fL\n", car.getCarFuelLevel());
            System.out.printf("Fuel Cost: $%.2f\n\n", car.getCarFuelCost());
        } else if (boat != null) {
            System.out.println("Vehicle Type: Boat");
            System.out.printf("Travel Distance: %.3fkm\n", boat.getBoatDistance());
            System.out.printf("Travel Time: %.4f hours\n", boat.getBoatTime());
            System.out.printf("Fuel Level: %.4fL\n", boat.getBoatFuelLevel());
            System.out.printf("Fuel Cost: $%.2f\n\n", boat.getBoatFuelCost());
        } else if (airplane != null) {
            System.out.println("Vehicle Type: Airplane");
            System.out.printf("Travel Distance: %.3fkm\n", airplane.getAirplaneDistance());
            System.out.printf("Travel Time: %.4f hours\n", airplane.getAirplaneTime());
            System.out.printf("Fuel Level: %.4fL\n", airplane.getAirplaneFuelLevel());
            System.out.printf("Fuel Cost: $%.2f\n\n", airplane.getAirplaneFuelCost());
    }
}
}