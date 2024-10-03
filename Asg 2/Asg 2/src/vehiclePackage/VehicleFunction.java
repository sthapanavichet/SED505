/**
 * The VehicleFunction interface provides methods for vehicle operations.
 * Implementing classes should define how a vehicle travels a certain distance
 * and how fuel is added to the vehicle.
 */
package vehiclePackage;

public interface VehicleFunction {
    void Travel(double distance);

    void AddFuel(double fuel);
}